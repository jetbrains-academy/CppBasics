#include <gtest/gtest.h>

#include <cmath>

#include "scene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e6;
const float MAX = 10e6;

std::string error_msg(Circle player, Circle consumable, bool consumed) {
    std::ostringstream stream;
    stream << "Test data:" << "\n"
           << "  player = { "
           << "{ " << player.center.x << ", " << player.center.y << " }, " << player.radius
           << " }" << "\n"
           << "  consumable = { "
           << "{ " << consumable.center.x << ", " << consumable.center.y << " }, " << consumable.radius
           << " }" << "\n"
           << "consumed " << consumed << "\n";
    return stream.str();
}

TEST(collisionLoopTest, collisionLoopTest) {
    Circle player = { {0.0f, 0.0f}, RADIUS };

    const int N_CIRCLES = 4;

    Circle circle1 = { {RADIUS / 2, RADIUS / 2}, 2 * RADIUS };
    Circle circle2 = { {RADIUS / 4, -RADIUS / 4}, RADIUS };
    Circle circle3 = {{EAST_BORDER, SOUTH_BORDER}, RADIUS };
    Circle circle4 = {{WEST_BORDER, NORTH_BORDER}, RADIUS };

    Circle consumable[N_CIRCLES] = {circle1, circle2, circle3, circle4 };
    bool consumed[N_CIRCLES] = { false, true, false, true };
    bool expected[N_CIRCLES] = { true, true, false, true };

    bool actual[N_CIRCLES];
    for (int i = 0; i < N_CIRCLES; ++i) {
        actual[i] = consumed[i];
    }
    collisionLoop(player, consumable, consumed, N_CIRCLES);

    for (int i = 0; i < N_CIRCLES; ++i) {
        ASSERT_EQ(expected[i], consumed[i]) << error_msg(player, consumable[i], consumed[i]);
    }
}