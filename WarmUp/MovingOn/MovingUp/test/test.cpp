#include <gtest/gtest.h>

#include "scene.hpp"
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

    Point2D mul(float s, Point2D a) {
        Point2D b = { 0, 0 };
        b.x = s * a.x;
        b.y = s * a.y;
        return b;
    }

    Point2D move(Point2D position, Point2D velocity, float delta) {
        return expected::add(position, expected::mul(delta, velocity));
    }
}

const float MIN = -10e6;
const float MAX = 10e6;

std::string add_error_msg(Point2D a, Point2D b) {
    std::ostringstream stream;
    stream << "Test data:" << std::endl
           << "  a = { " << a.x << ", " << a.y << " }" << std::endl
           << "  b = { " << b.x << ", " << b.y << " }" << std::endl;
    return stream.str();
}

TEST(AddTest, AddTestA0) {
    property_test(
        [] () {
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Point2D b = { 0.0f, 0.0f };
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            Point2D expected = a;
            Point2D actual = add(a, b);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << add_error_msg(a, b);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << add_error_msg(a, b);
        }
    );
}

TEST(AddTest, AddTest0B) {
    property_test(
        []() {
            Point2D a = { 0.0f, 0.0f };
            Point2D b = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            Point2D expected = b;
            Point2D actual = add(a, b);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << add_error_msg(a, b);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << add_error_msg(a, b);
        }
    );
}

//TEST(AddTest, AddTestAssoc) {
//    property_test(
//        [] () {
//            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
//            Point2D b = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
//            Point2D c = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
//            return std::make_tuple(a, b, c);
//        },
//        [] (std::tuple<Point2D, Point2D, Point2D> data) {
//            Point2D a, b, c;
//            std::tie(a, b, c) = data;
//            Point2D expected = add(add(a, b), c);
//            Point2D actual = add(a, add(b, c));
//            ASSERT_FLOAT_EQ(expected.x, actual.x) << add_error_msg(a, b);
//            ASSERT_FLOAT_EQ(expected.y, actual.y) << add_error_msg(a, b);
//        }
//    );
//}
//
//TEST(AddTest, AddTestComm) {
//    property_test(
//        [] () {
//            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
//            Point2D b = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
//            return std::make_tuple(a, b);
//        },
//        [] (std::tuple<Point2D, Point2D> data) {
//            Point2D a, b;
//            std::tie(a, b) = data;
//            Point2D expected = add(b, a);
//            Point2D actual = add(a, b);
//            ASSERT_FLOAT_EQ(expected.x, actual.x) << add_error_msg(a, b);
//            ASSERT_FLOAT_EQ(expected.y, actual.y) << add_error_msg(a, b);
//        }
//    );
//}

TEST(AddTest, AddTestRandom) {
    property_test(
        [] () {
            Point2D a = {genFloat(MIN, MAX), genFloat(MIN, MAX)};
            Point2D b = {genFloat(MIN, MAX), genFloat(MIN, MAX)};
            return std::make_tuple(a, b);
        },
        [] (std::tuple<Point2D, Point2D> data) {
            Point2D a, b;
            std::tie(a, b) = data;
            Point2D expected = expected::add(a, b);
            Point2D actual = add(a, b);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << add_error_msg(a, b);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << add_error_msg(a, b);
        }
    );
}

std::string mul_error_msg(float s, Point2D a) {
    std::ostringstream stream;
    stream << "Test data:" << std::endl
           << "  s = " << s << std::endl
           << "  a = { " << a.x << ", " << a.y << " }" << std::endl;
    return stream.str();
}

TEST(MulTest, MulTest0) {
    property_test(
        [] () {
            float s = 0.0f;
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return std::make_tuple(s, a);
        },
        [] (std::tuple<float, Point2D> data) {
            float s;
            Point2D a;
            std::tie(s, a) = data;
            Point2D expected = { 0.0f, 0.0f };
            Point2D actual = mul(s, a);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << mul_error_msg(s, a);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << mul_error_msg(s, a);
        }
    );
}

TEST(MulTest, MulTest1) {
    property_test(
        [] () {
            float s = 1.0f;
            Point2D a = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            return std::make_tuple(s, a);
        },
        [] (std::tuple<float, Point2D> data) {
            float s;
            Point2D a;
            std::tie(s, a) = data;
            Point2D expected = a;
            Point2D actual = mul(s, a);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << mul_error_msg(s, a);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << mul_error_msg(s, a);
        }
    );
}

TEST(MulTest, MulTestS0) {
    property_test(
        [] () {
            float s = genFloat(MIN, MAX);
            Point2D a = { 0.0f, 0.0f };
            return std::make_tuple(s, a);
        },
        [] (std::tuple<float, Point2D> data) {
            float s;
            Point2D a;
            std::tie(s, a) = data;
            Point2D expected = { 0.0f, 0.0f };
            Point2D actual = mul(s, a);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << mul_error_msg(s, a);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << mul_error_msg(s, a);
        }
    );
}

TEST(MulTest, MulTestRandom) {
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
            Point2D actual = mul(s, a);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << mul_error_msg(s, a);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << mul_error_msg(s, a);
        }
    );
}

std::string move_error_msg(Point2D position, Point2D velocity, float delta) {
    std::ostringstream stream;
    stream << "Test data:" << std::endl
           << "  position = { " << position.x << ", " << position.y << " }" << std::endl
           << "  velocity = { " << velocity.x << ", " << velocity.y << " }" << std::endl
           << "  delta = "    << delta    << std::endl;
    return stream.str();
}

TEST(MoveTest, MoveTestDelta0) {
    property_test(
        [] () {
            Point2D position = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Point2D velocity = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            float delta = 0.0f;
            return std::make_tuple(position, velocity, delta);
        },
        [] (std::tuple<Point2D, Point2D, float> data) {
            Point2D position, velocity;
            float delta;
            std::tie(position, velocity, delta) = data;
            Point2D expected = position;
            Point2D actual = move(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << move_error_msg(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << move_error_msg(position, velocity, delta);
        }
    );
}

TEST(MoveTest, MoveTestVelocity0) {
    property_test(
        [] () {
            Point2D position = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Point2D velocity = { 0.0f, 0.0f };
            float delta = genFloat(MIN, MAX);
            return std::make_tuple(position, velocity, delta);
        },
        [] (std::tuple<Point2D, Point2D, float> data) {
            Point2D position, velocity;
            float delta;
            std::tie(position, velocity, delta) = data;
            Point2D expected = position;
            Point2D actual = move(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << move_error_msg(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << move_error_msg(position, velocity, delta);
        }
    );
}

TEST(MoveTest, MoveTestRandom) {
    property_test(
        [] () {
            Point2D position = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            Point2D velocity = { genFloat(MIN, MAX), genFloat(MIN, MAX) };
            float delta = genFloat(MIN, MAX);
            return std::make_tuple(position, velocity, delta);
        },
        [] (std::tuple<Point2D, Point2D, float> data) {
            Point2D position, velocity;
            float delta;
            std::tie(position, velocity, delta) = data;
            Point2D expected = expected::move(position, velocity, delta);
            Point2D actual = move(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected.x, actual.x) << move_error_msg(position, velocity, delta);
            ASSERT_FLOAT_EQ(expected.y, actual.y) << move_error_msg(position, velocity, delta);
        }
    );
}
