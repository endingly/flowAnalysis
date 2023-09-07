#include "particle.hpp"
#include <string>
#include <utility>

using std::string;
using namespace flowAnalysis;

Atom::Atom()
{
    this->name            = "";
    this->state           = ExciteState::Ground;
    this->exciteStateName = "";

    this->N  = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
}

Atom::Atom(std::string name, ExciteState state,
           std::string exciteStateName)
{
    this->name            = std::move(name);
    this->state           = state;
    this->exciteStateName = std::move(exciteStateName);

    this->N  = Matrix::Zero();
    this->Dx = Matrix::Zero();
    this->Dy = Matrix::Zero();
    this->Zx = Matrix::Zero();
    this->Zy = Matrix::Zero();
    this->Jx = Matrix::Zero();
    this->Jy = Matrix::Zero();
}

Atom::~Atom() = default;

size_t Atom::hash() const
{
    return std::hash<std::string>()(name) ^
           std::hash<int>()((int)state) ^
           std::hash<std::string>()(exciteStateName);
}

bool Atom::operator==(const Atom& other) const noexcept
{
    return this->name == other.name && this->state == other.state &&
           this->exciteStateName == other.exciteStateName;
}

Atom::Atom(const Atom& other)
{
    this->name            = other.name;
    this->state           = other.state;
    this->exciteStateName = other.exciteStateName;

    this->N  = other.N;
    this->Dx = other.Dx;
    this->Dy = other.Dy;
    this->Zx = other.Zx;
    this->Zy = other.Zy;
    this->Jx = other.Jx;
    this->Jy = other.Jy;
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

    this->N  = other.N;
    this->Dx = other.Dx;
    this->Dy = other.Dy;
    this->Zx = other.Zx;
    this->Zy = other.Zy;
    this->Jx = other.Jx;
    this->Jy = other.Jy;
    return *this;
}

Atom::Atom(Atom&& other) noexcept
{
    this->name            = std::move(other.name);
    this->state           = other.state;
    this->exciteStateName = std::move(other.exciteStateName);

    this->N  = std::move(other.N);
    this->Dx = std::move(other.Dx);
    this->Dy = std::move(other.Dy);
    this->Zx = std::move(other.Zx);
    this->Zy = std::move(other.Zy);
    this->Jx = std::move(other.Jx);
    this->Jy = std::move(other.Jy);
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

    this->N  = std::move(other.N);
    this->Dx = std::move(other.Dx);
    this->Dy = std::move(other.Dy);
    this->Zx = std::move(other.Zx);
    this->Zy = std::move(other.Zy);
    this->Jx = std::move(other.Jx);
    this->Jy = std::move(other.Jy);
    return *this;
}

Ion::Ion()
{
    this->name     = "";
    this->polarity = 0;

    this->ux  = Matrix::Zero();
    this->uy  = Matrix::Zero();
    this->Jx  = Matrix::Zero();
    this->Jy  = Matrix::Zero();
    this->Dx  = Matrix::Zero();
    this->Dy  = Matrix::Zero();
    this->Zx  = Matrix::Zero();
    this->Zy  = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N   = Matrix::Zero();
}

Ion::Ion(string name, int polarity)
{
    this->name     = std::move(name);
    this->polarity = polarity;

    this->ux  = Matrix::Zero();
    this->uy  = Matrix::Zero();
    this->Jx  = Matrix::Zero();
    this->Jy  = Matrix::Zero();
    this->Dx  = Matrix::Zero();
    this->Dy  = Matrix::Zero();
    this->Zx  = Matrix::Zero();
    this->Zy  = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N   = Matrix::Zero();
}

Ion::~Ion() = default;

size_t Ion::hash() const
{
    return std::hash<std::string>()(name) ^
           std::hash<int>()(polarity);
}

bool Ion::operator==(const Ion& other) const noexcept
{
    return this->name == other.name &&
           this->polarity == other.polarity;
}

Ion::Ion(const Ion& other)
{
    this->name     = other.name;
    this->polarity = other.polarity;

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
}

Ion& Ion::operator=(const Ion& other)
{
    if (this == &other)
    {
        return *this;
    }
    this->name     = other.name;
    this->polarity = other.polarity;

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
    return *this;
}

Ion::Ion(Ion&& other) noexcept
{
    this->name     = std::move(other.name);
    this->polarity = other.polarity;

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
}

Ion& Ion::operator=(Ion&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    this->name     = std::move(other.name);
    this->polarity = other.polarity;

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
    return *this;
}

Molecule::Molecule()
{
    this->name            = "";
    this->polarity        = 0;
    this->state           = ExciteState::Ground;
    this->exciteStateName = "";

    this->ux  = Matrix::Zero();
    this->uy  = Matrix::Zero();
    this->Jx  = Matrix::Zero();
    this->Jy  = Matrix::Zero();
    this->Dx  = Matrix::Zero();
    this->Dy  = Matrix::Zero();
    this->Zx  = Matrix::Zero();
    this->Zy  = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N   = Matrix::Zero();
}

Molecule::Molecule(string name, int polarity, ExciteState state,
                   string exciteStateName)
{
    this->name            = std::move(name);
    this->polarity        = polarity;
    this->state           = state;
    this->exciteStateName = std::move(exciteStateName);

    this->ux  = Matrix::Zero();
    this->uy  = Matrix::Zero();
    this->Jx  = Matrix::Zero();
    this->Jy  = Matrix::Zero();
    this->Dx  = Matrix::Zero();
    this->Dy  = Matrix::Zero();
    this->Zx  = Matrix::Zero();
    this->Zy  = Matrix::Zero();
    this->Jdx = Matrix::Zero();
    this->Jdy = Matrix::Zero();
    this->N   = Matrix::Zero();
}

Molecule::~Molecule() = default;

size_t Molecule::hash() const
{
    return std::hash<std::string>()(name) ^
           std::hash<int>()(polarity) ^ std::hash<int>()((int)state) ^
           std::hash<std::string>()(exciteStateName);
}

bool Molecule::operator==(const Molecule& other) const noexcept
{
    return this->name == other.name &&
           this->polarity == other.polarity &&
           this->state == other.state &&
           this->exciteStateName == other.exciteStateName;
}

Molecule::Molecule(const Molecule& other)
{
    this->name            = other.name;
    this->polarity        = other.polarity;
    this->state           = other.state;
    this->exciteStateName = other.exciteStateName;

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
    return *this;
}

Molecule::Molecule(Molecule&& other) noexcept
{
    this->name            = std::move(other.name);
    this->polarity        = other.polarity;
    this->state           = other.state;
    this->exciteStateName = std::move(other.exciteStateName);

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
    return *this;
}