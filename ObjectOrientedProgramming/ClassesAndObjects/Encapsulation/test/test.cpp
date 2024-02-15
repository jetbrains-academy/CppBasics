#include <gtest/gtest.h>

#include <iostream>

#include "scene.hpp"
#include "operators.hpp"
#include "constants.hpp"

#include "testscene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

std::string setObjectPosition_error_msg(Scene* scene, GameObject* object, Point2D position, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  scene.setObjectPosition(object, position)" << "\n";
    stream << "Test data:" << "\n"
        << "  scene.getBoundingBox() = " << scene->getBoundingBox() << "\n"
        << "  object.getPosition() = " << object->getPosition() << "\n"
        << "  position = " << position << "\n";
    stream << "Expected result:\n"
        << "  object.getPosition() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getPosition() = " << actual << "\n";
    return stream.str();
}

std::string setObjectPositionInRectangle_error_msg(Scene* scene, GameObject* object, Point2D position, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  scene.setObjectPosition(object, position)" << "\n";
    stream << "Test data:" << "\n"
        << "  scene.getBoundingBox() = " << scene->getBoundingBox() << "\n"
        << "  object.getPosition() = " << object->getPosition() << "\n"
        << "  position = " << position << "\n";
    stream << "Actual result:\n"
        << "  object.getPosition() = " << actual << "\n";
    stream << "The result is not withing the scene bounds!\n";
    return stream.str();
}

TEST(SceneTest, SetObjectPositionInBoundsTest) {
    TestScene scene = TestScene(SCENE_WIDTH, SCENE_HEIGHT);
    property_test(
        [] () {
            const float radius = 20.0f;
            Point2D offset = { radius, radius };
            Rectangle positionArea = {
                Point2D { 0.0f, 0.0f } + offset,
                Point2D { SCENE_WIDTH, SCENE_HEIGHT } - offset
            };
            Point2D position = generatePoint(positionArea);
            Circle circle = Circle { position, radius };
            Point2D velocity = Point2D { 0.0f, 0.0f };
            TestCircleGameObject object = TestCircleGameObject(circle, velocity, GameObjectKind::CONSUMABLE);
            Rectangle newPositionArea = positionArea;
            Point2D newPosition = generatePoint(newPositionArea);
            return std::make_tuple(object, newPosition);
        },
        [&scene] (std::tuple<TestCircleGameObject, Point2D> data) {
            TestCircleGameObject object;
            Point2D newPosition;
            std::tie(object, newPosition) = data;
            TestCircleGameObject expected = object;
            expected.performSetPosition(newPosition);
            TestCircleGameObject actual = object;
            scene.performSetObjectPosition(actual, newPosition);
            ASSERT_TRUE(isInRectangle(actual.getPosition(), scene.getBoundingBox()))
                    << setObjectPositionInRectangle_error_msg(&scene, &object, newPosition, actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().x, actual.getPosition().x)
                    << setObjectPosition_error_msg(&scene, &object, newPosition, expected.getPosition(), actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().y, actual.getPosition().y)
                    << setObjectPosition_error_msg(&scene, &object, newPosition, expected.getPosition(), actual.getPosition());
        }
    );
}

TEST(SceneTest, SetObjectPositionOutOfBoundsTest) {
    TestScene scene = TestScene(SCENE_WIDTH, SCENE_HEIGHT);
    property_test(
        [&scene] () {
            const float radius = 20.0f;
            Point2D offset = { radius, radius };
            Rectangle positionArea = {
                Point2D { 0.0f, 0.0f } + offset,
                Point2D { SCENE_WIDTH, SCENE_HEIGHT } - offset
            };
            Point2D position = generatePoint(positionArea);
            Circle circle = Circle { position, radius };
            Point2D velocity = Point2D { 0.0f, 0.0f };
            TestCircleGameObject object = TestCircleGameObject(circle, velocity, GameObjectKind::CONSUMABLE);
            Rectangle newPositionArea = {
                { - 2 * SCENE_WIDTH, -2 * SCENE_HEIGHT },
                { 2 * SCENE_WIDTH, 2 * SCENE_HEIGHT }
            };
            Point2D newPosition;
            do {
                newPosition = generatePoint(newPositionArea);
            } while (isInRectangle(newPosition, scene.getBoundingBox()));
            return std::make_tuple(object, newPosition);
        },
        [&scene] (std::tuple<TestCircleGameObject, Point2D> data) {
            TestCircleGameObject object;
            Point2D newPosition;
            std::tie(object, newPosition) = data;
            TestCircleGameObject expected = object;
            expected.performSetPosition(newPosition);
            Rectangle rect = fitInto(expected.getBoundingBox(), scene.getBoundingBox());
            expected.performSetPosition(center(rect));
            TestCircleGameObject actual = object;
            scene.performSetObjectPosition(actual, newPosition);
            ASSERT_TRUE(isInRectangle(actual.getPosition(), scene.getBoundingBox()))
                    << setObjectPositionInRectangle_error_msg(&scene, &object, newPosition, actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().x, actual.getPosition().x)
                    << setObjectPosition_error_msg(&scene, &object, newPosition, expected.getPosition(), actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().y, actual.getPosition().y)
                    << setObjectPosition_error_msg(&scene, &object, newPosition, expected.getPosition(), actual.getPosition());
        }
    );
}

std::string moveObject_error_msg(Scene* scene, GameObject* object, Point2D vector, Point2D expected, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  scene.move(object, vector)" << "\n";
    stream << "Test data:" << "\n"
        << "  scene.getBoundingBox() = " << scene->getBoundingBox() << "\n"
        << "  object.getPosition() = " << object->getPosition() << "\n"
        << "  vector = " << vector << "\n";
    stream << "Expected result:\n"
        << "  object.getPosition() = " << expected << "\n";
    stream << "Actual result:\n"
        << "  object.getPosition() = " << actual << "\n";
    return stream.str();
}

std::string moveObjectInRectangle_error_msg(Scene* scene, GameObject* object, Point2D vector, Point2D actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
        << "  scene.move(object, vector)" << "\n";
    stream << "Test data:" << "\n"
        << "  scene.getBoundingBox() = " << scene->getBoundingBox() << "\n"
        << "  object.getPosition() = " << object->getPosition() << "\n"
        << "  vector = " << vector << "\n";
    stream << "Actual result:\n"
        << "  object.getPosition() = " << actual << "\n";
    stream << "The result is not withing the scene bounds!\n";
    return stream.str();
}

TEST(SceneTest, MoveInBoundsTest) {
    TestScene scene = TestScene(SCENE_WIDTH, SCENE_HEIGHT);
    property_test(
        [] () {
            const float radius = 20.0f;
            Point2D position = { SCENE_WIDTH / 2, SCENE_HEIGHT / 2 };
            Circle circle = Circle { position, radius };
            Point2D velocity = Point2D { 0.0f, 0.0f };
            TestCircleGameObject object = TestCircleGameObject(circle, velocity, GameObjectKind::CONSUMABLE);
            Rectangle vectorArea = Rectangle { { 0.0f, 0.0f }, { 2 * radius, 2 * radius } };
            Point2D vector = generatePoint(vectorArea);
            return std::make_tuple(object, vector);
        },
        [&scene] (std::tuple<TestCircleGameObject, Point2D> data) {
            TestCircleGameObject object;
            Point2D vector;
            std::tie(object, vector) = data;
            TestCircleGameObject expected = object;
            expected.performSetPosition(expected.getPosition() + vector);
            TestCircleGameObject actual = object;
            scene.performMove(actual, vector);
            ASSERT_TRUE(isInRectangle(actual.getPosition(), scene.getBoundingBox()))
                    << moveObjectInRectangle_error_msg(&scene, &object, vector, actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().x, actual.getPosition().x)
                    << moveObject_error_msg(&scene, &object, vector, expected.getPosition(), actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().y, actual.getPosition().y)
                    << moveObject_error_msg(&scene, &object, vector, expected.getPosition(), actual.getPosition());
        }
    );
}

TEST(SceneTest, MoveOutOfBoundsTest) {
    TestScene scene = TestScene(SCENE_WIDTH, SCENE_HEIGHT);
    property_test(
        [] () {
            const float radius = 20.0f;
            Point2D position = { SCENE_WIDTH / 2, SCENE_HEIGHT / 2 };
            Circle circle = Circle { position, radius };
            Point2D velocity = Point2D { 0.0f, 0.0f };
            TestCircleGameObject object = TestCircleGameObject(circle, velocity, GameObjectKind::CONSUMABLE);
            Rectangle vectorArea = Rectangle {
                { SCENE_WIDTH, SCENE_HEIGHT },
                { 4 * SCENE_WIDTH, 4 * SCENE_HEIGHT },
            };
            Point2D vector = generatePoint(vectorArea);
            return std::make_tuple(object, vector);
        },
        [&scene] (std::tuple<TestCircleGameObject, Point2D> data) {
            TestCircleGameObject object;
            Point2D vector;
            std::tie(object, vector) = data;
            TestCircleGameObject expected = object;
            expected.performSetPosition(expected.getPosition() + vector);
            Rectangle rect = fitInto(expected.getBoundingBox(), scene.getBoundingBox());
            expected.performSetPosition(center(rect));
            TestCircleGameObject actual = object;
            scene.performMove(actual, vector);
            ASSERT_TRUE(isInRectangle(actual.getPosition(), scene.getBoundingBox()))
                    << moveObjectInRectangle_error_msg(&scene, &object, vector, actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().x, actual.getPosition().x)
                    << moveObject_error_msg(&scene, &object, vector, expected.getPosition(), actual.getPosition());
            ASSERT_FLOAT_EQ(expected.getPosition().y, actual.getPosition().y)
                    << moveObject_error_msg(&scene, &object, vector, expected.getPosition(), actual.getPosition());
        }
    );
}