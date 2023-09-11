#include "particle.hpp"
#include "common_define.hpp"
#include <string>
#include <utility>

using std::string;
using namespace flowAnalysis;

Atom::Atom()
{
    this->name            = "";
    this->state           = ExciteState::Ground;
    this->exciteStateName = "";
    this->D               = 0;

    this->N  = Matrix::Zero(imax, jmax);
    this->Dx = Matrix::Zero(imax, jmax);
    this->Dy = Matrix::Zero(imax, jmax);
    this->Zx = Matrix::Zero(imax, jmax);
    this->Zy = Matrix::Zero(imax, jmax);
    this->Jx = Matrix::Zero(imax, jmax);
    this->Jy = Matrix::Zero(imax, jmax);

    this->G1x = Matrix::Zero(imax, jmax);
    this->G1y = Matrix::Zero(imax, jmax);
    this->G2x = Matrix::Zero(imax, jmax);
    this->G2y = Matrix::Zero(imax, jmax);
    this->H1x = Matrix::Zero(imax, jmax);
    this->H1y = Matrix::Zero(imax, jmax);
    this->LPx = Matrix::Zero(imax, jmax);
    this->LPy = Matrix::Zero(imax, jmax);
}

Atom::Atom(std::string name, ExciteState state, std::string exciteStateName)
{
    this->name            = std::move(name);
    this->state           = state;
    this->exciteStateName = std::move(exciteStateName);
    this->D               = 0;

    this->N  = Matrix::Zero(imax, jmax);
    this->Dx = Matrix::Zero(imax, jmax);
    this->Dy = Matrix::Zero(imax, jmax);
    this->Zx = Matrix::Zero(imax, jmax);
    this->Zy = Matrix::Zero(imax, jmax);
    this->Jx = Matrix::Zero(imax, jmax);
    this->Jy = Matrix::Zero(imax, jmax);

    this->G1x = Matrix::Zero(imax, jmax);
    this->G1y = Matrix::Zero(imax, jmax);
    this->G2x = Matrix::Zero(imax, jmax);
    this->G2y = Matrix::Zero(imax, jmax);
    this->H1x = Matrix::Zero(imax, jmax);
    this->H1y = Matrix::Zero(imax, jmax);
    this->LPx = Matrix::Zero(imax, jmax);
    this->LPy = Matrix::Zero(imax, jmax);
}

Atom::~Atom() = default;

Atom::Atom(const Atom& other)
{
    this->name            = other.name;
    this->state           = other.state;
    this->exciteStateName = other.exciteStateName;
    this->D               = other.D;

    this->N  = other.N;
    this->Dx = other.Dx;
    this->Dy = other.Dy;
    this->Zx = other.Zx;
    this->Zy = other.Zy;
    this->Jx = other.Jx;
    this->Jy = other.Jy;

    this->G1x = other.G1x;
    this->G1y = other.G1y;
    this->G2x = other.G2x;
    this->G2y = other.G2y;
    this->H1x = other.H1x;
    this->H1y = other.H1y;
    this->LPx = other.LPx;
    this->LPy = other.LPy;
}

Atom& Atom::operator=(const Atom& other)
{
    if (this == &other)
    {
        return *this;
    }
    this->name            = other.name;
    this->state           = other.state;
    this->exciteStateName = other.exciteStateName;
    this->D               = other.D;

    this->N  = other.N;
    this->Dx = other.Dx;
    this->Dy = other.Dy;
    this->Zx = other.Zx;
    this->Zy = other.Zy;
    this->Jx = other.Jx;
    this->Jy = other.Jy;

    this->G1x = other.G1x;
    this->G1y = other.G1y;
    this->G2x = other.G2x;
    this->G2y = other.G2y;
    this->H1x = other.H1x;
    this->H1y = other.H1y;
    this->LPx = other.LPx;
    this->LPy = other.LPy;
    return *this;
}

Atom::Atom(Atom&& other) noexcept
{
    this->name            = std::move(other.name);
    this->state           = other.state;
    this->exciteStateName = std::move(other.exciteStateName);
    this->D               = other.D;

    this->N  = std::move(other.N);
    this->Dx = std::move(other.Dx);
    this->Dy = std::move(other.Dy);
    this->Zx = std::move(other.Zx);
    this->Zy = std::move(other.Zy);
    this->Jx = std::move(other.Jx);
    this->Jy = std::move(other.Jy);

    this->G1x = std::move(other.G1x);
    this->G1y = std::move(other.G1y);
    this->G2x = std::move(other.G2x);
    this->G2y = std::move(other.G2y);
    this->H1x = std::move(other.H1x);
    this->H1y = std::move(other.H1y);
    this->LPx = std::move(other.LPx);
    this->LPy = std::move(other.LPy);
}

Atom& Atom::operator=(Atom&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    this->name            = std::move(other.name);
    this->state           = other.state;
    this->exciteStateName = std::move(other.exciteStateName);
    this->D               = other.D;

    this->N  = std::move(other.N);
    this->Dx = std::move(other.Dx);
    this->Dy = std::move(other.Dy);
    this->Zx = std::move(other.Zx);
    this->Zy = std::move(other.Zy);
    this->Jx = std::move(other.Jx);
    this->Jy = std::move(other.Jy);

    this->G1x = std::move(other.G1x);
    this->G1y = std::move(other.G1y);
    this->G2x = std::move(other.G2x);
    this->G2y = std::move(other.G2y);
    this->H1x = std::move(other.H1x);
    this->H1y = std::move(other.H1y);
    this->LPx = std::move(other.LPx);
    this->LPy = std::move(other.LPy);
    return *this;
}

Ion::Ion()
{
    this->name     = "";
    this->polarity = 0;
    this->D        = 0;

    this->ux  = Matrix::Zero(imax, jmax);
    this->uy  = Matrix::Zero(imax, jmax);
    this->Jx  = Matrix::Zero(imax, jmax);
    this->Jy  = Matrix::Zero(imax, jmax);
    this->Dx  = Matrix::Zero(imax, jmax);
    this->Dy  = Matrix::Zero(imax, jmax);
    this->Zx  = Matrix::Zero(imax, jmax);
    this->Zy  = Matrix::Zero(imax, jmax);
    this->Jdx = Matrix::Zero(imax, jmax);
    this->Jdy = Matrix::Zero(imax, jmax);
    this->N   = Matrix::Zero(imax, jmax);

    this->G1x = Matrix::Zero(imax, jmax);
    this->G1y = Matrix::Zero(imax, jmax);
    this->G2x = Matrix::Zero(imax, jmax);
    this->G2y = Matrix::Zero(imax, jmax);
    this->H1x = Matrix::Zero(imax, jmax);
    this->H1y = Matrix::Zero(imax, jmax);
    this->LPx = Matrix::Zero(imax, jmax);
    this->LPy = Matrix::Zero(imax, jmax);
}

Ion::Ion(string name, int polarity)
{
    this->name     = std::move(name);
    this->polarity = polarity;
    this->D        = 0;

    this->ux  = Matrix::Zero(imax, jmax);
    this->uy  = Matrix::Zero(imax, jmax);
    this->Jx  = Matrix::Zero(imax, jmax);
    this->Jy  = Matrix::Zero(imax, jmax);
    this->Dx  = Matrix::Zero(imax, jmax);
    this->Dy  = Matrix::Zero(imax, jmax);
    this->Zx  = Matrix::Zero(imax, jmax);
    this->Zy  = Matrix::Zero(imax, jmax);
    this->Jdx = Matrix::Zero(imax, jmax);
    this->Jdy = Matrix::Zero(imax, jmax);
    this->N   = Matrix::Zero(imax, jmax);

    this->G1x = Matrix::Zero(imax, jmax);
    this->G1y = Matrix::Zero(imax, jmax);
    this->G2x = Matrix::Zero(imax, jmax);
    this->G2y = Matrix::Zero(imax, jmax);
    this->H1x = Matrix::Zero(imax, jmax);
    this->H1y = Matrix::Zero(imax, jmax);
    this->LPx = Matrix::Zero(imax, jmax);
    this->LPy = Matrix::Zero(imax, jmax);
}

Ion::~Ion() = default;

Ion::Ion(const Ion& other)
{
    this->name     = other.name;
    this->polarity = other.polarity;
    this->D        = other.D;

    this->ux  = other.ux;
    this->uy  = other.uy;
    this->Jx  = other.Jx;
    this->Jy  = other.Jy;
    this->Dx  = other.Dx;
    this->Dy  = other.Dy;
    this->Zx  = other.Zx;
    this->Zy  = other.Zy;
    this->Jdx = other.Jdx;
    this->Jdy = other.Jdy;
    this->N   = other.N;

    this->G1x = other.G1x;
    this->G1y = other.G1y;
    this->G2x = other.G2x;
    this->G2y = other.G2y;
    this->H1x = other.H1x;
    this->H1y = other.H1y;
    this->LPx = other.LPx;
    this->LPy = other.LPy;
}

Ion& Ion::operator=(const Ion& other)
{
    if (this == &other)
    {
        return *this;
    }
    this->name     = other.name;
    this->polarity = other.polarity;
    this->D        = other.D;

    this->ux  = other.ux;
    this->uy  = other.uy;
    this->Jx  = other.Jx;
    this->Jy  = other.Jy;
    this->Dx  = other.Dx;
    this->Dy  = other.Dy;
    this->Zx  = other.Zx;
    this->Zy  = other.Zy;
    this->Jdx = other.Jdx;
    this->Jdy = other.Jdy;
    this->N   = other.N;

    this->G1x = other.G1x;
    this->G1y = other.G1y;
    this->G2x = other.G2x;
    this->G2y = other.G2y;
    this->H1x = other.H1x;
    this->H1y = other.H1y;
    this->LPx = other.LPx;
    this->LPy = other.LPy;

    return *this;
}

Ion::Ion(Ion&& other) noexcept
{
    this->name     = std::move(other.name);
    this->polarity = other.polarity;
    this->D        = other.D;

    this->ux  = std::move(other.ux);
    this->uy  = std::move(other.uy);
    this->Jx  = std::move(other.Jx);
    this->Jy  = std::move(other.Jy);
    this->Dx  = std::move(other.Dx);
    this->Dy  = std::move(other.Dy);
    this->Zx  = std::move(other.Zx);
    this->Zy  = std::move(other.Zy);
    this->Jdx = std::move(other.Jdx);
    this->Jdy = std::move(other.Jdy);
    this->N   = std::move(other.N);

    this->G1x = std::move(other.G1x);
    this->G1y = std::move(other.G1y);
    this->G2x = std::move(other.G2x);
    this->G2y = std::move(other.G2y);
    this->H1x = std::move(other.H1x);
    this->H1y = std::move(other.H1y);
    this->LPx = std::move(other.LPx);
    this->LPy = std::move(other.LPy);
}

Ion& Ion::operator=(Ion&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    this->name     = std::move(other.name);
    this->polarity = other.polarity;
    this->D        = other.D;

    this->ux  = std::move(other.ux);
    this->uy  = std::move(other.uy);
    this->Jx  = std::move(other.Jx);
    this->Jy  = std::move(other.Jy);
    this->Dx  = std::move(other.Dx);
    this->Dy  = std::move(other.Dy);
    this->Zx  = std::move(other.Zx);
    this->Zy  = std::move(other.Zy);
    this->Jdx = std::move(other.Jdx);
    this->Jdy = std::move(other.Jdy);
    this->N   = std::move(other.N);

    this->G1x = std::move(other.G1x);
    this->G1y = std::move(other.G1y);
    this->G2x = std::move(other.G2x);
    this->G2y = std::move(other.G2y);
    this->H1x = std::move(other.H1x);
    this->H1y = std::move(other.H1y);
    this->LPx = std::move(other.LPx);
    this->LPy = std::move(other.LPy);
    return *this;
}

Molecule::Molecule()
{
    this->name            = "";
    this->polarity        = 0;
    this->state           = ExciteState::Ground;
    this->exciteStateName = "";
    this->D               = 0;

    this->ux  = Matrix::Zero(imax, jmax);
    this->uy  = Matrix::Zero(imax, jmax);
    this->Jx  = Matrix::Zero(imax, jmax);
    this->Jy  = Matrix::Zero(imax, jmax);
    this->Dx  = Matrix::Zero(imax, jmax);
    this->Dy  = Matrix::Zero(imax, jmax);
    this->Zx  = Matrix::Zero(imax, jmax);
    this->Zy  = Matrix::Zero(imax, jmax);
    this->Jdx = Matrix::Zero(imax, jmax);
    this->Jdy = Matrix::Zero(imax, jmax);
    this->N   = Matrix::Zero(imax, jmax);

    this->G1x = Matrix::Zero(imax, jmax);
    this->G1y = Matrix::Zero(imax, jmax);
    this->G2x = Matrix::Zero(imax, jmax);
    this->G2y = Matrix::Zero(imax, jmax);
    this->H1x = Matrix::Zero(imax, jmax);
    this->H1y = Matrix::Zero(imax, jmax);
    this->LPx = Matrix::Zero(imax, jmax);
    this->LPy = Matrix::Zero(imax, jmax);
}

Molecule::Molecule(string name, int polarity, ExciteState state, string exciteStateName)
{
    this->name            = std::move(name);
    this->polarity        = polarity;
    this->state           = state;
    this->exciteStateName = std::move(exciteStateName);
    this->D               = 0;

    this->ux  = Matrix::Zero(imax, jmax);
    this->uy  = Matrix::Zero(imax, jmax);
    this->Jx  = Matrix::Zero(imax, jmax);
    this->Jy  = Matrix::Zero(imax, jmax);
    this->Dx  = Matrix::Zero(imax, jmax);
    this->Dy  = Matrix::Zero(imax, jmax);
    this->Zx  = Matrix::Zero(imax, jmax);
    this->Zy  = Matrix::Zero(imax, jmax);
    this->Jdx = Matrix::Zero(imax, jmax);
    this->Jdy = Matrix::Zero(imax, jmax);
    this->N   = Matrix::Zero(imax, jmax);

    this->G1x = Matrix::Zero(imax, jmax);
    this->G1y = Matrix::Zero(imax, jmax);
    this->G2x = Matrix::Zero(imax, jmax);
    this->G2y = Matrix::Zero(imax, jmax);
    this->H1x = Matrix::Zero(imax, jmax);
    this->H1y = Matrix::Zero(imax, jmax);
    this->LPx = Matrix::Zero(imax, jmax);
    this->LPy = Matrix::Zero(imax, jmax);
}

Molecule::~Molecule() = default;

Molecule::Molecule(const Molecule& other)
{
    this->name            = other.name;
    this->polarity        = other.polarity;
    this->state           = other.state;
    this->exciteStateName = other.exciteStateName;
    this->D               = other.D;

    this->ux  = other.ux;
    this->uy  = other.uy;
    this->Jx  = other.Jx;
    this->Jy  = other.Jy;
    this->Dx  = other.Dx;
    this->Dy  = other.Dy;
    this->Zx  = other.Zx;
    this->Zy  = other.Zy;
    this->Jdx = other.Jdx;
    this->Jdy = other.Jdy;
    this->N   = other.N;

    this->G1x = other.G1x;
    this->G1y = other.G1y;
    this->G2x = other.G2x;
    this->G2y = other.G2y;
    this->H1x = other.H1x;
    this->H1y = other.H1y;
    this->LPx = other.LPx;
    this->LPy = other.LPy;
}

Molecule& Molecule::operator=(const Molecule& other)
{
    if (this == &other)
    {
        return *this;
    }
    this->name            = other.name;
    this->polarity        = other.polarity;
    this->state           = other.state;
    this->exciteStateName = other.exciteStateName;
    this->D               = other.D;

    this->ux  = other.ux;
    this->uy  = other.uy;
    this->Jx  = other.Jx;
    this->Jy  = other.Jy;
    this->Dx  = other.Dx;
    this->Dy  = other.Dy;
    this->Zx  = other.Zx;
    this->Zy  = other.Zy;
    this->Jdx = other.Jdx;
    this->Jdy = other.Jdy;
    this->N   = other.N;

    this->G1x = other.G1x;
    this->G1y = other.G1y;
    this->G2x = other.G2x;
    this->G2y = other.G2y;
    this->H1x = other.H1x;
    this->H1y = other.H1y;
    this->LPx = other.LPx;
    this->LPy = other.LPy;
    return *this;
}

Molecule::Molecule(Molecule&& other) noexcept
{
    this->name            = std::move(other.name);
    this->polarity        = other.polarity;
    this->state           = other.state;
    this->exciteStateName = std::move(other.exciteStateName);
    this->D               = other.D;

    this->ux  = std::move(other.ux);
    this->uy  = std::move(other.uy);
    this->Jx  = std::move(other.Jx);
    this->Jy  = std::move(other.Jy);
    this->Dx  = std::move(other.Dx);
    this->Dy  = std::move(other.Dy);
    this->Zx  = std::move(other.Zx);
    this->Zy  = std::move(other.Zy);
    this->Jdx = std::move(other.Jdx);
    this->Jdy = std::move(other.Jdy);
    this->N   = std::move(other.N);

    this->G1x = std::move(other.G1x);
    this->G1y = std::move(other.G1y);
    this->G2x = std::move(other.G2x);
    this->G2y = std::move(other.G2y);
    this->H1x = std::move(other.H1x);
    this->H1y = std::move(other.H1y);
    this->LPx = std::move(other.LPx);
    this->LPy = std::move(other.LPy);
}

Molecule& Molecule::operator=(Molecule&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    this->name            = std::move(other.name);
    this->polarity        = other.polarity;
    this->state           = other.state;
    this->exciteStateName = std::move(other.exciteStateName);
    this->D               = other.D;

    this->ux  = std::move(other.ux);
    this->uy  = std::move(other.uy);
    this->Jx  = std::move(other.Jx);
    this->Jy  = std::move(other.Jy);
    this->Dx  = std::move(other.Dx);
    this->Dy  = std::move(other.Dy);
    this->Zx  = std::move(other.Zx);
    this->Zy  = std::move(other.Zy);
    this->Jdx = std::move(other.Jdx);
    this->Jdy = std::move(other.Jdy);
    this->N   = std::move(other.N);

    this->G1x = std::move(other.G1x);
    this->G1y = std::move(other.G1y);
    this->G2x = std::move(other.G2x);
    this->G2y = std::move(other.G2y);
    this->H1x = std::move(other.H1x);
    this->H1y = std::move(other.H1y);
    this->LPx = std::move(other.LPx);
    this->LPy = std::move(other.LPy);
    return *this;
}