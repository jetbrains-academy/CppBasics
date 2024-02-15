#include <gtest/gtest.h>

#include <cmath>

#include "game.hpp"
#include "operators.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

std::string error_msg(Circle player, Circle consumable, bool concerned, bool expected, bool actual) {
    std::ostringstream stream;
    stream << "Testing statement:\n"
           << "  approachingLoop(player, consumable, concerned, N)" << "\n";
    stream << "Test data:" << "\n"
           << "  player = " << player << "\n"
           << "  consumable[i] = " << consumable << "\n"
           << "  concerned[i] = " << concerned << "\n";
    stream << "Expected result:\n"
           << "  concerned[i] = " << expected << "\n";
    stream << "Actual result:\n"
           << "  concerned[i] = " << actual << "\n";
    return stream.str();
}

TEST(collisionLoopTest, collisionLoopTest) {
    Circle player = { {0.0f, 0.0f}, RADIUS };

    const int N_CIRCLES = 4;

    Circle circle1 = { { 3 * RADIUS, 3 * RADIUS }, 2 * RADIUS };
    Circle circle2 = { { 2 * RADIUS, -2 * RADIUS }, RADIUS / 2 };
    Circle circle3 = { { EAST_BORDER, SOUTH_BORDER }, RADIUS };
    Circle circle4 = { { 10 * RADIUS, 6 * RADIUS }, RADIUS / 4 };
    Circle circle5 = player;

    Circle consumable[N_CIRCLES + 1] = { circle1, circle2, circle3, circle4, circle5 };
    bool concerned[N_CIRCLES + 1] = { false, true, false, true, false };
    bool expected[N_CIRCLES + 1] = { true, true, false, false, false };

    bool actual[N_CIRCLES + 1];
    for (int i = 0; i < N_CIRCLES + 1; ++i) {
        actual[i] = concerned[i];
    }
    approachingLoop(player, consumable, actual, N_CIRCLES);

    for (int i = 0; i < N_CIRCLES; ++i) {
        ASSERT_EQ(expected[i], actual[i]) << error_msg(player, consumable[i], concerned[i], expected[i], actual[i]);
    }
    ASSERT_EQ(expected[N_CIRCLES], actual[N_CIRCLES])
        << "Testing statement:\n"
        << "  approachingLoop(player, consumable, concerned, N)" << "\n"
        << "Function attempted to modify elements of the array outside of its bounds.";
}