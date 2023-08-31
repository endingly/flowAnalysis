#include "particle_manager.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(particle_manager, init)
{
    flowAnalysis::particle_manager pm;
    std::cout << pm.atom["H"].name << std::endl;
    ASSERT_TRUE(true);
}