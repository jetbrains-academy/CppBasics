#include <gtest/gtest.h>

#include "operators.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e3;
const float MAX = 10e3;

const Rectangle generateArea = { { MIN, MIN }, { MAX, MAX } };

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

std::string point_plus_error_msg(Point2D a, Point2D b, Point2D expected, Point2D actual) {
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

TEST(PointPlusTest, PointPlusTest) {
    property_test(
        [] () {
            Point2D a = generatePoint(generateArea);
            Point2D b = generatePoint(generateArea);
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            Point2D expected = expected::add(a, b);
            Point2D actual = a + b;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << point_plus_error_msg(a, b, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << point_plus_error_msg(a, b, expected, actual);
        }
    );
}

std::string point_unary_minus_error_msg(Point2D a, Point2D expected, Point2D actual) {
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

TEST(PointUnaryMinusTest, PointUnaryMinusTest) {
    property_test(
        [] () {
            Point2D a = generatePoint(generateArea);
            return a;
        },
        [] (Point2D a) {
            Point2D expected = { -a.x, -a.y };
            Point2D actual = -a;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << point_unary_minus_error_msg(a, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << point_unary_minus_error_msg(a, expected, actual);
        }
    );
}

std::string point_minus_error_msg(Point2D a, Point2D b, Point2D expected, Point2D actual) {
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

TEST(PointMinusTest, PointMinusTest) {
    property_test(
        [] () {
            Point2D a = generatePoint(generateArea);
            Point2D b = generatePoint(generateArea);
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            Point2D expected = expected::add(a, { -b.x, -b.y });
            Point2D actual = a - b;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << point_minus_error_msg(a, b, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << point_minus_error_msg(a, b, expected, actual);
        }
    );
}

std::string point_scalar_mul_error_msg(float s, Point2D a, Point2D expected, Point2D actual) {
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
            float s = generateFloat(MIN, MAX);
            Point2D a = generatePoint(generateArea);
            return std::make_tuple(s, a);
        },
        [] (std::tuple<float, Point2D> data) {
            float s;
            Point2D a;
            std::tie(s, a) = data;
            Point2D expected = expected::mul(s, a);
            Point2D actual = s * a;
            ASSERT_FLOAT_EQ(expected.x, actual.x) << point_scalar_mul_error_msg(s, a, expected, actual);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << point_scalar_mul_error_msg(s, a, expected, actual);
        }
    );
}

std::string circle_plus_error_msg(Circle c, Point2D v, Circle expected, Circle actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  c' = c + v" << "\n";
    stream << "Test data:\n"
        << "  c = " << c << "\n"
        << "  v = " << v << "\n";
    stream << "Expected result:\n"
        << "  c' = " << expected << "\n";
    stream << "Actual result:\n"
        << "  c' = " << actual << "\n";
    return stream.str();
}

TEST(CirclePlusTest, CirclePlusTest) {
    property_test(
        [] () {
            Circle c = generateCircle(generateFloat(MIN, MAX), generateArea);
            Point2D v = generatePoint(generateArea);
            return std::make_tuple(c, v);
        },
        [] (std::tuple<Circle, Point2D> data) {
            Circle c;
            Point2D v;
            std::tie(c, v) = data;
            Circle expected = Circle { expected::add(c.center, v) , c.radius };
            Circle actual = c + v;
            ASSERT_FLOAT_EQ(expected.center.x, actual.center.x) << circle_plus_error_msg(c, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.center.y, actual.center.y) << circle_plus_error_msg(c, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.radius, actual.radius) << circle_plus_error_msg(c, v, expected, actual);
        }
    );
}

std::string circle_minus_error_msg(Circle c, Point2D v, Circle expected, Circle actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  c' = c - v" << "\n";
    stream << "Test data:\n"
        << "  c = " << c << "\n"
        << "  v = " << v << "\n";
    stream << "Expected result:\n"
        << "  c' = " << expected << "\n";
    stream << "Actual result:\n"
        << "  c' = " << actual << "\n";
    return stream.str();
}

TEST(CircleMinusTest, CircleMinusTest) {
    property_test(
        [] () {
            Circle c = generateCircle(generateFloat(MIN, MAX), generateArea);
            Point2D v = generatePoint(generateArea);
            return std::make_tuple(c, v);
        },
        [] (std::tuple<Circle, Point2D> data) {
            Circle c;
            Point2D v;
            std::tie(c, v) = data;
            Circle expected = Circle { expected::add(c.center, Point2D { -v.x, -v.y }) , c.radius };
            Circle actual = c - v;
            ASSERT_FLOAT_EQ(expected.center.x, actual.center.x) << circle_minus_error_msg(c, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.center.y, actual.center.y) << circle_minus_error_msg(c, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.radius, actual.radius) << circle_minus_error_msg(c, v, expected, actual);
        }
    );
}

std::string rectangle_plus_error_msg(Rectangle r, Point2D v, Rectangle expected, Rectangle actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  r' = r + v" << "\n";
    stream << "Test data:\n"
        << "  r = " << r << "\n"
        << "  v = " << v << "\n";
    stream << "Expected result:\n"
        << "  r' = " << expected << "\n";
    stream << "Actual result:\n"
        << "  r' = " << actual << "\n";
    return stream.str();
}

TEST(RectanglePlusTest, RectanglePlusTest) {
    property_test(
        [] () {
            Rectangle r = generateRectangle(generateArea);
            Point2D v = generatePoint(generateArea);
            return std::make_tuple(r, v);
        },
        [] (std::tuple<Rectangle, Point2D> data) {
            Rectangle r;
            Point2D v;
            std::tie(r, v) = data;
            Rectangle expected = Rectangle {
                expected::add(r.topLeft, v),
                expected::add(r.botRight, v)
            };
            Rectangle actual = r + v;
            ASSERT_FLOAT_EQ(expected.topLeft.x, actual.topLeft.x) << rectangle_plus_error_msg(r, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.topLeft.y, actual.topLeft.y) << rectangle_plus_error_msg(r, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.botRight.x, actual.botRight.x) << rectangle_plus_error_msg(r, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.botRight.y, actual.botRight.y) << rectangle_plus_error_msg(r, v, expected, actual);
        }
    );
}

std::string rectangle_minus_error_msg(Rectangle r, Point2D v, Rectangle expected, Rectangle actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  r' = r - v" << "\n";
    stream << "Test data:\n"
        << "  r = " << r << "\n"
        << "  v = " << v << "\n";
    stream << "Expected result:\n"
        << "  r' = " << expected << "\n";
    stream << "Actual result:\n"
        << "  r' = " << actual << "\n";
    return stream.str();
}

TEST(RectangleMinusTest, RectangleMinusTest) {
    property_test(
        [] () {
            Rectangle r = generateRectangle(generateArea);
            Point2D v = generatePoint(generateArea);
            return std::make_tuple(r, v);
        },
        [] (std::tuple<Rectangle, Point2D> data) {
            Rectangle r;
            Point2D v;
            std::tie(r, v) = data;
            Rectangle expected = Rectangle {
                expected::add(r.topLeft, { -v.x, -v.y }),
                expected::add(r.botRight, { -v.x, -v.y })
            };
            Rectangle actual = r - v;
            ASSERT_FLOAT_EQ(expected.topLeft.x, actual.topLeft.x) << rectangle_minus_error_msg(r, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.topLeft.y, actual.topLeft.y) << rectangle_minus_error_msg(r, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.botRight.x, actual.botRight.x) << rectangle_minus_error_msg(r, v, expected, actual);
            ASSERT_FLOAT_EQ(expected.botRight.y, actual.botRight.y) << rectangle_minus_error_msg(r, v, expected, actual);
        }
    );
}

std::string circle_scalar_mul_error_msg(float s, Circle c, Circle expected, Circle actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  c' = s * c" << "\n";
    stream << "Test data:\n"
        << "  s = " << s << "\n"
        << "  c = " << c << "\n";
    stream << "Expected result:\n"
        << "  c' = " << expected << "\n";
    stream << "Actual result:\n"
        << "  c' = " << actual << "\n";
    return stream.str();
}

TEST(CircleMulTest, CircleMulTest) {
    property_test(
        [] () {
            float s = generateFloat(MIN, MAX);
            Circle c = generateCircle(generateFloat(MIN, MAX), generateArea);
            return std::make_tuple(s, c);
        },
        [] (std::tuple<float, Circle> data) {
            float s;
            Circle c;
            std::tie(s, c) = data;
            Circle expected = Circle { c.center, s * c.radius };
            Circle actual = s * c;
            ASSERT_FLOAT_EQ(expected.center.x, actual.center.x) << circle_scalar_mul_error_msg(s, c, expected, actual);
            ASSERT_FLOAT_EQ(expected.center.y, actual.center.y) << circle_scalar_mul_error_msg(s, c, expected, actual);
            ASSERT_FLOAT_EQ(expected.radius, actual.radius) << circle_scalar_mul_error_msg(s, c, expected, actual);
        }
    );
}

std::string rectangle_scalar_mul_error_msg(float s, Rectangle r, Rectangle expected, Rectangle actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  r' = s * r" << "\n";
    stream << "Test data:\n"
        << "  s = " << s << "\n"
        << "  r = " << r << "\n";
    stream << "Expected result:\n"
        << "  r' = " << expected << "\n";
    stream << "Actual result:\n"
        << "  r' = " << actual << "\n";
    return stream.str();
}

TEST(RectangleScalarMulTest, RectangleScalarMulTest) {
    property_test(
        [] () {
            float s = generateFloat(MIN, MAX);
            Rectangle r = generateRectangle(generateArea);
            return std::make_tuple(s, r);
        },
        [] (std::tuple<float, Rectangle> data) {
            float s;
            Rectangle r;
            std::tie(s, r) = data;
            Rectangle expected = Rectangle {
                r.topLeft,
                expected::add(r.topLeft, expected::mul(s, { width(r), height(r) }))
            };
            Rectangle actual = s * r;
            ASSERT_FLOAT_EQ(expected.topLeft.x, actual.topLeft.x) << rectangle_scalar_mul_error_msg(s, r, expected, actual);
            ASSERT_FLOAT_EQ(expected.topLeft.y, actual.topLeft.y) << rectangle_scalar_mul_error_msg(s, r, expected, actual);
            ASSERT_FLOAT_EQ(expected.botRight.x, actual.botRight.x) << rectangle_scalar_mul_error_msg(s, r, expected, actual);
            ASSERT_FLOAT_EQ(expected.botRight.y, actual.botRight.y) << rectangle_scalar_mul_error_msg(s, r, expected, actual);
        }
    );
}