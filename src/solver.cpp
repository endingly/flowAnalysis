#include "solver.hpp"
#include "common_define.hpp"

namespace flowAnalysis
{

auto operator*(const Matrix& m, const Matrix& n)
{
    return m.array() * n.array();
}

solver::solver()
{
    f = std::make_unique<fluid>();
}

solver::~solver()
{
}

}