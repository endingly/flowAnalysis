#pragma once
#include "particle_manager.hpp"
#include <memory>

namespace flowAnalysis
{

class fluid
{
  private:
    Matrix           E, Ex, Ey; // 电场，x轴电场以及y轴电场
    Matrix           Jex, Jey;  // 电流密度
    Matrix           uex, uey;  // 电子迁移系数
    Matrix           Dex, Dey;  // 电子扩散系数
    particle_manager pm;        // 粒子管理器
  public:
    fluid(/* args */);
    ~fluid();
};

} // namespace flowAnalysis