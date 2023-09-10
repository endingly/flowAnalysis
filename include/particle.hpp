#pragma once
#include "common_define.hpp"
#include "utility.hpp"
#include <fmt/core.h>
#include <nlohmann/json.hpp>

namespace flowAnalysis
{

enum class ExciteState
{
    Ground  = 0,
    Excited = 1
};

class Atom
{
  public:
    std::string name;
    ExciteState state;           // 激发状态，常规原子是 groud
    std::string exciteStateName; // 激发状态
    double      D;               // 扩散系数
    Matrix      N;
    Matrix      Dx, Dy;
    Matrix      Zx, Zy;
    Matrix      Jx, Jy;

    Matrix G1x, G1y;
    Matrix G2x, G2y;
    Matrix H1x, H1y;
    Matrix LPx, LPy;

    Atom(std::string name, ExciteState state, std::string exciteStateName);
    Atom();

    bool operator==(const Atom& other) const noexcept;
    Atom(const Atom& other);
    Atom& operator=(const Atom& other);
    Atom(Atom&& other) noexcept;
    Atom& operator=(Atom&& other) noexcept;
    ~Atom();
};

class Ion
{
  public:
    std::string name;     // 名字
    int         polarity; // 1 为正, -1 为负
    double      D;        // 扩散系数
    Matrix      ux, uy;   // 迁移系数
    Matrix      Jx, Jy;   // 电流密度
    Matrix      Dx, Dy;   // 扩散系数
    Matrix      Zx, Zy;   // 粒子流密度
    Matrix      Jdx, Jdy; // 电流密度在空间上的步进
    Matrix      N;        // 摩尔的量

    Matrix G1x, G1y;
    Matrix G2x, G2y;
    Matrix H1x, H1y;
    Matrix LPx, LPy;

    Ion(std::string name, int polarity);
    Ion();
    ~Ion();
    bool operator==(const Ion& other) const noexcept;
    Ion(const Ion& other);
    Ion& operator=(const Ion& other);
    Ion(Ion&& other) noexcept;
    Ion& operator=(Ion&& other) noexcept;
};

class Molecule
{
  public:
    std::string name;
    int         polarity;
    ExciteState state;
    std::string exciteStateName;
    double      D; // 扩散系数
    Matrix      ux, uy;
    Matrix      Jx, Jy;
    Matrix      Dx, Dy;
    Matrix      Zx, Zy;
    Matrix      Jdx, Jdy;
    Matrix      N;

    Matrix G1x, G1y;
    Matrix G2x, G2y;
    Matrix H1x, H1y;
    Matrix LPx, LPy;

    Molecule(std::string name, int polarity, ExciteState state, std::string exciteStateName);
    Molecule();
    ~Molecule();

    bool operator==(const Molecule& other) const noexcept;
    Molecule(const Molecule& other);
    Molecule& operator=(const Molecule& other);
    Molecule(Molecule&& other) noexcept;
    Molecule& operator=(Molecule&& other) noexcept;
};

} // namespace flowAnalysis

// 对于拥有移动构造的类，需要另外特化
namespace nlohmann
{
template <>
struct adl_serializer<flowAnalysis::Atom>
{
    static void from_json(const json& j, flowAnalysis::Atom& p)
    {
        p.name            = j.at("name").get<std::string>();
        p.state           = j.at("state").get<flowAnalysis::ExciteState>();
        p.exciteStateName = j.at("exciteStateName").get<std::string>();
        p.D               = flowAnalysis::sstod(j.at("D").get<std::string>());
    }

    static void to_json(json& j, const flowAnalysis::Atom& p)
    {
        j = nlohmann::json{{"name", p.name},
                           {"state", p.state},
                           {"exciteStateName", p.exciteStateName},
                           {"D", fmt::format("{0:.2e}", p.D)}};
    }
};

template <>
struct adl_serializer<flowAnalysis::Ion>
{
    static void from_json(const json& j, flowAnalysis::Ion& p)
    {
        p.name     = j.at("name").get<std::string>();
        p.polarity = j.at("polarity").get<int>();
        p.D        = flowAnalysis::sstod(j.at("D").get<std::string>());
    }

    static void to_json(json& j, const flowAnalysis::Ion& p)
    {
        j = nlohmann::json{
            {"name", p.name}, {"polarity", p.polarity}, {"D", fmt::format("{0:.2e}", p.D)}};
    }
};

template <>
struct adl_serializer<flowAnalysis::Molecule>
{
    static void from_json(const json& j, flowAnalysis::Molecule& p)
    {
        p.name            = j.at("name").get<std::string>();
        p.polarity        = j.at("polarity").get<int>();
        p.state           = j.at("state").get<flowAnalysis::ExciteState>();
        p.exciteStateName = j.at("exciteStateName").get<std::string>();
        p.D               = flowAnalysis::sstod(j.at("D").get<std::string>());
    }

    static void to_json(json& j, const flowAnalysis::Molecule& p)
    {
        j = nlohmann::json{{"name", p.name},
                           {"polarity", p.polarity},
                           {"state", p.state},
                           {"exciteStateName", p.exciteStateName},
                           {"D", fmt::format("{0:.2e}", p.D)}};
    }
};

} // namespace nlohmann