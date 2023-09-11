#include "fluid.hpp"
#include "common_define.hpp"
#include "particle_manager.hpp"
#include <filesystem>
#include <fstream>
#include <memory>

namespace fs = std::filesystem;

flowAnalysis::fluid::fluid()
{

    gama_O2                = 0.02;
    gama_CO2               = 0.02;
    SecEnergy              = 0.5;
    MidParticleDensity     = init_midparticle_density;
    MidParticleDensity_CO2 = init_midparticle_density * f_CO_2;

    E   = Matrix::Zero(imax, jmax);
    Ex  = Matrix::Zero(imax, jmax);
    Ey  = Matrix::Zero(imax, jmax);
    Jex = Matrix::Zero(imax, jmax);
    Jey = Matrix::Zero(imax, jmax);
    uex = Matrix::Zero(imax, jmax);
    uey = Matrix::Zero(imax, jmax);
    Dex = Matrix::Zero(imax, jmax);
    Dey = Matrix::Zero(imax, jmax);

    /*
     *  ----------------------------- <---- 外电路电压施压区
     * |                             |
     * |                             |
     * |                             |
     * |                             |
     * |                             |
     * |                             |
     * |                             |
     * |                             |
     *  ----------------------------- <---- 外电路电压施压区
     */
    phi               = Matrix::Zero(imax, jmax);
    auto r            = RVector::Ones(jmax).transpose() * voltage;
    phi.topRows(1)    = r;
    phi.bottomRows(1) = r;

    Kte  = Matrix::Zero(imax, jmax);
    Ener = Matrix::Zero(imax, jmax);
    Zex  = Matrix::Zero(imax, jmax);
    Zey  = Matrix::Zero(imax, jmax);

    fs::path       p = fs::current_path() / "particle.json";
    std::ifstream  f(p.string().c_str());
    nlohmann::json j;
    f >> j;
    pm = *(new flowAnalysis::particle_manager());
    pm = j;
    f.close();
}

flowAnalysis::fluid::~fluid() = default;