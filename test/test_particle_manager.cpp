#include "particle_manager.hpp"
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>

namespace fs = std::filesystem;

TEST(particle_manager, init)
{
    /// test default constructor
    flowAnalysis::particle_manager pm;
    flowAnalysis::Atom             atom("H", flowAnalysis::ExciteState::Ground, "0");
    nlohmann::json                 j = atom;
    std::cout << j.dump(4) << std::endl;
}

TEST(particle_manager, to_json_file)
{
    auto pm = std::make_unique<flowAnalysis::particle_manager>();
    // atom
    auto C = std::make_unique<flowAnalysis::Atom>("C", flowAnalysis::ExciteState::Ground, "0");
    auto O = std::make_unique<flowAnalysis::Atom>("O", flowAnalysis::ExciteState::Ground, "0");
    // molecule
    auto O2    = std::make_unique<flowAnalysis::Molecule>("O2", 0, flowAnalysis::ExciteState::Ground, "0");
    auto CO    = std::make_unique<flowAnalysis::Molecule>("CO", 0, flowAnalysis::ExciteState::Ground, "0");
    auto CO2   = std::make_unique<flowAnalysis::Molecule>("CO2", 0, flowAnalysis::ExciteState::Ground, "0");
    auto CO2V1 = std::make_unique<flowAnalysis::Molecule>("CO2V1", -1, flowAnalysis::ExciteState::Ground, "0");
    auto CO2V2 = std::make_unique<flowAnalysis::Molecule>("CO2V2", -2, flowAnalysis::ExciteState::Ground, "0");
    auto CO2V3 = std::make_unique<flowAnalysis::Molecule>("CO2V3", -3, flowAnalysis::ExciteState::Ground, "0");
    auto CO2V4 = std::make_unique<flowAnalysis::Molecule>("CO2V4", -4, flowAnalysis::ExciteState::Ground, "0");

    auto ion = std::make_unique<flowAnalysis::Ion>("O2-", 1);

    pm->atom.insert(std::move(*C));
    pm->atom.insert(std::move(*O));
    pm->ion.insert(std::move(*ion));
    pm->molecule.insert(std::move(*O2));
    pm->molecule.insert(std::move(*CO));
    pm->molecule.insert(std::move(*CO2));
    pm->molecule.insert(std::move(*CO2V1));
    pm->molecule.insert(std::move(*CO2V2));
    pm->molecule.insert(std::move(*CO2V3));
    pm->molecule.insert(std::move(*CO2V4));

    nlohmann::json j = *pm;
    std::cout << j.dump(4) << std::endl;

    fs::path      p = fs::current_path() / "particle.json";
    std::ofstream o(p);
    o << j.dump(4);
    o.close();
}

TEST(particle_manager, from_json_file)
{
    fs::path       p = fs::current_path() / "particle.json";
    std::ifstream  i(p);
    nlohmann::json j;
    i >> j;
    i.close();

    flowAnalysis::particle_manager pm = j;
    std::cout << pm.atom.size() << std::endl;
    std::cout << pm.ion.size() << std::endl;
    std::cout << pm.molecule.size() << std::endl;
}