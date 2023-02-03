#include <gtest/gtest.h>

#include "scene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

std::string error_msg(Direction direction) {
    std::ostringstream stream;
    stream << "Incorrect vector for direction: "
           << directionToString(direction) << std::endl;
    return stream.str();
}

TEST(GetDirectionTest, GetDirectionNorth) {
    Point2D expected = { 0.0f, -1.0f };
    Point2D actual = getDirection(North);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(North);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(North);
}

TEST(GetDirectionTest, GetDirectionEast) {
    Point2D expected = { 1.0f,  0.0f };
    Point2D actual = getDirection(East);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(East);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(East);
}

TEST(GetDirectionTest, GetDirectionSouth) {
    Point2D expected = { 0.0f,  1.0f };
    Point2D actual = getDirection(South);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(South);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(South);;
}

TEST(GetDirectionTest, GetDirectionWest) {
    Point2D expected = { -1.0f,  0.0f };
    Point2D actual = getDirection(West);
    ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(West);
    ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(West);
}