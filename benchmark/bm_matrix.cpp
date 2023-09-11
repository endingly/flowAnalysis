#include <Eigen/Core>
#include <benchmark/benchmark.h>
#include <iostream>
#include <memory>


using Matrix = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;

static void BM_eigen_matrix(benchmark::State& state)
{
    Matrix m = Matrix::Random(1000, 1000);
    Matrix n = Matrix::Random(1000, 1000);
    Matrix result;
    for (auto _ : state)
    {
        result = m * n;
    }
}

BENCHMARK(BM_eigen_matrix);
