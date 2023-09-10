#include <gtest/gtest.h>
#include <solver.hpp>

TEST(solver, init)
{
    

    flowAnalysis::solver s;
    s.init_MigrationAndDiffusion();
    // s.solve_poisson_equation();
}