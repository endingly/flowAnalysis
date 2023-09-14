#pragma once
#include "common_define.hpp"
#include <string>
#include <vector>

namespace flowAnalysis
{

/// @brief 字符枚举
enum char_type
{
    space,
    number,
    letter,
    symbol
};

/// @brief 科学计数法形式的浮点数字符串(计算式)转换为浮点数
/// @param str 字符串
/// @return
double sstod(const std::string& str);

char_type get_char_type(const char& c);

}; // namespace flowAnalysis
