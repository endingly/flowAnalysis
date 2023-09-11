#pragma once
#include <Eigen/Core>

namespace flowAnalysis
{

template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

template <typename Arg>
concept EigenMatrix = requires(Arg arg) {
    std::is_arithmetic_v<typename Arg::Scalar>&& Arg::RowSizeAtCompileTime != 1 &&
        Arg::ColSizeAtCompileTime != 1 &&
        std::is_same_v<std::decay_t<Arg>, Eigen::MatrixBase<typename Arg::Scalar>>;
};

template <EigenMatrix T>
class circulant_functor
{
    const T& s;

  public:
    circulant_functor(const T& arg) : s(arg)
    {
    }

    const typename T::Scalar& operator()(Eigen::Index row, Eigen::Index col) const
    {
        if (row == T::RowSizeAtCompileTime)
        {
            return 0;
        }
        return s(row, col + 1) - s(row, col);
    }
};

template <EigenMatrix T>
Eigen::CwiseNullaryOp<circulant_functor<T>, T> makeCirculant(const Eigen::MatrixBase<T>& arg)
{
    return T::NullaryExpr(arg.size(), arg.size(), circulant_functor<T>(arg.derived()));
}
}
; // namespace flowAnalysis