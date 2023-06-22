#include <gtest/gtest.h>

#include "scene.hpp"
#include "operators.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e3;
const float MAX = 10e3;
const float DELTA = 0.5f;

TEST(generateCoordinateTest, generateCoordinateTestBounds) {
    property_test(
        [] () {
            return generateCoordinate(MIN, MAX);
        },
        [] (float coordinate) {
            ASSERT_GT(coordinate, MIN - DELTA) << "Generated value exceeds bounds.";
            ASSERT_LT(coordinate, MAX + DELTA) << "Generated value exceeds bounds.";
        }
    );
}

TEST(generateCoordinateTest, generateCoordinateTestRandomness) {
    randomness_test(
        [] () {
            return generateCoordinate(MIN, MAX);
        },
        [] (float a, float b) {
            return abs(a - b) < EPS;
        },
        [] (float a) {
            return std::to_string(a);
        }
    );
}

std::string error_msg(float radius, Circle circle) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  circle = generateCircle(" << radius << ")" << "\n";
    stream << "Generated result:" << "\n"
           << "  circle = " << circle << "\n";
    return stream.str();
}

TEST(generateCircleTest, generateCircleTestBounds) {
    property_test(
        []() {
            float radius = genFloat(0.0f, RADIUS * 2);
            Circle circle = generateCircle(radius);
            return std::make_tuple(radius, circle);
        },
        [] (std::tuple<float, Circle> data) {
            float radius;
            Circle circle;
            std::tie(radius, circle) = data;

            ASSERT_FLOAT_EQ(radius, circle.radius)
                << "Radius does not match requested value.\n" << error_msg(radius, circle);

            ASSERT_GT(circle.center.x - radius, WEST_BORDER + DELTA)
                << "Generated circle center exceeds bounds.\n" << error_msg(radius, circle);

            ASSERT_LT(circle.center.x + radius, EAST_BORDER - DELTA)
                << "Generated circle center exceeds bounds.\n" << error_msg(radius, circle);

            ASSERT_GT(circle.center.y - radius, NORTH_BORDER + DELTA)
                << "Generated circle center exceeds bounds.\n" << error_msg(radius, circle);

            ASSERT_LT(circle.center.y + radius, SOUTH_BORDER - DELTA)
                << "Generated circle center exceeds bounds.\n" << error_msg(radius, circle);
        }
    );
}

TEST(generateCircleTest, generateCircleTestRandomness) {
    randomness_test(
        []() {
            return generateCircle(RADIUS);
        },
        [](Circle a, Circle b) {
            return abs(  a.radius - b.radius  ) < EPS   &&
                   abs(a.center.x - b.center.x) < EPS   &&
                   abs(a.center.y - b.center.y) < EPS;
        },
        [](Circle c) {
            std::ostringstream stream;
            stream << c;
            return stream.str();
        }
    );
}