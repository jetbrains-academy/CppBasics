#include <gtest/gtest.h>

#include "game.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);


namespace expected {
    float move(float position, float velocity, float delta) {
        return position + (delta * velocity);
    }
}

const float MIN = -10e6;
const float MAX = 10e6;

std::string error_msg(float position, float velocity, float delta, float expected, float actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  newPosition = move(position, velocity, delta)" << "\n";
    stream << "Test data:" << "\n"
           << "  position = " << position << "\n"
           << "  velocity = " << velocity << "\n"
           << "  delta = "    << delta    << "\n";
    stream << "Expected result:\n"
           << "  newPosition = " << expected << "\n";
    stream << "Actual result:\n"
           << "  newPosition = " << actual << "\n";
    return stream.str();
}

TEST(MoveTest, MoveTestDelta0) {
    property_test(
        [] () {
            return std::make_tuple(genFloat(MIN, MAX), genFloat(MIN, MAX), 0.0f);
        },
        [] (std::tuple<float, float, float> data) {
            float position, velocity, delta;
            std::tie(position, velocity, delta) = data;
            float expected = position;
            float actual = move(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected, actual) << error_msg(position, velocity, delta, expected, actual);
        }
    );
}

TEST(MoveTest, MoveTestVelocity0) {
    property_test(
        [] () {
            return std::make_tuple(genFloat(MIN, MAX), 0.0f, genFloat(MIN, MAX));
        },
        [] (std::tuple<float, float, float> data) {
            float position, velocity, delta;
            std::tie(position, velocity, delta) = data;
            float expected = position;
            float actual = move(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected, actual) << error_msg(position, velocity, delta, expected, actual);
        }
    );
}

TEST(MoveTest, MoveTestRandom) {
    property_test(
        [] () {
            return std::make_tuple(genFloat(MIN, MAX), genFloat(MIN, MAX), genFloat(MIN, MAX));
        },
        [] (std::tuple<float, float, float> data) {
            float position, velocity, delta;
            std::tie(position, velocity, delta) = data;
            float expected = expected::move(position, velocity, delta);
            float actual = move(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected, actual) << error_msg(position, velocity, delta, expected, actual);
        }
    );
}
