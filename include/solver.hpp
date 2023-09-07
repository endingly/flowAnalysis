#pragma once
#include "fluid.hpp"

namespace flowAnalysis
{

class solver
{
  private:
    std::unique_ptr<fluid> f;

  public:
    solver();
    ~solver();
};

} // namespace flowAnalysis
