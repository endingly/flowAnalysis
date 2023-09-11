#pragma once
#include "fluid.hpp"

namespace flowAnalysis
{

class solver
{
  private:
    double dx, dy; // 空间步长
    double dt;     // 时间步长

    std::unique_ptr<fluid> f;

  public:
    solver();
    ~solver();

    /// @brief 初始化迁移与扩散矩阵
    void init_MigrationAndDiffusion();

    /// @brief 利用半隐式方法求解泊松方程
    void solve_poisson_equation();

  private:
    /// @brief 初始化电子的迁移系数，在 init_MigrationAndDiffusion 中调用
    void init_uex();
    /// @brief 初始化电子的扩散系数，在 init_MigrationAndDiffusion 中调用
    void init_Dex();
    /// @brief 初始化各粒子的迁移系数与扩散系数，在 init_MigrationAndDiffusion 中调用
    void init_particle_u_D();
    /// @brief 初始化用于计算粒子流密度间接矩阵，在 init_MigrationAndDiffusion 中调用
    void init_Zx();
    /// @brief 初始化每种粒子的三种系数，在 solve_poisson_equation 中调用
    void init_GHL_matrix();

  public:
    static Matrix& H1(const Matrix& Z);
    static Matrix& G1(const Matrix& Z);
};

} // namespace flowAnalysis
