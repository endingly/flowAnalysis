#include "particle_manager.hpp"
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

namespace fs = std::filesystem;

flowAnalysis::particle_manager::particle_manager()
{
    fs::path p = fs::current_path().append("input").append("particle.json");
    std::ifstream i(p.string().c_str());
    nlohmann::json j;
    i >> j;
    for (auto &element : j["atom"])
    {
        std::string name = element["name"];
        ExciteState state = element["state"];
        std::string exciteStateName = element["exciteStateName"];
        atom[name] = Atom(name, state, exciteStateName);
    }
    for (auto &element : j["molecule"])
    {
        std::string name = element["name"];
        int polarity = element["polarity"];
        ExciteState state = element["state"];
        std::string exciteStateName = element["exciteStateName"];
        molecule[name] = Molecule(name, polarity, state, exciteStateName);
    }
    for (auto &element : j["Ion"])
    {
        std::string name = element["name"];
        int polarity = element["polarity"];
        ion[name] = Ion(name, polarity);
    }
}

flowAnalysis::particle_manager::~particle_manager()
{
}