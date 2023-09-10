#include "common_define.hpp"
#include <gtest/gtest.h>


using namespace flowAnalysis;

TEST(matrix, custom_operator)
{
    Eigen::Matrix3d m;
    Eigen::Matrix3d n;
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    n << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "m:\n" << m << "\n\n";
    std::cout << "n:\n" << n << "\n\n";
    std::cout << "m + n:\n" << m + n << "\n\n";
    std::cout << "m * n:\n" << m * n << "\n\n";
    std::cout << "m.array()*n.array():\n" << m.array() * n.array() << "\n\n";
}