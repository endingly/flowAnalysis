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
    ~Atom();
    size_t hash() const;
    bool   operator==(const Atom& other) const noexcept;
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
    size_t hash() const;
    bool   operator==(const Ion& other) const noexcept;
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
    size_t hash() const;
    bool   operator==(const Molecule& other) const noexcept;
};

/// @brief 从 json 文件中读取粒子信息
void from_json(const nlohmann::json& j, Atom& p);
void from_json(const nlohmann::json& j, Ion& p);
void from_json(const nlohmann::json& j, Molecule& p);
/// @brief 将粒子信息写入 json 文件
void to_json(nlohmann::json& j, const Atom& p);
void to_json(nlohmann::json& j, const Ion& p);
void to_json(nlohmann::json& j, const Molecule& p);

} // namespace flowAnalysis

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

} // namespace std