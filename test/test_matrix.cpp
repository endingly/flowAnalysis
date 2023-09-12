#include "eigen_matrix_extension.hpp"
#include <Eigen/src/Core/Matrix.h>
#include <gtest/gtest.h>
#include <iostream>

// [x]: test EigenMatrix concept
TEST(matrix, test_matrix_extension)
{
    Eigen::MatrixXi A = Eigen::MatrixXi::Random(4, 4);
    Eigen::MatrixXi B = flowAnalysis::Get_space_step_x(A);
    Eigen::MatrixXi C = flowAnalysis::Get_space_step_y(A);
    std::cout << "A =" << std::endl;
    std::cout << A << std::endl << std::endl;

    std::cout << "B =" << std::endl;
    std::cout << B << std::endl;

    std::cout << "C =" << std::endl;
    std::cout << C << std::endl;
}