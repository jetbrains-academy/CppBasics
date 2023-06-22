#include <gtest/gtest.h>

#include "scene.hpp"
#include "operators.hpp"
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

std::string error_msg(Point2D p, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  newPosition = adjustToBorders(position)" << "\n";
    stream << "Test data:" << "\n"
           << "  position = " << p << "\n";
    stream << "Expected result:\n"
           << "  newPosition = " << expected << "\n";
    stream << "Actual result:\n"
           << "  newPosition = " << actual << "\n";
    return stream.str();
}

TEST(adjustToBordersTest, adjustToBordersTestNorth) {
    property_test(
        [] () {
            Point2D position = { genFloat(WEST_BORDER, EAST_BORDER), NORTH_BORDER };
            return position;
        },
        [] (Point2D position) {
            Point2D expected = { position.x, NORTH_BORDER + RADIUS };
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(position, expected, actual);
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
            Point2D expected = { position.x, SOUTH_BORDER - RADIUS };
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(position, expected, actual);
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
            Point2D expected = { WEST_BORDER + RADIUS, position.y };
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(position, expected, actual);
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
            Point2D expected = { EAST_BORDER - RADIUS, position.y };
            Point2D actual = adjustToBorders(position);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(position, expected, actual);
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
            ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(position, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(position, expected, actual);
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
            ASSERT_FLOAT_EQ(expected.x, actual.x) << error_msg(position, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << error_msg(position, expected, actual);
        }
    );
}