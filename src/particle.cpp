#include "particle.hpp"
#include <Parma.hpp>
using std::string;

flowAnalysis::Atom::Atom()
{
    this->name = "";
    this->state = ExciteState::Ground;
    this->exciteStateName = "";

    this->N = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
}

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

flowAnalysis::Ion::Ion()
{
    this->name = "";
    this->polarity = 0;

    this->ux = Matrix::Zero();
    this->uy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N = Matrix::Zero();
}

flowAnalysis::Ion::Ion(string name, int polarity)
{
    this->name = name;
    this->polarity = polarity;

    this->ux = Matrix::Zero();
    this->uy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N = Matrix::Zero();
}

flowAnalysis::Ion::~Ion()
{
}

flowAnalysis::Molecule::Molecule()
{
    this->name = "";
    this->polarity = 0;
    this->state = ExciteState::Ground;
    this->exciteStateName = "";

    this->ux = Matrix::Zero();
    this->uy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N = Matrix::Zero();
}

flowAnalysis::Molecule::Molecule(string name, int polarity, ExciteState state, string exciteStateName)
{
    this->name = name;
    this->polarity = polarity;
    this->state = state;
    this->exciteStateName = exciteStateName;

    this->ux = Matrix::Zero();
    this->uy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N = Matrix::Zero();
}

flowAnalysis::Molecule::~Molecule()
{
}