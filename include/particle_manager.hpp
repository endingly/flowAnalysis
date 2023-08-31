#pragma once
#include <map>
#include <string>
#include "particle.hpp"

namespace flowAnalysis
{

class particle_manager
{
  private:
    std::map<std::string, Atom> atom;
    std::map<std::string, Molecule> molecule;
    std::map<std::string, Ion> ion;                                  
    /* data */
  public:
    particle_manager();
    ~particle_manager();
};

} // namespace flowAnalysis
