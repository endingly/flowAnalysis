#pragma once
#include <Eigen/Core>

namespace flowAnalysis
{

template <typename ArgType>
class space_step_functor_x
{
    const ArgType& m_arg;

  public:
    using MatrixType =
        Eigen::Matrix<typename ArgType::Scalar, ArgType::SizeAtCompileTime,
                      ArgType::SizeAtCompileTime,
                      ArgType::Flags & Eigen::RowMajorBit ? Eigen::RowMajor : Eigen::ColMajor,
                      ArgType::MaxSizeAtCompileTime, ArgType::MaxSizeAtCompileTime>;

    space_step_functor_x(const ArgType& arg) : m_arg(arg)
    {
    }

    const typename ArgType::Scalar& operator()(Eigen::Index row, Eigen::Index col) const
    {
        if (row == m_arg.rows() - 1)
        {
            return 0;
        }
        return m_arg(row, col + 1) - m_arg(row, col);
    }
};

/// @brief Get the space step in x direction
template <typename ArgType>
Eigen::CwiseNullaryOp<space_step_functor_x<ArgType>,
                      typename space_step_functor_x<ArgType>::MatrixType>
Get_space_step_x(const Eigen::MatrixBase<ArgType>& arg)
{
    using Func       = space_step_functor_x<ArgType>;
    using MatrixType = typename Func::MatrixType;
    return MatrixType::NullaryExpr(arg.rows(), arg.cols(), Func(arg.derived()));
}

template <typename ArgType>
class space_step_functor_y
{
    const ArgType& m_arg;

  public:
    using MatrixType =
        Eigen::Matrix<typename ArgType::Scalar, ArgType::SizeAtCompileTime,
                      ArgType::SizeAtCompileTime,
                      ArgType::Flags & Eigen::RowMajorBit ? Eigen::RowMajor : Eigen::ColMajor,
                      ArgType::MaxSizeAtCompileTime, ArgType::MaxSizeAtCompileTime>;

    space_step_functor_y(const ArgType& arg) : m_arg(arg)
    {
    }

    const typename ArgType::Scalar& operator()(Eigen::Index row, Eigen::Index col) const
    {
        if (col == m_arg.cols() - 1)
        {
            return 0;
        }
        return m_arg(row + 1, col) - m_arg(row, col);
    }
};

/// @brief Get the space step in y direction
template <typename ArgType>
Eigen::CwiseNullaryOp<space_step_functor_y<ArgType>,
                      typename space_step_functor_y<ArgType>::MatrixType>
Get_space_step_y(const Eigen::MatrixBase<ArgType>& arg)
{
    using Func       = space_step_functor_y<ArgType>;
    using MatrixType = typename Func::MatrixType;
    return MatrixType::NullaryExpr(arg.rows(), arg.cols(), Func(arg.derived()));
}

}; // namespace flowAnalysis