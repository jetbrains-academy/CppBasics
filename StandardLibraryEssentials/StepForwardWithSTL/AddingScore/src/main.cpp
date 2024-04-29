#include "engine.hpp"

#include <iostream>

int main() {
    GameEngine* engine = GameEngine::create();
    if (!engine) {
        std::cout << "Game engine is not created!\n";
        return 1;
    }
    GameEngine::create()->run();
    return 0;
}