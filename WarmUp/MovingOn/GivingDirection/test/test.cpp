#include <gtest/gtest.h>

#include "scene.hpp"
#include "operators.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

std::string error_msg(Direction direction, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  vector = getDirection(" << direction << ")" << "\n";
    stream << "Expected result:\n"
           << "  vector = " << expected << "\n";
    stream << "Actual result:\n"
           << "  vector = " << actual << "\n";
    return stream.str();
}

TEST(GetDirectionTest, GetDirectionNorth) {
    Point2D expected = { 0.0f, -1.0f };
    Point2D actual = getDirection(North);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(North, expected, actual);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(North, expected, actual);
}

TEST(GetDirectionTest, GetDirectionEast) {
    Point2D expected = { 1.0f,  0.0f };
    Point2D actual = getDirection(East);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(East, expected, actual);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(East, expected, actual);
}

TEST(GetDirectionTest, GetDirectionSouth) {
    Point2D expected = { 0.0f,  1.0f };
    Point2D actual = getDirection(South);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(South, expected, actual);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(South, expected, actual);
}

TEST(GetDirectionTest, GetDirectionWest) {
    Point2D expected = { -1.0f,  0.0f };
    Point2D actual = getDirection(West);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(West, expected, actual);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(West, expected, actual);
}