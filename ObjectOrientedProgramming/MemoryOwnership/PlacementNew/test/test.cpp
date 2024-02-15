#include <gtest/gtest.h>

#include <cstddef>
#include <new>

#include "../include/animal.hpp"

Cat* createCat(char* memory);
void destroyCat(char* memory);

Mouse* createMouse(char* memory);
void destroyMouse(char* memory);

TEST(PlacementNew, PlacementNewTest) {
    size_t size = std::max(sizeof(Cat), sizeof(Mouse));
    char* memory = (char*) malloc(size);

    Cat* cat = createCat(memory);
    ASSERT_EQ("Tom", cat->getName());
    ASSERT_EQ("Tom", reinterpret_cast<Cat*>(memory)->getName());
    ASSERT_EQ(cat, reinterpret_cast<Cat*>(memory));
    ASSERT_EQ(1, Cat::getCounter());

    destroyCat(memory);
    ASSERT_EQ(0, Cat::getCounter());

    Mouse* mouse = createMouse(memory);
    ASSERT_EQ("Jerry", mouse->getName());
    ASSERT_EQ("Jerry", reinterpret_cast<Mouse*>(memory)->getName());
    ASSERT_EQ(mouse, reinterpret_cast<Mouse*>(memory));
    ASSERT_EQ(1, Mouse::getCounter());

    destroyMouse(memory);
    ASSERT_EQ(0, Mouse::getCounter());

    free(memory);
}