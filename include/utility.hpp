#pragma once
#include "common_define.hpp"
#include <string>

namespace flowAnalysis
{

/// @brief 字符枚举
enum char_type
{
    space,
    number,
    low_letter,
    up_letter,
    symbol
};

/// @brief 科学计数法形式的浮点数字符串(计算式)转换为浮点数
/// @param str 字符串
/// @return
double sstod(const std::string& str);

/// @brief 获取字符串中是否含有符号
/// @param str 字符串
/// @return 符号类型
particelType get_particle_type(const std::string& str);

}; // namespace flowAnalysis
