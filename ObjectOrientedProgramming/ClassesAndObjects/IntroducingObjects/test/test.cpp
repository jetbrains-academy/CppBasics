#include <gtest/gtest.h>

#include <iostream>

#include "gobject.hpp"
#include "operators.hpp"

#include "testscene.hpp"
#include "testing.hpp"

const float MIN = -10e3;
const float MAX = 10e3;

const Rectangle generateArea = { { MIN, MIN }, { MAX, MAX } };


std::string move_error_msg(GameObject* object, Point2D vector, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  object.move(vector)" << "\n";
    stream << "Test data:" << "\n"
        << "  object.getPosition() = " << object->getPosition() << "\n"
        << "  vector = " << vector << "\n";
    stream << "Expected result:\n"
        << "  object.getPosition() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getPosition() = " << actual << "\n";
    return stream.str();
}

TEST(MoveTest, MoveTest0) {
    property_test(
        [] () {
            Point2D position = generatePoint(generateArea);
            Point2D velocity = Point2D { 0.0f, 0.0f };
            TestGameObject object = TestGameObject(position, velocity,
                GameObjectStatus::NORMAL,
                GameObjectKind::CONSUMABLE
            );
            return std::make_tuple(object);
        },
        [] (std::tuple<TestGameObject> data) {
            TestGameObject object;
            std::tie(object) = data;
            TestGameObject expected = object;
            TestGameObject actual = object;
            Point2D vector0 = Point2D { 0.0f, 0.0f };
            object.performMove(vector0);
            ASSERT_FLOAT_EQ(expected.getPosition().x, actual.getPosition().x)
                                << move_error_msg(&object, vector0, expected.getPosition(), actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().y, actual.getPosition().y)
                                << move_error_msg(&object, vector0, expected.getPosition(), actual.getPosition());
        }
    );
}

TEST(MoveTest, MoveTestRandom) {
    property_test(
        [] () {
            Point2D position = generatePoint(generateArea);
            Point2D velocity = Point2D { 0.0f, 0.0f };
            TestGameObject object = TestGameObject(position, velocity,
                GameObjectStatus::NORMAL,
                GameObjectKind::CONSUMABLE
            );
            Point2D vector = generatePoint(generateArea);
            return std::make_tuple(object, vector);
        },
        [] (std::tuple<TestGameObject, Point2D> data) {
            TestGameObject object;
            Point2D vector;
            std::tie(object, vector) = data;
            TestGameObject expected = object;
            expected.setPosition(expected.getPosition() + vector);
            TestGameObject actual = object;
            object.performMove(vector);
            ASSERT_FLOAT_EQ(expected.getPosition().x, actual.getPosition().x)
                << move_error_msg(&object, vector, expected.getPosition(), actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().y, actual.getPosition().y)
                << move_error_msg(&object, vector, expected.getPosition(), actual.getPosition());
        }
    );
}