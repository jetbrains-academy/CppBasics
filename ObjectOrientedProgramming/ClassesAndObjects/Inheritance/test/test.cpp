#include <gtest/gtest.h>

#include <iostream>

#include "gobject.hpp"
#include "operators.hpp"

#include "testscene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e3;
const float MAX = 10e3;

const Rectangle generateArea = { { MIN, MIN }, { MAX, MAX } };

std::string getPosition_error_msg(CircleGameObject* object, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  object.getPosition()" << "\n";
    stream << "Expected result:\n"
        << "  object.getPosition() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getPosition() = " << actual << "\n";
    return stream.str();
}

TEST(CircleGameObjectTest, GetPositionTest) {
    Point2D center = { 10.0f, 10.0f };
    float radius = 30.0f;
    TestCircleGameObject object = TestCircleGameObject(
        Circle { center, radius },
        Point2D { 0.0f, 0.0f },
        GameObjectKind::CONSUMABLE
    );
    ASSERT_FLOAT_EQ(center.x, object.getPosition().x)
            << getPosition_error_msg(&object, center, object.getPosition());
    ASSERT_FLOAT_EQ(center.y, object.getPosition().y)
            << getPosition_error_msg(&object, center, object.getPosition());
}

std::string setPosition_error_msg(CircleGameObject* object, Point2D position, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  object.setPosition(p)" << "\n";
    stream << "Test data:" << "\n"
        << "  object.getPosition() = " << object->getPosition() << "\n"
        << "  p = " << position << "\n";
    stream << "Expected result:\n"
        << "  object.getPosition() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getPosition() = " << actual << "\n";
    return stream.str();
}

TEST(CircleGameObjectTest, SetPositionTest) {
    Point2D position = { 10.0f, 10.0f };
    TestCircleGameObject object = TestCircleGameObject();
    object.performSetPosition(position);
    ASSERT_FLOAT_EQ(position.x, object.getPosition().x)
            << setPosition_error_msg(&object, position, position, object.getPosition());
    ASSERT_FLOAT_EQ(position.y, object.getPosition().y)
            << setPosition_error_msg(&object, position, position, object.getPosition());
}

std::string getStatus_error_msg(CircleGameObject* object, GameObjectStatus expected, GameObjectStatus actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  object.getStatus()" << "\n";
    stream << "Expected result:\n"
        << "  object.getStatus() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getStatus() = " << actual << "\n";
    return stream.str();
}

TEST(CircleGameObjectTest, GetStatusTest) {
    TestCircleGameObject object = TestCircleGameObject();
    ASSERT_EQ(GameObjectStatus::NORMAL, object.getStatus())
            << getStatus_error_msg(&object, GameObjectStatus::NORMAL, object.getStatus());
}

std::string setStatus_error_msg(CircleGameObject* object, GameObjectStatus status, GameObjectStatus expected, GameObjectStatus actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  object.setStatus(status)" << "\n";
    stream << "Test data:" << "\n"
        << "  object.getStatus() = " << object->getStatus() << "\n"
        << "  status = " << status << "\n";
    stream << "Expected result:\n"
        << "  object.getStatus() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getStatus() = " << actual << "\n";
    return stream.str();
}

TEST(CircleGameObjectTest, SetStatusTest) {
    TestCircleGameObject object = TestCircleGameObject();

    TestCircleGameObject actual1 = TestCircleGameObject();
    actual1.performSetStatus(GameObjectStatus::NORMAL);
    ASSERT_EQ(GameObjectStatus::NORMAL, actual1.getStatus())
            << setStatus_error_msg(&object, GameObjectStatus::NORMAL, GameObjectStatus::NORMAL, actual1.getStatus());

    TestCircleGameObject actual2 = TestCircleGameObject();
    actual2.performSetStatus(GameObjectStatus::WARNED);
    ASSERT_EQ(GameObjectStatus::WARNED, actual2.getStatus())
            << setStatus_error_msg(&object, GameObjectStatus::WARNED, GameObjectStatus::WARNED, actual2.getStatus());

    TestCircleGameObject actual3 = TestCircleGameObject();
    actual3.performSetStatus(GameObjectStatus::DESTROYED);
    ASSERT_EQ(GameObjectStatus::DESTROYED, actual3.getStatus())
            << setStatus_error_msg(&object, GameObjectStatus::DESTROYED, GameObjectStatus::DESTROYED, actual3.getStatus());
}

std::string getCircle_error_msg(CircleGameObject* object, Point2D position, Circle expected, Circle actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  object.setPosition(p)" << "\n";
    stream << "Test data:" << "\n"
        << "  object.getCircle() = " << object->getCircle() << "\n"
        << "  p = " << position << "\n";
    stream << "Expected result:\n"
        << "  object.getCircle() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getCircle() = " << actual << "\n";
    return stream.str();
}

TEST(CircleGameObjectTest, GetCircleTest) {
    TestCircleGameObject object = TestCircleGameObject();
    Point2D position = Point2D { 150.0f, 300.0f };
    Circle expected = Circle { position, CONSUMABLE_RADIUS };
    TestCircleGameObject actual = TestCircleGameObject();
    actual.performSetPosition(position);
    ASSERT_FLOAT_EQ(expected.center.x, actual.getCircle().center.x)
            << getCircle_error_msg(&object, position, expected, actual.getCircle());
    ASSERT_FLOAT_EQ(expected.center.y, actual.getCircle().center.y)
            << getCircle_error_msg(&object, position, expected, actual.getCircle());
    ASSERT_FLOAT_EQ(expected.radius, actual.getCircle().radius)
            << getCircle_error_msg(&object, position, expected, actual.getCircle());
}