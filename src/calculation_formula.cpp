#include "calculation_formula.hpp"
#include "common_define.hpp"

namespace flowAnalysis
{

auto operator*(const Matrix& m, const Matrix& n)
{
    return m.array() * n.array();
}

}