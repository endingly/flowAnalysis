// #pragma once
// #include <common_define.hpp>

// namespace flowAnalysis
// {

// template <typename T>
// concept Numeric = std::is_arithmetic_v<T>;

// template <Numeric T, int rows, int cols>
// auto operator+(const Eigen::Matrix<T, rows, cols>& lhs, T rhs)
// {
//     return lhs.array() + rhs;
// }

// template <Numeric T, int rows, int cols>
// auto operator+(T lhs, const Eigen::Matrix<T, rows, cols>& rhs)
// {
//     return lhs + rhs.array();
// }

// template <Numeric T, int rows, int cols>
// auto operator-(const Eigen::Matrix<T, rows, cols>& lhs, T rhs)
// {
//     return lhs.array() - rhs;
// }

// template <Numeric T, int rows, int cols>
// auto operator-(T lhs, const Eigen::Matrix<T, rows, cols>& rhs)
// {
//     return lhs - rhs.array();
// }

// template <Numeric T, int rows, int cols>
// auto operator*(const Eigen::Matrix<T, rows, cols>& lhs, const Eigen::Matrix<T, rows, cols>& rhs)
// {
//     return lhs.array() * rhs.array();
// }

// template <Numeric T, int rows, int cols>
// auto operator/(const Eigen::Matrix<T, rows, cols>& lhs, const Eigen::Matrix<T, rows, cols>& rhs)
// {
//     return lhs.array() / rhs.array();
// }

// template <Numeric T, int rows, int cols>
// auto operator^(const Eigen::Matrix<T, rows, cols>& lhs, T n)
// {
//     return lhs.array().pow(n);
// }


// } // namespace flowAnalysis