#include "particle.hpp"
#include <Parma.hpp>
#include <string>
using std::string;

flowAnalysis::Atom::Atom()
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

flowAnalysis::Atom::Atom(std::string name, ExciteState state, std::string exciteStateName)
{
    this->name            = name;
    this->state           = state;
    this->exciteStateName = exciteStateName;

    this->N  = Matrix::Zero();
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

size_t flowAnalysis::Atom::hash() const
{
    return std::hash<std::string>()(name) ^ std::hash<int>()((int)state) ^ std::hash<std::string>()(exciteStateName);
}

bool flowAnalysis::Atom::operator==(const Atom& other) const noexcept
{
    return this->name == other.name && this->state == other.state && this->exciteStateName == other.exciteStateName;
}

flowAnalysis::Ion::Ion()
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

flowAnalysis::Ion::Ion(string name, int polarity)
{
    this->name     = name;
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

flowAnalysis::Ion::~Ion()
{
}

size_t flowAnalysis::Ion::hash() const
{
    return std::hash<std::string>()(name) ^ std::hash<int>()(polarity);
}

bool flowAnalysis::Ion::operator==(const Ion& other) const noexcept
{
    return this->name == other.name && this->polarity == other.polarity;
}

flowAnalysis::Molecule::Molecule()
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

flowAnalysis::Molecule::Molecule(string name, int polarity, ExciteState state, string exciteStateName)
{
    this->name            = name;
    this->polarity        = polarity;
    this->state           = state;
    this->exciteStateName = exciteStateName;

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

flowAnalysis::Molecule::~Molecule()
{
}

void flowAnalysis::from_json(const nlohmann::json& j, Atom& p)
{
    p.name            = j.at("name").get<std::string>();
    p.state           = j.at("state").get<ExciteState>();
    p.exciteStateName = j.at("exciteStateName").get<std::string>();

    p.N  = Matrix::Zero();
    p.Dx = Matrix::Zero();
    p.Dy = Matrix::Zero();
    p.Zx = Matrix::Zero();
    p.Zy = Matrix::Zero();
    p.Jx = Matrix::Zero();
    p.Jy = Matrix::Zero();
}

void flowAnalysis::from_json(const nlohmann::json& j, Ion& p)
{
    p.name     = j.at("name").get<std::string>();
    p.polarity = j.at("polarity").get<int>();

    p.ux  = Matrix::Zero();
    p.uy  = Matrix::Zero();
    p.Jx  = Matrix::Zero();
    p.Jy  = Matrix::Zero();
    p.Dx  = Matrix::Zero();
    p.Dy  = Matrix::Zero();
    p.Zx  = Matrix::Zero();
    p.Zy  = Matrix::Zero();
    p.Jdx = Matrix::Zero();
    p.Jdy = Matrix::Zero();
    p.N   = Matrix::Zero();
}

void flowAnalysis::from_json(const nlohmann::json& j, Molecule& p)
{
    p.name            = j.at("name").get<std::string>();
    p.polarity        = j.at("polarity").get<int>();
    p.state           = j.at("state").get<ExciteState>();
    p.exciteStateName = j.at("exciteStateName").get<std::string>();

    p.ux  = Matrix::Zero();
    p.uy  = Matrix::Zero();
    p.Jx  = Matrix::Zero();
    p.Jy  = Matrix::Zero();
    p.Dx  = Matrix::Zero();
    p.Dy  = Matrix::Zero();
    p.Zx  = Matrix::Zero();
    p.Zy  = Matrix::Zero();
    p.Jdx = Matrix::Zero();
    p.Jdy = Matrix::Zero();
    p.N   = Matrix::Zero();
}

size_t flowAnalysis::Molecule::hash() const 
{
    return std::hash<std::string>()(name) ^ std::hash<int>()(polarity) ^ std::hash<int>()((int)state) ^ std::hash<std::string>()(exciteStateName);
}

bool flowAnalysis::Molecule::operator==(const Molecule& other) const noexcept
{
    return this->name == other.name && this->polarity == other.polarity && this->state == other.state && this->exciteStateName == other.exciteStateName;
}

/// clang-format off
void flowAnalysis::to_json(nlohmann::json& j, const Atom& p)
{
    j = nlohmann::json{{"name", p.name},
                       {"state", p.state},
                       {"exciteStateName", p.exciteStateName}};
}
void flowAnalysis::to_json(nlohmann::json& j, const Ion& p)
{
    j = nlohmann::json{{"name", p.name},
                       {"polarity", p.polarity}};
}
void flowAnalysis::to_json(nlohmann::json& j, const Molecule& p)
{
    j = nlohmann::json{{"name", p.name},
                       {"polarity", p.polarity},
                       {"state", p.state},
                       {"exciteStateName", p.exciteStateName}};
}
// clang-format on