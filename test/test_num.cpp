#include "utility.hpp"
#include <gtest/gtest.h>
using std::string;

TEST(numeric, StringToConvert)
{
    string str    = "1.9e16";
    auto   result = flowAnalysis::sstod(str);
    EXPECT_DOUBLE_EQ(result, 1.9e16);
}

TEST(numeric, calculation_formula_StringToConvert)
{
    string str    = "1.9e16*1.9e16/MN";
    auto   result = flowAnalysis::sstod(str);
    std::cout << result << "\n";
}