#include <iostream>
#include "log.hpp"


int main(int argc, char const *argv[])
{
    flowAnalysis::InitLogSystem();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
