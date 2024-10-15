#include "engine.hpp"

#include <iostream>
#include <unistd.h>
#include <limits.h>

int main() {
    GameEngine* engine = GameEngine::create();
    if (!engine) {
        std::cout << "Game engine is not created!\n";
        return 1;
    }
    // print current working directory
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "Error getting current working directory" << std::endl;
    }

    GameEngine::create()->run();
    return 0;
}