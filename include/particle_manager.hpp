#pragma once
#include "particle.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace flowAnalysis
{

class particle_manager
{
  public:
    std::unordered_map<std::string, Atom>     atom;
    std::unordered_map<std::string, Molecule> molecule;
    std::unordered_map<std::string, Ion>      ion;

    particle_manager();
    ~particle_manager();
};

} // namespace flowAnalysis

namespace nlohmann
{
template <>
struct adl_serializer<flowAnalysis::particle_manager>
{
    static void from_json(const json& j, flowAnalysis::particle_manager& p)
    {
        p.atom.clear();
        p.molecule.clear();
        p.ion.clear();

        for (const auto& item : j.at("atom").items())
        {
            auto v             = std::make_unique<flowAnalysis::Atom>();
            v->name            = item.value().at("name").get<std::string>();
            v->state           = item.value().at("state").get<flowAnalysis::ExciteState>();
            v->exciteStateName = item.value().at("exciteStateName").get<std::string>();
            v->D               = item.value().at("D").get<double>();
            p.atom[v->name]    = std::move(*v);
        }
        for (const auto& item : j.at("ion").items())
        {
            auto v         = std::make_unique<flowAnalysis::Ion>();
            v->name        = item.value().at("name").get<std::string>();
            v->polarity    = item.value().at("polarity").get<int>();
            v->D           = item.value().at("D").get<double>();
            p.ion[v->name] = std::move(*v);
        }
        for (const auto& item : j.at("molecule").items())
        {
            auto v              = std::make_unique<flowAnalysis::Molecule>();
            v->name             = item.value().at("name").get<std::string>();
            v->state            = item.value().at("state").get<flowAnalysis::ExciteState>();
            v->exciteStateName  = item.value().at("exciteStateName").get<std::string>();
            v->polarity         = item.value().at("polarity").get<int>();
            v->D                = item.value().at("D").get<double>();
            p.molecule[v->name] = std::move(*v);
        }
    }

    static void to_json(json& j, const flowAnalysis::particle_manager& p)
    {
        j = nlohmann::json{{"atom", p.atom}, {"molecule", p.molecule}, {"ion", p.ion}};
    }
};
} // namespace nlohmann
