#include "eigen_matrix_extension.hpp"
#include <Eigen/src/Core/Matrix.h>
#include <gtest/gtest.h>

// [ ]: test EigenMatrix concept
TEST(matrix, test_matrix_extension)
{
    Eigen::Matrix<int, 4, 4> m;
    m << 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8;
    flowAnalysis::makeCirculant(m);
}