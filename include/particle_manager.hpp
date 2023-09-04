#pragma once
#include "particle.hpp"
#include <string>
#include <unordered_set>

namespace flowAnalysis
{

class particle_manager
{
  public:
    std::unordered_set<Atom>     atom;
    std::unordered_set<Molecule> molecule;
    std::unordered_set<Ion>      ion;

    particle_manager();
    ~particle_manager();
};

void to_json(nlohmann::json& j, const particle_manager& pm);
void from_json(const nlohmann::json& j, particle_manager& pm);

} // namespace flowAnalysis
