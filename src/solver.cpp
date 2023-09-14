#include "solver.hpp"
#include "common_define.hpp"
#include "eigen_matrix_extension.hpp"
#include "particle.hpp"
#include <memory>
#include <utility>

using namespace flowAnalysis;

auto operator^(Array& m, int n)
{
    return m.pow(n);
}

solver::solver()
{
    dx = double(imax) / (double(imax) - 1);
    dy = double(jmax) / (double(jmax) - 1);

    AW = Matrix::Zero(imax, jmax);
    AN = Matrix::Zero(imax, jmax);
    AC = Matrix::Zero(imax, jmax);
    AE = Matrix::Zero(imax, jmax);
    AS = Matrix::Zero(imax, jmax);
    AR = Matrix::Zero(imax, jmax);

    f = std::make_unique<fluid>();

    init_MigrationAndDiffusion();
}

solver::~solver() = default;

void solver::init_MigrationAndDiffusion()
{
    init_particle_u_D();
    init_uex();
    init_Dex();
    init_Zx();
}

void solver::solve_poisson_equation()
{
    // # Math: \Delta \Phi=-\frac{\rho}{\epsilon_{0}}

    // 对于每种粒子的 Z 而言都需要分段讨论
    init_GHL_matrix();
}

void solver::init_uex()
{
    auto Kte = f->Kte.array();
    auto uex = f->uex.array();

    uex = (Kte < 0.04868).select(1.839E22 / init_midparticle_density, uex);
    uex = (Kte >= 0.04868 && Kte < 0.6217)
              .select((1.27948E22 + 1.06616E23 * Kte - 8.706E22 * (Kte ^ 2)) /
                          init_midparticle_density,
                      uex);
    uex = (Kte >= 0.6217 && Kte < 0.7368).select(4.54284E22 / init_midparticle_density, uex);
    uex = (Kte >= 0.7368 && Kte < 85.56)
              .select((6.21706E22 - 4.84082E22 * (1 - Eigen::exp(-Kte / 1.78886)) -
                       1.06655E22 * (1 - Eigen::exp(-Kte / 9.31518))) /
                          init_midparticle_density,
                      uex);
    uex = (Kte >= 85.56 && Kte < 200.0)
              .select((1.64251E18 * Kte + 2.9575E21) / init_midparticle_density, uex);
}

void solver::init_Dex()
{
    auto Kte = f->Kte.array();
    auto Dex = f->Dex.array();

    Dex = (Kte < 0.1).select(1.00515 * 1.0E22 / init_midparticle_density, Dex);
    Dex = (Kte >= 0.1 && Kte < 1.159)
              .select((exp(52.25793 - 1.12899 / (Kte + 0.20674))) / init_midparticle_density, Dex);
    Dex = (Kte >= 1.159 && Kte < 28.3)
              .select((-3.72599 * 1.0E22 * exp(-Kte / 3.99714) -
                       5.68012 * 1.0E22 * exp(-Kte / 36.35961) + 1.02742 * 1.0E23) /
                          init_midparticle_density,
                      Dex);
    Dex = (Kte >= 28.3 && Kte < 31.7)
              .select((5.36739 * 1.0E22 + 8.11836 * 1.0E20 * Kte) / init_midparticle_density, Dex);
    Dex = (Kte >= 31.7 && Kte < 200.0)
              .select((2.95262 * 1.0E23 + (4.28465 * 1.0E22 - 2.95262 * 1.0E23) /
                                              (1.0 + exp((Kte - 94.82187) / 35.28612))) /
                          init_midparticle_density,
                      Dex);
}

void solver::init_particle_u_D()
{
    auto atom     = f->pm.atom;
    auto ion      = f->pm.ion;
    auto molecule = f->pm.molecule;

    // 约化电场
    auto EBPx = (f->Ex.cwiseAbs() / init_midparticle_density * 1E17).array();
    auto EBPy = (f->Ey.cwiseAbs() / init_midparticle_density * 1E17).array();

    // x 方向
    // 各粒子的迁移系数
    ion["O-"].ux       = f->pm.molecule["O2-"].ux;
    molecule["O2"].ux  = Matrix::Constant(1.4 * 760 * 300 / (273 * pressure), imax, jmax);
    molecule["O2-"].ux = Matrix::Constant(2.0 * 760 * 300 / (273 * pressure), imax, jmax);

    auto EBPx_tmp = (1.27709 + 4.20304 * 1.0E-4 * EBPx + 9.31504 * 1.0E-6 * (EBPx.pow(2))) * 760 *
                    300 / (273 * pressure);
    molecule["CO3-"].ux = (EBPx > 25).select(1.29 * 760 * 300 / (273 * pressure), EBPx_tmp);
    molecule["CO2"].ux  = Matrix::Constant(1.113 * 760 * 300 / (273 * pressure), imax, jmax);

    // 各粒子扩散速度，根据迁移系数计算
    auto alpha = 300 * (1.38 * 1.0E-23) / (1.6 * 1.0E-19); // 扩散系数与迁移系数的转换关系
    ion["O-"].Dx        = ion["O-"].ux * alpha;
    molecule["O2"].Dx   = molecule["O2"].ux * alpha;
    molecule["O2-"].Dx  = molecule["O2-"].ux * alpha;
    molecule["CO3-"].Dx = molecule["CO3-"].ux * alpha;
    molecule["CO2"].Dx  = molecule["CO2"].ux * alpha;

    // y 方向
    ion["O-"].uy       = f->pm.molecule["O2-"].uy;
    molecule["O2"].uy  = Matrix::Constant(1.4 * 760 * 300 / (273 * pressure), imax, jmax);
    molecule["O2-"].uy = Matrix::Constant(2.0 * 760 * 300 / (273 * pressure), imax, jmax);

    auto EBPy_tmp = (1.27709 + 4.20304 * 1.0E-4 * EBPy + 9.31504 * 1.0E-6 * (EBPy.pow(2))) * 760 *
                    300 / (273 * pressure);
    molecule["CO3-"].uy = (EBPy > 25).select(1.29 * 760 * 300 / (273 * pressure), EBPy_tmp);
    molecule["CO2"].uy  = Matrix::Constant(1.113 * 760 * 300 / (273 * pressure), imax, jmax);

    // 各粒子扩散速度，根据迁移系数计算
    ion["O-"].Dy        = ion["O-"].uy * alpha;
    molecule["O2"].Dy   = molecule["O2"].uy * alpha;
    molecule["O2-"].Dy  = molecule["O2-"].uy * alpha;
    molecule["CO3-"].Dy = molecule["CO3-"].uy * alpha;
    molecule["CO2"].Dy  = molecule["CO2"].uy * alpha;
}

void solver::init_Zx()
{
    auto ion      = f->pm.ion;
    auto molecule = f->pm.molecule;
    auto atom     = f->pm.atom;

    auto ZxOfu   = ion["O-"].Zx.array();
    auto uxOfu   = ion["O-"].ux.array();
    auto DxOfu   = ion["O-"].Dx.array();
    auto ZxO2    = molecule["O2"].Zx.array();
    auto uxO2    = molecule["O2"].ux.array();
    auto DxO2    = molecule["O2"].Dx.array();
    auto ZxO2fu  = molecule["O2-"].Zx.array();
    auto uxO2fu  = molecule["O2-"].ux.array();
    auto DxO2fu  = molecule["O2-"].Dx.array();
    auto ZxCO3fu = molecule["CO3-"].Zx.array();
    auto uxCO3fu = molecule["CO3-"].ux.array();
    auto DxCO3fu = molecule["CO3-"].Dx.array();
    auto ZxCO2   = molecule["CO2"].Zx.array();
    auto uxCO2   = molecule["CO2"].ux.array();
    auto DxCO2   = molecule["CO2"].Dx.array();

    auto Zex = f->Zex.array();
    auto Dex = f->Dex.array();
    auto uex = f->uex.array();
    auto Ex  = f->Ex.array();

    Zex = -(uex / Dex) * Ex * dx;

    ZxOfu   = -uxOfu / DxOfu * Ex * dx;
    ZxO2    = uxO2 / DxO2 * Ex * dx;
    ZxO2fu  = -uxO2fu / DxO2fu * Ex * dx;
    ZxCO3fu = -uxCO3fu / DxCO3fu * Ex * dx;
    ZxCO2   = uxCO2 / DxCO2 * Ex * dx;
}

Matrix& solver::G1(const Matrix& Z)
{
    constexpr double z1     = -60.0;
    constexpr double z2     = 1.0e-5;
    constexpr double z3     = 60.0;
    Matrix           result = Matrix::Zero(imax, jmax);
    auto             r      = result.array();

    auto z = Z.array();

    r = (z < z1).select(-1, z);
    r = (z.abs() >= z1 && z.abs() < z2).select(-(z / 2.0 + (z.pow(2)) / 2.0) / (1 + 0.5 * z), z);
    r = (z.abs() >= z2 && z.abs() < z3)
            .select((z.exp() * (1 - z) - 1.0) / (z.exp() - 1.0).pow(2), z);

    return result;
}

Matrix& solver::H1(const Matrix& Z)
{
    constexpr double z1     = -60.0;
    constexpr double z2     = 1.0e-5;
    constexpr double z3     = 60.0;
    Matrix           result = Matrix::Zero(imax, jmax);
    auto             r      = result.array();

    auto z = Z.array();

    r = (z < z1).select(0, z);
    r = (z.abs() >= z1 && z.abs() < z2).select(z.exp() / (1 + z / 2).pow(2), z);
    r = (z.abs() >= z2 && z.abs() < z3).select((z.exp() * z.pow(2)) / (z.exp() - 1.0).pow(2), z);

    return result;
}

///[x]: 初始化系数矩阵待完成
void solver::init_GHL_matrix()
{
    // 电子
    f->G1ex = G1(f->Zex);
    f->G1ey = G1(f->Zey);
    f->G2ex = f->G1ex.array() + 1;
    f->G2ey = f->G1ey.array() + 1;
    f->H1ex = H1(f->Zex);
    f->H1ey = H1(f->Zey);
    f->LPex = f->Dex.array() * f->H1ex.array() * Get_space_step_x(f->Zex).array();
    f->LPey = f->Dey.array() * f->H1ey.array() * Get_space_step_y(f->Zey).array();

    // 离子
    for (auto& item : f->pm.ion)
    {
        auto i = item.second;
        i.G1x  = G1(i.Zx);
        i.G1y  = G1(i.Zy);
        i.G2x  = i.G1x.array() + 1;
        i.G2y  = i.G1y.array() + 1;
        i.H1x  = H1(i.Zx);
        i.H1y  = H1(i.Zy);
        i.LPx  = i.Dx.array() * i.H1x.array() * Get_space_step_x(i.Zx).array();
        i.LPy  = i.Dy.array() * i.H1y.array() * Get_space_step_y(i.Zy).array();
    }
    // 分子
    for (auto& item : f->pm.molecule)
    {
        auto i = item.second;
        i.G1x  = G1(i.Zx);
        i.G1y  = G1(i.Zy);
        i.G2x  = i.G1x.array() + 1;
        i.G2y  = i.G1y.array() + 1;
        i.H1x  = H1(i.Zx);
        i.H1y  = H1(i.Zy);
        i.LPx  = i.Dx.array() * i.H1x.array() * Get_space_step_x(i.Zx).array();
        i.LPy  = i.Dy.array() * i.H1y.array() * Get_space_step_y(i.Zy).array();
    }
}

///[ ]: 初始化系数矩阵待完成
void solver::init_AWENCSR_matrix()
{
    // 电子以及各粒子的 G1 G2 矩阵以及 u 共同组成了 AE 矩阵
    // clang-format off
    AE = epsilon * dy / dx - dy * dt / dx * Qe * make_AWENCSR_matrix_subfunction(ion, "O-")
                                               * make_AWENCSR_matrix_subfunction(molecule, "O2")
                                               * make_AWENCSR_matrix_subfunction(molecule, "O2-")
                                               * make_AWENCSR_matrix_subfunction(molecule, "CO3-")
                                               * make_AWENCSR_matrix_subfunction(molecule, "CO2")
                                               * make_AWENCSR_matrix_subfunction(electron, "e");
    // clang-format on
}

solver::Expr solver::make_AWENCSR_matrix_subfunction(flowAnalysis::particelType kind,
                                                     const std::string&   particel_name)
{
    if (kind == electron)
    {
        auto uex  = f->uex.array();
        auto G1ex = f->G1ex.array();
        auto G2ex = f->G2ex.array();
        auto ne   = f->ne.array();
        return uex * (G1ex * ne - G2ex * ne);
    }
    else if (kind == ion)
    {
        auto ion = f->pm.ion;
        auto u   = ion[particel_name].ux.array();
        auto G1  = ion[particel_name].G1x.array();
        auto G2  = ion[particel_name].G2x.array();
        auto n   = ion[particel_name].N.array();
        return u * (G1 * n - G2 * n);
    }
    else
    {
        auto molecule = f->pm.molecule;
        auto u        = molecule[particel_name].ux.array();
        auto G1       = molecule[particel_name].G1x.array();
        auto G2       = molecule[particel_name].G2x.array();
        auto n        = molecule[particel_name].N.array();
        return u * (G1 * n - G2 * n);
    }
}