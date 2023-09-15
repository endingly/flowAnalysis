#pragma once
#include "fluid.hpp"
#include "particle.hpp"
#include <string>

namespace flowAnalysis
{

class solver
{
  private:
    static constexpr double Qe      = 1.6E-19;            // 单位电荷量
    static constexpr double epsilon = 8.84E-14 * 1.00056; // 介电常数
    double                  dx, dy;                       // 空间步长

    // 对应于流体的五点系数，多的一个不知道是什么，由于不属于流体自带的物理量，所以放在这里
    Matrix AW, AN, AC, AE, AS, AR;

    std::unique_ptr<fluid> f;

  public:
    solver();
    ~solver();

    /// @brief 初始化迁移与扩散矩阵
    void init_MigrationAndDiffusion();

    /// @brief 利用半隐式方法求解泊松方程
    void solve_poisson_equation();

  private:
    /// @brief 初始化电子的迁移系数，在 init_MigrationAndDiffusion 中调用
    void init_uex();
    /// @brief 初始化电子的扩散系数，在 init_MigrationAndDiffusion 中调用
    void init_Dex();
    /// @brief 初始化各粒子的迁移系数与扩散系数，在 init_MigrationAndDiffusion 中调用
    void init_particle_u_D();
    /// @brief 初始化用于计算粒子流密度间接矩阵，在 init_MigrationAndDiffusion 中调用
    void init_Zx();
    /// @brief 初始化每种粒子的三种系数，在 solve_poisson_equation 中调用
    void init_GHL_matrix();
    /// @brief 初始化 AW, AN, AC, AE, AS, AR 矩阵，在 solve_poisson_equation 中调用
    void init_AWENCSR_matrix();

  public:
    static Matrix H1(const Matrix& Z);
    static Matrix G1(const Matrix& Z);

  private:
    /// @brief 求解 AW, AN, AC, AE, AS, AR 矩阵中的一项，子函数
    auto make_AWENCSR_matrix_subfunction(const std::string& particel_name);
};

} // namespace flowAnalysis
