#pragma once
#include "common_define.hpp"
#include <string>

namespace flowAnalysis
{
    
enum class ExciteState
{
    Ground = 0,
    Excited = 1
};

struct Atom
{
    std::string name;
    ExciteState state;           // 激发状态，常规原子是 groud
    std::string exciteStateName; // 激发状态
    Matrix N;
    Matrix Dx, Dy;
    Matrix Zx, Zy;
    Matrix Jx, Jy;

    Atom(std::string name, ExciteState state, std::string exciteStateName);
    ~Atom();
};

struct Ion
{
    std::string name; // 名字
    int polarity;     // 1 为正, -1 为负
    Matrix ux, uy;    // 迁移系数
    Matrix Jx, Jy;    // 电流密度
    Matrix Dx, Dy;    // 扩散系数
    Matrix Zx, Zy;    // 粒子流密度
    Matrix Jdx, Jdy;  // 电流密度在空间上的步进
    Matrix N;         // 摩尔的量

    Ion(/* args */);
    ~Ion();
};

struct Molecule
{
    std::string name;
    int polarity;
    ExciteState state;
    std::string exciteStateName;
    Matrix ux, uy;
    Matrix Jx, Jy;
    Matrix Dx, Dy;
    Matrix Zx, Zy;
    Matrix Jdx, Jdy;
    Matrix N;

    Molecule(/* args */);
    ~Molecule();
};

} // namespace flowAnalysis