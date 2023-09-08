#pragma once
#include "fluid.hpp"

namespace flowAnalysis
{

class solver
{
  private:
    std::unique_ptr<fluid> f;

  public:
    solver();
    ~solver();

  public:
    /// @brief 初始化迁移与扩散矩阵
    void init_MigrationAndDiffusion();
};

} // namespace flowAnalysis
