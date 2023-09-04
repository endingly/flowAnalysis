#pragma once
#include "common_define.hpp"
#include <nlohmann/json.hpp>
#include <string>

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
    Matrix      N;
    Matrix      Dx, Dy;
    Matrix      Zx, Zy;
    Matrix      Jx, Jy;

    Atom(std::string name, ExciteState state, std::string exciteStateName);
    Atom();

    bool operator==(const Atom& other) const noexcept;
    Atom(const Atom& other);
    Atom& operator=(const Atom& other);
    Atom(Atom&& other) noexcept;
    Atom& operator=(Atom&& other) noexcept;
    ~Atom();
    [[nodiscard]] size_t hash() const;
};

class Ion
{
  public:
    std::string name;     // 名字
    int         polarity; // 1 为正, -1 为负
    Matrix      ux, uy;   // 迁移系数
    Matrix      Jx, Jy;   // 电流密度
    Matrix      Dx, Dy;   // 扩散系数
    Matrix      Zx, Zy;   // 粒子流密度
    Matrix      Jdx, Jdy; // 电流密度在空间上的步进
    Matrix      N;        // 摩尔的量

    Ion(std::string name, int polarity);
    Ion();
    ~Ion();
    bool operator==(const Ion& other) const noexcept;
    Ion(const Ion& other);
    Ion& operator=(const Ion& other);
    Ion(Ion&& other) noexcept;
    Ion& operator=(Ion&& other) noexcept;

    [[nodiscard]] size_t hash() const;
};

class Molecule
{
  public:
    std::string name;
    int         polarity;
    ExciteState state;
    std::string exciteStateName;
    Matrix      ux, uy;
    Matrix      Jx, Jy;
    Matrix      Dx, Dy;
    Matrix      Zx, Zy;
    Matrix      Jdx, Jdy;
    Matrix      N;

    Molecule(std::string name, int polarity, ExciteState state, std::string exciteStateName);
    Molecule();
    ~Molecule();

    bool operator==(const Molecule& other) const noexcept;
    Molecule(const Molecule& other);
    Molecule& operator=(const Molecule& other);
    Molecule(Molecule&& other) noexcept;
    Molecule& operator=(Molecule&& other) noexcept;

    [[nodiscard]] size_t hash() const;
};
} 

// -------------------------------------
// 为了让自定义的类型可以作为 std::unordered_map 的 key
namespace std
{

template <typename T>
concept Has_Hash_Function = requires {
    requires requires(const T obj) {
        {
            obj.hash()
        } -> std::same_as<std::size_t>;
    };
};

template <Has_Hash_Function T>
struct hash<T>
{
    std::size_t operator()(const T& obj) const noexcept
    {
        return obj.hash();
    }
};

} 

// 对于拥有移动构造的类，需要另外特化
namespace nlohmann
{
template <>
struct adl_serializer<flowAnalysis::Atom>
{
    static flowAnalysis::Atom from_json(const json& j)
    {
        auto* p            = new flowAnalysis::Atom();
        p->name            = j.at("name").get<std::string>();
        p->state           = j.at("state").get<flowAnalysis::ExciteState>();
        p->exciteStateName = j.at("exciteStateName").get<std::string>();
        return std::move(*p);
    }

    static void to_json(json& j, flowAnalysis::Atom p)
    {
        j = nlohmann::json{{"name", p.name}, {"state", p.state}, {"exciteStateName", p.exciteStateName}};
    }
};

template <>
struct adl_serializer<flowAnalysis::Ion>
{
    static flowAnalysis::Ion from_json(const json& j)
    {
        auto* p     = new flowAnalysis::Ion();
        p->name     = j.at("name").get<std::string>();
        p->polarity = j.at("polarity").get<int>();
        return std::move(*p);
    }

    static void to_json(json& j, flowAnalysis::Ion p)
    {
        j = nlohmann::json{{"name", p.name}, {"polarity", p.polarity}};
    }
};

template <>
struct adl_serializer<flowAnalysis::Molecule>
{
    static flowAnalysis::Molecule from_json(const json& j)
    {
        auto* p            = new flowAnalysis::Molecule();
        p->name            = j.at("name").get<std::string>();
        p->polarity        = j.at("polarity").get<int>();
        p->state           = j.at("state").get<flowAnalysis::ExciteState>();
        p->exciteStateName = j.at("exciteStateName").get<std::string>();
        return std::move(*p);
    }

    static void to_json(json& j, flowAnalysis::Molecule p)
    {
        j = nlohmann::json{
            {"name", p.name}, {"polarity", p.polarity}, {"state", p.state}, {"exciteStateName", p.exciteStateName}};
    }
};

}