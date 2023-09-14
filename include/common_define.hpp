#pragma once
#include <Eigen/Core>
#include "config.hpp"

namespace flowAnalysis
{

using Matrix  = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;
using Array   = Eigen::ArrayWrapper<Matrix>;
using RVector = Eigen::Vector<double, jmax>;
using CVector = Eigen::Vector<double, imax>;

enum particelType
{
    electron,
    ion,
    atom,
    molecule
};

} // namespace flowAnalysis
