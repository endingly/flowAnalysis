#pragma once
#include <string>
#include <memory>

namespace flowAnalysis
{
struct Parma
{
    float xmax;
    float ymax;
    float imax;
    float jmax;
    float pressure;
    float voltage;
    float dt;
    float gamma;
    float i2;
    float i3;
    float F_He;
    float F_CO_2;

  public:
    /// @brief 序列化为 json 字符串
    /// @return json 字符串
    std::string ToString();

    /// @brief 从 json 字符串反序列化
    /// @param jsonString 指定 json 字符串
    /// @return 在堆上分配的结果结构体
    static std::unique_ptr<Parma> Parse(std::string jsonString);

    /// @brief 将 json 字符串写入文件
    /// @param path 文件名
    /// @return 
    bool ToFile(std::string path);

    /// @brief 从 json 文件中读取并反序列化
    /// @param path 文件路径
    /// @return 序列化结果
    static std::unique_ptr<Parma> FromFile(std::string path);
};
} // namespace flowAnalysis