#include "common_define.hpp"
#include "utility.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
using std::string;

TEST(numeric, StringToConvert)
{
    string str    = "1.9e16";
    auto   result = std::atof(str.c_str());
    ASSERT_EQ(result, 1.9e16);
}

TEST(numeric, stringToDouble)
{
    string str    = "1.9e10";
    auto   result = flowAnalysis::sstod(str);
    ASSERT_EQ(result, 1.9e10);
}

TEST(numeric, calculation_formula_StringToConvert)
{
    string str    = "1.9e16*1.9e16/MN";
    auto   result = flowAnalysis::sstod(str);
    ASSERT_EQ(result, 1.9e16 * 1.9e16 / flowAnalysis::init_midparticle_density);
}