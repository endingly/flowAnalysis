#include "particle.hpp"
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
    auto a  = std::make_unique<flowAnalysis::Atom>("H", flowAnalysis::ExciteState::Ground, "0");
    auto i  = std::make_unique<flowAnalysis::Ion>("H+", 1);
    auto m  = std::make_unique<flowAnalysis::Molecule>("H2", 0, flowAnalysis::ExciteState::Ground, "0");
    pm->atom.insert(std::move(*a));
    pm->ion.insert(std::move(*i));
    pm->molecule.insert(std::move(*m));

    nlohmann::json j = *pm;
    std::cout << j.dump(4) << std::endl;

    fs::path p = fs::current_path() / "particle.json";
    std::ofstream o(p);
    o << j.dump(4);
    o.close();
}

TEST(particle_manager, from_json_file)
{
    fs::path p = fs::current_path() / "particle.json";
    std::ifstream i(p);
    nlohmann::json j;
    i >> j;
    i.close();

    flowAnalysis::particle_manager pm = j;
    std::cout << pm.atom.size() << std::endl;
    std::cout << pm.ion.size() << std::endl;
    std::cout << pm.molecule.size() << std::endl;
}