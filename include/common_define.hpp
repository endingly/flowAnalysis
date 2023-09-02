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
#define FLOW_ANALYSIS_I2 7
#define FLOW_ANALYSIS_I3 67
#define FLOW_ANALYSIS_F_He 0
#define FLOW_ANALYSIS_F_CO_2 1

using Matrix = Eigen::Matrix<double, FLOW_ANALYSIS_IMAX, FLOW_ANALYSIS_JMAX, Eigen::ColMajor>;
