#pragma once
#pragma warning(disable : 4172)
#include <Eigen/Core>

namespace flowAnalysis
{

template <typename ArgType>
class space_step_functor_x
{
    const ArgType& m_arg;

  public:
    using MatrixType = Eigen::Matrix<typename ArgType::Scalar, ArgType::SizeAtCompileTime,
                                     ArgType::SizeAtCompileTime, Eigen::ColMajor,
                                     ArgType::MaxSizeAtCompileTime, ArgType::MaxSizeAtCompileTime>;

    space_step_functor_x(const ArgType& arg) : m_arg(arg)
    {
    }

    const typename ArgType::Scalar& operator()(Eigen::Index row, Eigen::Index col) const
    {
        if (row >= 0 && row < m_arg.rows() && col >= 0 && col <= m_arg.cols() - 2)
        {
            return m_arg.data()[row * m_arg.cols() + col + 1] -
                   m_arg.data()[row * m_arg.cols() + col];
        }
        else
        {
            return 0;
        }
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
    using MatrixType = Eigen::Matrix<typename ArgType::Scalar, ArgType::SizeAtCompileTime,
                                     ArgType::SizeAtCompileTime, Eigen::ColMajor,
                                     ArgType::MaxSizeAtCompileTime, ArgType::MaxSizeAtCompileTime>;

    space_step_functor_y(const ArgType& arg) : m_arg(arg)
    {
    }

    const typename ArgType::Scalar& operator()(Eigen::Index row, Eigen::Index col) const
    {

        if (row >= 0 && row <= m_arg.rows() - 2 && col >= 0 && col < m_arg.cols())
        {
            return m_arg.data()[(row + 1) * m_arg.cols() + col] -
                   m_arg.data()[row * m_arg.cols() + col];
        }
        else
        {
            return 0;
        }
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