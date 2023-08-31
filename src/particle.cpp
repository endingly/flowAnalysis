#include "particle.hpp"
#include <Parma.hpp>

flowAnalysis::Atom::Atom(std::string name, ExciteState state, std::string exciteStateName)
{
    this->name = name;
    this->state = state;
    this->exciteStateName = exciteStateName;

    this->N = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
}

flowAnalysis::Atom::~Atom()
{
}

flowAnalysis::Ion::Ion(/* args */)
{
    // [ ] Ion 构造函数
}

flowAnalysis::Ion::~Ion()
{
}

flowAnalysis::Molecule::Molecule(/* args */)
{
    // [ ] Molecule 构造函数
}

flowAnalysis::Molecule::~Molecule()
{
}