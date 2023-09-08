#include <Eigen/Core>
#include <gtest/gtest.h>

using Matrix = Eigen::Matrix<double, 3, 3, Eigen::ColMajor>;

auto operator+(const Matrix& m, const double& n)
{
    return m.array() + n;
}

auto operator+(const double& n, const Matrix& m)
{
    return n + m.array();
}

TEST(matrix, custom_operator)
{
    Matrix m = Matrix::Random();
    double n = 2;
    std::cout << "m:\n" << m << "\n\n";
    std::cout << "m * 2:\n" << 2 * m << "\n\n";
}