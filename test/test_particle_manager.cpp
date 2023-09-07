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
    flowAnalysis::Atom atom("H", flowAnalysis::ExciteState::Ground,
                            "0");
    nlohmann::json     j = atom;
    std::cout << j.dump(4) << '\n';
}

TEST(particle_manager, to_json_file)
{
    auto pm = std::make_unique<flowAnalysis::particle_manager>();
    // atom
    auto C = std::make_unique<flowAnalysis::Atom>(
        "C", flowAnalysis::ExciteState::Ground, "0");
    C->D = 6.5E16;

    auto O = std::make_unique<flowAnalysis::Atom>(
        "O", flowAnalysis::ExciteState::Ground, "0");
    O->D = 6.5E16;

    // molecule
    auto O2 = std::make_unique<flowAnalysis::Molecule>(
        "O2", 0, flowAnalysis::ExciteState::Ground, "0");
    O2->D = 7.3E18;

    auto CO = std::make_unique<flowAnalysis::Molecule>(
        "CO", 0, flowAnalysis::ExciteState::Ground, "0");
    CO->D = 9.86E16;

    auto CO2 = std::make_unique<flowAnalysis::Molecule>(
        "CO2", 0, flowAnalysis::ExciteState::Ground, "0");
    CO2->D = 3.07E18;

    auto CO2V1 = std::make_unique<flowAnalysis::Molecule>(
        "CO2V1", -1, flowAnalysis::ExciteState::Ground, "0");
    CO2V1->D   = 3.07E18;
    auto CO2V2 = std::make_unique<flowAnalysis::Molecule>(
        "CO2V2", -2, flowAnalysis::ExciteState::Ground, "0");
    CO2V2->D   = 3.07E18;
    auto CO2V3 = std::make_unique<flowAnalysis::Molecule>(
        "CO2V3", -3, flowAnalysis::ExciteState::Ground, "0");
    CO2V3->D   = 3.07E18;
    auto CO2V4 = std::make_unique<flowAnalysis::Molecule>(
        "CO2V4", -4, flowAnalysis::ExciteState::Ground, "0");
    CO2V4->D = 3.07E18;

    auto ion = std::make_unique<flowAnalysis::Ion>("O2-", 1);

    pm->atom[C->name]  = std::move(*C);
    pm->atom[O->name]  = std::move(*O);
    pm->ion[ion->name] = std::move(*ion);

    pm->molecule[O2->name]    = std::move(*O2);
    pm->molecule[CO->name]    = std::move(*CO);
    pm->molecule[CO2->name]   = std::move(*CO2);
    pm->molecule[CO2V1->name] = std::move(*CO2V1);
    pm->molecule[CO2V2->name] = std::move(*CO2V2);
    pm->molecule[CO2V3->name] = std::move(*CO2V3);
    pm->molecule[CO2V4->name] = std::move(*CO2V4);

    nlohmann::json j = *pm;
    std::cout << j.dump(4) << '\n';

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
    std::cout << j.dump(4) << '\n';

    flowAnalysis::particle_manager pm = j;
}