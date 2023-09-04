#include "particle_manager.hpp"
#include <nlohmann/json.hpp>
#include <string>

using flowAnalysis::particle_manager;

particle_manager::particle_manager() = default;

particle_manager::~particle_manager() = default;

void flowAnalysis::to_json(nlohmann::json& j, const particle_manager& pm)
{
    j["atom"]     = pm.atom;
    j["molecule"] = pm.molecule;
    j["ion"]      = pm.ion;
}

void flowAnalysis::from_json(const nlohmann::json& j, particle_manager& pm)
{
    j.at("atom").get_to(pm.atom);
    j.at("molecule").get_to(pm.molecule);
    j.at("ion").get_to(pm.ion);
}