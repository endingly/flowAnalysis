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
            return m_arg(row, col + 1) - m_arg(row, col);
        }
        else
        {
            return 0;
        }
    }
};

/// @brief 获取一个矩阵在 x 方向的差值矩阵，此方法只适用于动态矩阵
template <typename ArgType>
inline Eigen::CwiseNullaryOp<space_step_functor_x<ArgType>,
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
            return m_arg(row + 1, col) - m_arg(row, col);
        }
        else
        {
            return 0;
        }
    }
};

/// @brief 获取一个矩阵在 y 方向的差值矩阵，此方法只适用于动态矩阵
/// @param arg 输入矩阵
template <typename ArgType>
inline Eigen::CwiseNullaryOp<space_step_functor_y<ArgType>,
                             typename space_step_functor_y<ArgType>::MatrixType>
Get_space_step_y(const Eigen::MatrixBase<ArgType>& arg)
{
    using Func       = space_step_functor_y<ArgType>;
    using MatrixType = typename Func::MatrixType;
    return MatrixType::NullaryExpr(arg.rows(), arg.cols(), Func(arg.derived()));
}

template <typename ArgType>
class move_matrix_functor_x
{
    const ArgType& m_arg;

  public:
    using MatrixType = Eigen::Matrix<typename ArgType::Scalar, ArgType::SizeAtCompileTime,
                                     ArgType::SizeAtCompileTime, Eigen::ColMajor,
                                     ArgType::MaxSizeAtCompileTime, ArgType::MaxSizeAtCompileTime>;

    move_matrix_functor_x(const ArgType& arg) : m_arg(arg)
    {
    }

    const typename ArgType::Scalar& operator()(Eigen::Index row, Eigen::Index col) const
    {
        if (row >= 0 && row < m_arg.rows() && col >= 0 && col <= m_arg.cols() - 2)
        {
            return m_arg(row, col + 1);
        }
        else
        {
            return 0;
        }
    }
};

template <typename ArgType>
inline Eigen::CwiseNullaryOp<move_matrix_functor_x<ArgType>,
                             typename move_matrix_functor_x<ArgType>::MatrixType>
Get_move_matrix_x(const Eigen::MatrixBase<ArgType>& arg)
{
    using Func       = move_matrix_functor_x<ArgType>;
    using MatrixType = typename Func::MatrixType;
    return MatrixType::NullaryExpr(arg.rows(), arg.cols(), Func(arg.derived()));
}

template <typename ArgType>
class move_matrix_functor_y
{
    const ArgType& m_arg;

  public:
    using MatrixType = Eigen::Matrix<typename ArgType::Scalar, ArgType::SizeAtCompileTime,
                                     ArgType::SizeAtCompileTime, Eigen::ColMajor,
                                     ArgType::MaxSizeAtCompileTime, ArgType::MaxSizeAtCompileTime>;

    move_matrix_functor_y(const ArgType& arg) : m_arg(arg)
    {
    }

    const typename ArgType::Scalar& operator()(Eigen::Index row, Eigen::Index col) const
    {
        if (row >= 0 && row <= m_arg.rows() - 2 && col >= 0 && col < m_arg.cols())
        {
            return m_arg(row + 1, col);
        }
        else
        {
            return 0;
        }
    }
};

template <typename ArgType>
inline Eigen::CwiseNullaryOp<move_matrix_functor_y<ArgType>,
                             typename move_matrix_functor_y<ArgType>::MatrixType>
Get_move_matrix_y(const Eigen::MatrixBase<ArgType>& arg)
{
    using Func       = move_matrix_functor_y<ArgType>;
    using MatrixType = typename Func::MatrixType;
    return MatrixType::NullaryExpr(arg.rows(), arg.cols(), Func(arg.derived()));
}

}; // namespace flowAnalysis