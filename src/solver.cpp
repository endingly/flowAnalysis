#include "solver.hpp"
#include "common_define.hpp"

using namespace flowAnalysis;

solver::solver()
{
    f = std::make_unique<fluid>();
}

solver::~solver()
{
}

void solver::init_MigrationAndDiffusion()
{
    // 约化电场
    Matrix EBPx = f->Ex.cwiseAbs() / FLOW_ANALYSIS_INIT_MIDPARTICLE_DENSITY * 1E17;

    f->pm.ion["O-"].ux       = f->pm.molecule["O2-"].ux;
    f->pm.molecule["O2"].ux  = Matrix::Constant(1.4 * 760 * 300 / (273 * FLOW_ANALYSIS_PRESSURE));
    f->pm.molecule["O2-"].ux = Matrix::Constant(2.0 * 760 * 300 / (273 * FLOW_ANALYSIS_PRESSURE));

    // Matrix EBPx_tmp = (1.27709 + 4.20304 * 1.0E-4 * EBPx + 9.31504 * 1.0E-6 * EBPx ^ 2) * 760 *
    //                   300 / (273 * FLOW_ANALYSIS_PRESSURE);
    // (EBPx.array() > 25).select(1.29 * 760 * 300 / (273 * FLOW_ANALYSIS_PRESSURE),
    // EBPx_tmp.array());
}