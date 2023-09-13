#include "utility.hpp"
#include "common_define.hpp"
#include <cstdlib>

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperator(const std::string& c)
{
    return c == "+" || c == "-" || c == "*" || c == "/";
}

// 分割数学表达式字符串
std::vector<std::string> splitExpression(const std::string& expression)
{
    std::vector<std::string> tokens;
    int                      currentIndex = 0;
    // 遍历字符串之前应该找到最后一个运算符的位置
    int lastOperatorIndex = 0;
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        if (isOperator(expression[i]))
        {
            lastOperatorIndex = i;
            break;
        }
    }

    bool first = true;
    int  fix   = 0;
    // 遍历字符串
    for (int i = 0; i < expression.length(); i++)
    {
        if (!isOperator(expression[i]))
        {
            continue;
        }
        if (i == lastOperatorIndex)
        {
            // 最后一个运算符，直接分割
            tokens.push_back(expression.substr(currentIndex + 1, i - currentIndex - 1));
            tokens.push_back(expression.substr(i, 1));
            tokens.push_back(expression.substr(i + 1, expression.length() - i - 1));
            return tokens;
        }

        // 遇到运算符就分割
        // 运算符前面的字符串
        tokens.push_back(expression.substr(currentIndex + fix, i - currentIndex - fix));
        // 以及运算符本身
        tokens.push_back(expression.substr(i, 1));
        currentIndex = i;
        if (first)
        {
            fix   = 1;
            first = false;
        }
    }
    return tokens;
}

//[x]: 数学表达式解析错误，待 fix
double flowAnalysis::sstod(const std::string& str)
{
    if (str.find('*') == -1 && str.find('/') == -1)
    {
        return std::atof(str.c_str());
    }
    double                   result;
    std::vector<std::string> tokens = splitExpression(str);
    bool                     first  = true;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (!isOperator(tokens[i][0]))
        {
            // 先看有没有 MN
            double temp;
            if (tokens[i] == "MN")
            {
                temp = init_midparticle_density;
            }
            else
            {
                temp = std::atof(tokens[i].c_str());
            }
            if (first)
            {
                result = temp;
                first  = false;
            }
            else
            {
                switch (tokens[i - 1][0])
                {
                case '+':
                    result += temp;
                    break;
                case '-':
                    result -= temp;
                    break;
                case '*':
                    result *= temp;
                    break;
                case '/':
                    result /= temp;
                    break;
                default:
                    break;
                }
            }
        }
    }
    return result;
}
