#include "common_define.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <solver.hpp>
using namespace flowAnalysis;

TEST(solver, init)
{
    // flowAnalysis::solver s;
    // s.solve_poisson_equation();
    Matrix m = Matrix::Random(imax, jmax);
    auto   a = solver::G1(m);
    std::cout << a << "\n";
}