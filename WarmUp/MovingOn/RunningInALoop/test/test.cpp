#include <gtest/gtest.h>

#include <cmath>

#include "game.hpp"
#include "operators.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

std::string error_msg(Circle player, Circle consumable, bool consumed, bool expected, bool actual) {
    std::ostringstream stream;
    stream << "Testing statement:\n"
           << "  collisionLoop(player, consumable, consumed, N)" << "\n";
    stream << "Test data:" << "\n"
           << "  player = " << player << "\n"
           << "  consumable[i] = " << consumable << "\n"
           << "  consumed[i] = " << consumed << "\n";
    stream << "Expected result:\n"
           << "  consumed[i] = " << expected << "\n";
    stream << "Actual result:\n"
           << "  consumed[i] = " << actual << "\n";
    return stream.str();
}

TEST(collisionLoopTest, collisionLoopTest) {
    Circle player = { {0.0f, 0.0f}, RADIUS };

    const int N_CIRCLES = 4;

    Circle circle1 = { { RADIUS / 2, RADIUS / 2 }, 2 * RADIUS };
    Circle circle2 = { { RADIUS / 4, -RADIUS / 4 }, RADIUS };
    Circle circle3 = { { EAST_BORDER, SOUTH_BORDER }, RADIUS };
    Circle circle4 = { { WEST_BORDER, NORTH_BORDER }, RADIUS };

    Circle consumable[N_CIRCLES] = {circle1, circle2, circle3, circle4 };
    bool consumed[N_CIRCLES] = { false, true, false, true };
    bool expected[N_CIRCLES] = { true, true, false, true };

    bool actual[N_CIRCLES];
    for (int i = 0; i < N_CIRCLES; ++i) {
        actual[i] = consumed[i];
    }
    collisionLoop(player, consumable, actual, N_CIRCLES);

    for (int i = 0; i < N_CIRCLES; ++i) {
        ASSERT_EQ(expected[i], actual[i]) << error_msg(player, consumable[i], consumed[i], expected[i], actual[i]);
    }
}