#include "utility.hpp"
#include <gtest/gtest.h>
using std::string;

TEST(test_char, isAtom)
{
    string str  = "O";
    auto   type = flowAnalysis::get_particle_type(str);
    EXPECT_EQ(type, flowAnalysis::atom);
}

TEST(test_char, isMolecule)
{
    string str  = "CO2";
    auto   type = flowAnalysis::get_particle_type(str);
    EXPECT_EQ(type, flowAnalysis::molecule);
}

TEST(test_char, isIon)
{
    string str  = "H+";
    auto   type = flowAnalysis::get_particle_type(str);
    EXPECT_EQ(type, flowAnalysis::ion);
}

TEST(test_char, isElectron)
{
    string str  = "e";
    auto   type = flowAnalysis::get_particle_type(str);
    EXPECT_EQ(type, flowAnalysis::electron);
}

TEST(test_char, isAtomWithE_two_up_letter)
{
    string str  = "He+";
    auto   type = flowAnalysis::get_particle_type(str);
    EXPECT_EQ(type, flowAnalysis::ion);
}

TEST(test_char, isMoleculeWithE)
{
    string str  = "CO3+";
    auto   type = flowAnalysis::get_particle_type(str);
    EXPECT_EQ(type, flowAnalysis::molecule);
}