#include "eigen_matrix_extension.hpp"
#include <Eigen/src/Core/Matrix.h>
#include <gtest/gtest.h>
#include <iostream>

// [ ]: warning: unused parameter ‘row’ [-Wunused-parameter]
TEST(matrix, test_matrix_extension)
{
    Eigen::MatrixXi A(3, 3);
    A << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    Eigen::MatrixXi B = flowAnalysis::Get_space_step_x(A);
    Eigen::MatrixXi C = flowAnalysis::Get_space_step_y(A);
    std::cout << "A =" << std::endl;
    std::cout << A << std::endl << std::endl;

    std::cout << "B =" << std::endl;
    std::cout << B << std::endl;

    std::cout << "C =" << std::endl;
    std::cout << C << std::endl;
}

TEST(matrix, test_matrix_extension_no_q)
{
    Eigen::MatrixXi A = Eigen::MatrixXi::Random(5, 7);
    Eigen::MatrixXi B = flowAnalysis::Get_space_step_x(A);
    Eigen::MatrixXi C = flowAnalysis::Get_space_step_y(A);
    std::cout << "A =" << std::endl;
    std::cout << A << std::endl << std::endl;

    std::cout << "B =" << std::endl;
    std::cout << B << std::endl;

    std::cout << "C =" << std::endl;
    std::cout << C << std::endl;
}

TEST(matrix, test_move_matrix_xy)
{
    Eigen::MatrixXi A = Eigen::MatrixXi::Random(5, 7);
    Eigen::MatrixXi B = flowAnalysis::Get_move_matrix_x(A);
    Eigen::MatrixXi C = flowAnalysis::Get_move_matrix_y(A);
    std::cout << "A =" << std::endl;
    std::cout << A << std::endl << std::endl;

    std::cout << "B =" << std::endl;
    std::cout << B << std::endl;

    std::cout << "C =" << std::endl;
    std::cout << C << std::endl;
}
