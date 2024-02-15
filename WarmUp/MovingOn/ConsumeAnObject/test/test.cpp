#include <gtest/gtest.h>

#include <cmath>

#include "game.hpp"
#include "operators.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);


namespace expected {
    Point2D add(Point2D a, Point2D b) {
        Point2D c = { 0, 0 };
        c.x = a.x + b.x;
        c.y = a.y + b.y;
        return c;
    }

    float distance(Point2D a, Point2D b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool collision(Circle circle1, Circle circle2) {
        float dx = circle1.center.x - circle2.center.x;
        float dy = circle1.center.y - circle2.center.y;
        float distance = sqrt(dx * dx + dy * dy);
        return distance < circle1.radius + circle2.radius;
    }
}

const float MIN = -100;
const float MAX = 100;

std::string distance_error_msg(Point2D a, Point2D b, float expected, float actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  d = distance(a, b)" << "\n";
    stream << "Test data:" << "\n"
           << "  a = " << a << "\n"
           << "  b = " << b << "\n";
    stream << "Expected result:\n"
           << "  d = " << expected << "\n";
    stream << "Actual result:\n"
           << "  d = " << actual << "\n";
    return stream.str();
}

TEST(distanceTest, distanceTestRandom) {
    property_test(
        []() {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Point2D b = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            float expected = expected::distance(a, b);
            float actual = distance(a, b);
            ASSERT_FLOAT_EQ(expected, actual) << distance_error_msg(a, b, expected, actual);
        }
    );
}

std::string collision_error_msg(Circle circle1, Circle circle2, bool expected, bool actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  collide = collision(circle1, circle2)" << "\n";
    stream << "Test data:" << "\n"
           << "  circle1 = " << circle1 << "\n"
           << "  circle2 = " << circle2 << "\n";
    stream << "Expected result:\n"
           << "  collide = " << expected << "\n";
    stream << "Actual result:\n"
           << "  collide = " << actual << "\n";
    return stream.str();
}

TEST(collisionTest, collisionTestTrue) {
    property_test(
        [] () {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Circle c1 = { a, RADIUS };
            Point2D diff = { genFloat(0.0f, RADIUS / 4), genFloat(0.0f, RADIUS / 4) };
            Point2D b = expected::add(a, diff);
            Circle c2 = { b, c1.radius };
            return std::make_tuple(c1, c2);
        },
        [] (std::tuple<Circle, Circle> data) {
            Circle c1, c2;
            std::tie(c1, c2) = data;
            bool expected = true;
            bool actual = collision(c1, c2);
            ASSERT_FLOAT_EQ(expected, actual) << collision_error_msg(c1, c2, expected, actual);
        }
    );
}

TEST(collisionTest, collisionTestFalse) {
    property_test(
        [] () {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Circle c1 = { a, RADIUS };
            Point2D diff = { genFloat(4 * RADIUS, 16 * RADIUS), genFloat(4 * RADIUS, 16 * RADIUS) };
            Point2D b = expected::add(a, diff);
            Circle c2 = { b, c1.radius };
            return std::make_tuple(c1, c2);
        },
        [] (std::tuple<Circle, Circle> data) {
            Circle c1, c2;
            std::tie(c1, c2) = data;
            bool expected = false;
            bool actual = collision(c1, c2);
            ASSERT_FLOAT_EQ(expected, actual) << collision_error_msg(c1, c2, expected, actual);
        }
    );
}

TEST(collisionTest, collisionTestRandom) {
    property_test(
        [] () {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Circle c1 = { a, genFloat(0.0f, MAX / 2) };
            Point2D b = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Circle c2 = { b, genFloat(0.0f, MAX / 2) };
            return std::make_tuple(c1, c2);
        },
        [] (std::tuple<Circle, Circle> data) {
            Circle c1, c2;
            std::tie(c1, c2) = data;
            bool expected = expected::collision(c1, c2);
            bool actual = collision(c1, c2);
            ASSERT_FLOAT_EQ(expected, actual) << collision_error_msg(c1, c2, expected, actual);
        }
    );
}