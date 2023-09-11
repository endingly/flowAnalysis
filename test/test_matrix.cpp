#include "common_define.hpp"
#include "eigen_matrix_extension.hpp"
#include <gtest/gtest.h>

using namespace flowAnalysis;

TEST(matrix_extension, operator_add)
{
    Eigen::Matrix3d m;
    Eigen::Matrix3d n;
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    n << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "m:\n" << m << "\n\n";
    std::cout << "n:\n" << n << "\n\n";
    std::cout << "m + 2:\n" << m + 2.0 << "\n\n";
    std::cout << "2 + m:\n" << 2.0 + m << "\n\n";
    // std::cout << "m * n:\n" << m * n << "\n\n";
    // std::cout << "m.array()*n.array():\n" << m.array() * n.array() << "\n\n";
}

TEST(matrix_extension, operator_sub)
{
    Eigen::Matrix3d m;
    Eigen::Matrix3d n;
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    n << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "m:\n" << m << "\n\n";
    std::cout << "n:\n" << n << "\n\n";
    std::cout << "m - 2:\n" << m - 2.0 << "\n\n";
    std::cout << "2 - m:\n" << 2.0 - m << "\n\n";
}

TEST(matrix_extension, operator_multi)
{
    Eigen::Matrix3d m;
    Eigen::Matrix3d n;
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    n << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "m:\n" << m << "\n\n";
    std::cout << "n:\n" << n << "\n\n";
    std::cout << "m * 2:\n" << m * 2.0 << "\n\n";
    std::cout << "m * n:\n" << m * n << "\n\n";
}

TEST(matrix_extension, operator_div)
{
    Eigen::Matrix3d m;
    Eigen::Matrix3d n;
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    n << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "m:\n" << m << "\n\n";
    std::cout << "n:\n" << n << "\n\n";
    std::cout << "m / 2:\n" << m / 2.0 << "\n\n";
    std::cout << "m / n:\n" << m / n << "\n\n";
}

TEST(matrix_extension, math)
{
    Eigen::Matrix3d m;
    Eigen::Matrix3d n;
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    n << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "m:\n" << m << "\n\n";
    std::cout << "n:\n" << n << "\n\n";
    std::cout << "m * m + 2:\n"
              << (1.27709 + 4.20304 * 1.0E-4 * m + 9.31504 * 1.0E-6 * m ^ 2) * 760 * 300 /
                     (273 * FLOW_ANALYSIS_INIT_MIDPARTICLE_DENSITY)
              << "\n\n";
}