#include "utility.hpp"
#include <stdexcept>

bool _sstod(const std::string& str, double* d)
{
    const auto* s = str.c_str();
    bool bNegtiveBase, bNegtiveExp; // 分别表示基数和指数是否为负
    int         nPreZero = 0; // 基数前缀0的个数
    const char* p;
    int         sum_i   = 0;
    double      sum_f   = 0.0;
    int         sum_exp = 0;
    double      sum     = 0.0;
    bNegtiveBase = bNegtiveExp = false;
    if (!s)
    {
        return false;
    }
    if ('-' == *s)
    {
        bNegtiveBase = true;
        s++;
    }
    for (; '0' == *s; nPreZero++, s++)
        ; // 统计基数前缀0的个数
    for (; *s != '.' && *s != 'e' && *s != 'E' && *s != '\0'; s++)
    {
        if (*s < '0' || *s > '9')
        {
            return false;
        }
        sum_i = sum_i * 10 + *s - '0';
    }
    if (0 == sum_i &&
        0 ==
            nPreZero) // 基数为0且前缀0个数为0，说明是.25、e7、E7、“”之类的数据格式
        return false;
    if ('.' == *s) // 还需要计算小数部分数值
    {
        for (p = s; *p != 'e' && *p != 'E' && *p != '\0'; p++)
            ; // 找到尾数部分的末尾
        if (s == p - 1)
            return false;
        s = p;
        p--;
        for (; *p != '.'; p--)
        {
            if (*p < '0' || *p > '9')
                return false;
            sum_f = sum_f * 0.1 + 0.1 * (*p - '0');
        }
    }
    if ('e' == *s || 'E' == *s) // 还需要计算阶码
    {
        s++;
        if ('-' == *s)
        {
            bNegtiveExp = true;
            s++;
        }
        else if ('+' == *s)
        {
            bNegtiveExp = false;
            s++;
        }
        nPreZero = 0;
        for (; *s != '\0'; s++)
        {
            if (*s < '0' || *s > '9')
            {
                return false;
            }
            sum_exp = sum_exp * 10 + *s - '0';
            nPreZero++;
        }
        if (0 == sum_exp && 0 == nPreZero)
            return false;
    }
    sum = sum_i + sum_f;
    if (bNegtiveExp) // 阶码为负
    {
        while (sum_exp > 0)
        {
            sum /= 10;
            sum_exp--;
        }
    }
    else
    {
        while (sum_exp > 0)
        {
            sum *= 10;
            sum_exp--;
        }
    }
    if (bNegtiveBase) // 基数为负
        sum = -sum;
    *d = sum;
    return true;
}

double flowAnalysis::sstod(const std::string& str)
{
    double d;
    if (!_sstod(str, &d))
    {
        throw std::runtime_error("Error: " + str +
                                 " is not a number.");
    }
    return d;
}