#pragma once
#include "common_define.hpp"

namespace flowAnalysis
{

class Fluid
{
  private:
    Matrix E, Ex, Ey;   // 电场，x轴电场以及y轴电场
    Matrix Jex, Jey;    // 电流密度
    Matrix uex, uey;    // 电子迁移系数
    Matrix Dex, Dey;    // 电子扩散系数
  public:
    Fluid(/* args */);
    ~Fluid();
};

} // namespace flowAnalysis