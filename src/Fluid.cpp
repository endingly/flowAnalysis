#include "fluid.hpp"
#include "common_define.hpp"

flowAnalysis::fluid::fluid()
{
    gama_O2                = 0.02;
    gama_CO2               = 0.02;
    SecEnergy              = 0.5;
    MidParticleDensity     = FLOW_ANALYSIS_PRESSURE * 133.3 * 1e-6 / (1.38 * 1e-23 * 300);
    MidParticleDensity_CO2 = MidParticleDensity * FLOW_ANALYSIS_F_CO_2;

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
}

flowAnalysis::fluid::~fluid() = default;