#include <gtest/gtest.h>

#include <iostream>

#include "engine.hpp"

#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

TEST(EngineTest, CreateTest) {
    GameEngine* engine = GameEngine::create();

    ASSERT_TRUE(engine != nullptr)
        << "GameEngine::create() returns nullptr!";

    ASSERT_TRUE(engine == GameEngine::create())
        << "GameEngine::create() returns pointer to non-static memory!";

    ASSERT_TRUE(engine->isActive())
        << "GameEngine::create() returns pointer to a non-initialized engine object!";
}