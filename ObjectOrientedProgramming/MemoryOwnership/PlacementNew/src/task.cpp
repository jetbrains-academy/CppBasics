#include <new>

#include "../include/animal.hpp"

Cat* createCat(char* memory) {
    return new (memory) Cat("Tom");
}

void destroyCat(char* memory) {
    reinterpret_cast<Cat*>(memory)->~Cat();
}

Mouse* createMouse(char* memory) {
    return new (memory) Mouse("Jerry");
}

void destroyMouse(char* memory) {
    reinterpret_cast<Mouse*>(memory)->~Mouse();
}