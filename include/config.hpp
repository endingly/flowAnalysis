#pragma once

namespace flowAnalysis
{
    
constexpr float  xmax                     = 0.24;  // cm
constexpr float  ymax                     = 0.2;   // cm
constexpr int    imax                     = 73;    // cell
constexpr int    jmax                     = 61;    // cell
constexpr int    pressure                 = 15;    // torr
constexpr int    voltage                  = 800;   // V
constexpr double dt                       = 1e-20; // s
constexpr int    gama                     = 0;
constexpr int    i2                       = 7;
constexpr int    i3                       = 67;
constexpr float  f_He                     = 0;
constexpr float  f_CO_2                   = 1;
constexpr double init_midparticle_density = pressure * 133.3 * 1e-6 / (1.38 * 1e-23 * 300);

} // namespace flowAnalysis
