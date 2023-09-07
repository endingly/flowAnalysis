#pragma once
#include <Eigen/Core>

// cm
#define FLOW_ANALYSIS_XMAX 0.24
#define FLOW_ANALYSIS_YMAX 0.2
// cell
#define FLOW_ANALYSIS_IMAX 73
#define FLOW_ANALYSIS_JMAX 61
// torr
#define FLOW_ANALYSIS_PRESSURE 15
// V
#define FLOW_ANALYSIS_VOLTAGE 800
// s
#define FLOW_ANALYSIS_DT 1e-20
#define FLOW_ANALYSIS_GAMMA 0
// 等离子体的边界
#define FLOW_ANALYSIS_I2 7
#define FLOW_ANALYSIS_I3 67

#define FLOW_ANALYSIS_F_He 0
#define FLOW_ANALYSIS_F_CO_2 1

// 初始条件设定
#define FLOW_ANALYSIS_INIT_MIDPARTICLE_DENSITY                       \
    FLOW_ANALYSIS_PRESSURE * 133.3 * 1e-6 / (1.38 * 1e-23 * 300)



namespace flowAnalysis
{

using Matrix  = Eigen::Matrix<double, FLOW_ANALYSIS_IMAX,
                             FLOW_ANALYSIS_JMAX, Eigen::ColMajor>;
using RVector = Eigen::Vector<double, FLOW_ANALYSIS_JMAX>;
using CVector = Eigen::Vector<double, FLOW_ANALYSIS_IMAX>;

} // namespace flowAnalysis