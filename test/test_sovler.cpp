#include "common_define.hpp"
#include "eigen_matrix_extension.hpp"
#include <gtest/gtest.h>
#include <solver.hpp>

using namespace flowAnalysis;

TEST(solver, init)
{
    auto s = std::make_unique<solver>();
}

TEST(solver, test_function_G1)
{
    Matrix m = Matrix::Random(4, 4);
    auto   a = solver::G1(m);
    std::cout << "m=\n" << m << "\n\n";
    std::cout << "a=\n" << a << "\n\n";
}

TEST(solver, test_function_H1)
{
    Matrix m = Matrix::Random(4, 4);
    auto   a = solver::H1(m);
    std::cout << "m=\n" << m << "\n\n";
    std::cout << "a=\n" << a << "\n\n";
}

TEST(solver, test_init_logic_sub)
{
    auto u   = Eigen::MatrixXi::Random(4, 4);
    auto G1  = Eigen::MatrixXi::Random(4, 4);
    auto G2  = Eigen::MatrixXi::Random(4, 4);
    auto n   = Eigen::MatrixXi::Random(4, 4);
    auto n_1 = Get_move_matrix_x(n);
    auto r   = u * (G1 * n_1 - G2 * n);

    std::cout << 2 * Get_move_matrix_x(r) * Get_move_matrix_x(r) << "\n\n";
}