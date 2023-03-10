#include <gtest/gtest.h>

#include "scene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);


namespace expected {
    Point2D adjustToBorders(Point2D position) {
        Point2D result = position;
        if (result.x - RADIUS < WEST_BORDER) {
            result.x = WEST_BORDER + RADIUS;
        }
        if (result.x + RADIUS > EAST_BORDER) {
            result.x = EAST_BORDER - RADIUS;
        }
        if (result.y - RADIUS < NORTH_BORDER) {
            result.y = NORTH_BORDER + RADIUS;
        }
        if (result.y + RADIUS > SOUTH_BORDER) {
            result.y = SOUTH_BORDER - RADIUS;
        }
        return result;
    }
}

std::string error_msg(Point2D p) {
    std::ostringstream stream;
    stream << "Test data:" << std::endl
           << "  position = { " << p.x << ", " << p.y << " }" << std::endl;
    return stream.str();
}

TEST(adjustToBordersTest, adjustToBordersTestNorth) {
    property_test(
        [] () {
            Point2D position = { genFloat(WEST_BORDER, EAST_BORDER), NORTH_BORDER };
            return position;
        },
        [] (Point2D position) {
            float expected = NORTH_BORDER + RADIUS;
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected, actual.y) << error_msg(position);
        }
    );
}

TEST(adjustToBordersTest, adjustToBordersTestSouth) {
    property_test(
        [] () {
            Point2D position = { genFloat(WEST_BORDER, EAST_BORDER), SOUTH_BORDER };
            return position;
        },
        [] (Point2D position) {
            float expected = SOUTH_BORDER - RADIUS;
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected, actual.y) << error_msg(position);
        }
    );
}

TEST(adjustToBordersTest, adjustToBordersTestEast) {
    property_test(
        [] () {
            Point2D position = { WEST_BORDER, genFloat(NORTH_BORDER, SOUTH_BORDER) };
            return position;
        },
        [] (Point2D position) {
            float expected = WEST_BORDER + RADIUS;
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected, actual.x) << error_msg(position);
        }
    );
}

TEST(adjustToBordersTest, adjustToBordersTestWest) {
    property_test(
        [] () {
            Point2D position = { EAST_BORDER, genFloat(NORTH_BORDER, SOUTH_BORDER) };
            return position;
        },
        [] (Point2D position) {
            float expected = EAST_BORDER - RADIUS;
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected, actual.x) << error_msg(position);
        }
    );
}

TEST(adjustToBordersTest, adjustToBordersTestId) {
    property_test(
        [] () {
            Point2D position = { genFloat(WEST_BORDER + 4 * RADIUS, EAST_BORDER - 4 * RADIUS),
                                 genFloat(NORTH_BORDER + 4 * RADIUS, SOUTH_BORDER - 4 * RADIUS) };
            return position;
        },
        [] (Point2D position) {
            Point2D expected = position;
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(position);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(position);
        }
    );
}

TEST(adjustToBordersTest, adjustToBordersTestRandom) {
    property_test(
        [] () {
            Point2D position = { genFloat(WEST_BORDER, EAST_BORDER), genFloat(NORTH_BORDER, SOUTH_BORDER) };
            return position;
        },
        [] (Point2D position) {
            Point2D expected = expected::adjustToBorders(position);
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(position);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(position);
        }
    );
}