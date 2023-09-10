#include "log.hpp"
#include "particle_manager.hpp"
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main(int argc, char const* argv[])
{
    flowAnalysis::InitLogSystem();
    fs::path       p = fs::current_path() / "particle.json";
    std::ifstream  i(p);
    nlohmann::json j;
    i >> j;

    i.close();
    std::cout << j.dump(4) << '\n';

    auto pm = std::make_unique<flowAnalysis::particle_manager>();

    *pm = j;
    return 0;
}
