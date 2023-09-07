#pragma once
#include "particle_manager.hpp"
#include <memory>

namespace flowAnalysis
{

class fluid
{
  private:
    float            gama_O2, gama_CO2;  // 二次发射系数
    float            SecEnergy;          // 二次发射初始能量
    float            MidParticleDensity; // 中性粒子初始密度
    double           MidParticleDensity_O2, MidParticleDensity_CO2;
    Matrix           E, Ex, Ey; // 电场，x轴电场以及y轴电场
    Matrix           Jex, Jey;  // 电流密度
    Matrix           uex, uey;  // 电子迁移系数
    Matrix           Dex, Dey;  // 电子扩散系数
    Matrix           Kte;       // 电子温度
    Matrix           phi;       // 电势 # Math: \phi
    Matrix           Ener;      // 能量
    particle_manager pm;        // 粒子管理器
  public:
    fluid();
    ~fluid();

  private:
    friend class solver;
};

} // namespace flowAnalysis