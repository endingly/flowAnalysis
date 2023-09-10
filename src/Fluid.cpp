#include "fluid.hpp"
#include "common_define.hpp"
#include <filesystem>

namespace fs = std::filesystem;

flowAnalysis::fluid::fluid()
{

    gama_O2                = 0.02;
    gama_CO2               = 0.02;
    SecEnergy              = 0.5;
    MidParticleDensity     = FLOW_ANALYSIS_INIT_MIDPARTICLE_DENSITY;
    MidParticleDensity_CO2 = FLOW_ANALYSIS_INIT_MIDPARTICLE_DENSITY * FLOW_ANALYSIS_F_CO_2;

    E   = Matrix::Zero();
    Ex  = Matrix::Zero();
    Ey  = Matrix::Zero();
    Jex = Matrix::Zero();
    Jey = Matrix::Zero();
    uex = Matrix::Zero();
    uey = Matrix::Zero();
    Dex = Matrix::Zero();
    Dey = Matrix::Zero();

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
    phi               = Matrix::Zero();
    auto r            = RVector::Ones().transpose() * FLOW_ANALYSIS_VOLTAGE;
    phi.topRows(1)    = r;
    phi.bottomRows(1) = r;

    Kte  = Matrix::Zero();
    Ener = Matrix::Zero();
    Zex  = Matrix::Zero();
    Zey  = Matrix::Zero();

    // fs::path       p = fs::current_path() / "particle.json";
    // std::ifstream  f(p.string().c_str());
    // nlohmann::json j;
    // f >> j;

    // f.close();
}

flowAnalysis::fluid::~fluid() = default;