#include <gtest/gtest.h>

#include "operators.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e3;
const float MAX = 10e3;

namespace expected {
    Point2D add(Point2D a, Point2D b) {
        Point2D c = { 0, 0 };
        c.x = a.x + b.x;
        c.y = a.y + b.y;
        return c;
    }

    Point2D mul(float s, Point2D a) {
        Point2D b = { 0, 0 };
        b.x = s * a.x;
        b.y = s * a.y;
        return b;
    }
}

std::string plus_error_msg(Point2D a, Point2D b, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  c = a + b" << "\n";
    stream << "Test data:\n"
           << "  a = " << a << "\n"
           << "  b = " << b << "\n";
    stream << "Expected result:\n"
           << "  c = " << expected << "\n";
    stream << "Actual result:\n"
           << "  c = " << actual << "\n";
    return stream.str();
}

TEST(PlusTest, PlusTest) {
    property_test(
        [] () {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Point2D b = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            Point2D expected = expected::add(a, b);
            Point2D actual = a + b;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << plus_error_msg(a, b, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << plus_error_msg(a, b, expected, actual);
        }
    );
}

std::string unary_minus_error_msg(Point2D a, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  b = -a" << "\n";
    stream << "Test data:\n"
           << "  a = " << a << "\n";
    stream << "Expected result:\n"
           << "  b = " << expected << "\n";
    stream << "Actual result:\n"
           << "  b = " << actual << "\n";
    return stream.str();
}

TEST(UnaryMinusTest, UnaryMinusTest) {
    property_test(
        [] () {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return a;
        },
        [] (Point2D a) {
            Point2D expected = { -a.x, -a.y };
            Point2D actual = -a;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << unary_minus_error_msg(a, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << unary_minus_error_msg(a, expected, actual);
        }
    );
}

std::string minus_error_msg(Point2D a, Point2D b, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  c = a - b" << "\n";
    stream << "Test data:\n"
           << "  a = " << a << "\n"
           << "  b = " << b << "\n";
    stream << "Expected result:\n"
           << "  c = " << expected << "\n";
    stream << "Actual result:\n"
           << "  c = " << actual << "\n";
    return stream.str();
}

TEST(MinusTest, MinusTest) {
    property_test(
        [] () {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Point2D b = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            Point2D expected = expected::add(a, { -b.x, -b.y });
            Point2D actual = a - b;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << minus_error_msg(a, b, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << minus_error_msg(a, b, expected, actual);
        }
    );
}

std::string scalar_mul_error_msg(float s, Point2D a, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  c = s * a" << "\n";
    stream << "Test data:\n"
           << "  s = " << s << "\n"
           << "  a = " << a << "\n";
    stream << "Expected result:\n"
           << "  c = " << expected << "\n";
    stream << "Actual result:\n"
           << "  c = " << actual << "\n";
    return stream.str();
}

TEST(ScalarProdTest, ScalarProdTest) {
    property_test(
        [] () {
            float s = genFloat(MIN, MAX);
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return std::make_tuple(s, a);
        },
        [] (std::tuple<float, Point2D> data) {
            float s;
            Point2D a;
            std::tie(s, a) = data;
            Point2D expected = expected::mul(s, a);
            Point2D actual = s * a;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << scalar_mul_error_msg(s, a, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << scalar_mul_error_msg(s, a, expected, actual);
        }
    );
}