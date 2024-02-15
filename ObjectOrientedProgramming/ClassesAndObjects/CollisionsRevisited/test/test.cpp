#include <gtest/gtest.h>

#include "consumable.hpp"
#include "operators.hpp"

#include "testscene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e3;
const float MAX = 10e3;

const Rectangle generateArea = { { MIN, MIN }, { MAX, MAX } };

std::string onCollision_error_msg(GameObject* object, GameObject* other, const CollisionInfo& info,
                                  GameObjectStatus expected, GameObjectStatus actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  object.onCollision(other, info)" << "\n";
    stream << "Test data:" << "\n"
           << "  object.getKind() = " << object->getKind() << "\n"
           << "  object.getStatus() = " << object->getStatus() << "\n"
           << "  other.getKind() = " << other->getKind() << "\n"
           << "  other.getStatus() = " << other->getStatus() << "\n"
           << "  info = " << info << "\n";
    stream << "Expected result:\n"
           << "  object.getStatus() = " << expected << "\n";
    stream << "Actual result:\n"
           << "  object.getStatus() = " << actual << "\n";
    return stream.str();
}

TEST(ConsumableObjectTest, OnCollisionDestroyTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of consumable object after a collision with another non-consumable object should become GameObjectStatus::DESTROYED";
}

TEST(ConsumableObjectTest, OnCollisionDestroyWarnedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::WARNED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of consumable object after a collision with another non-consumable object should become GameObjectStatus::DESTROYED";
}

TEST(ConsumableObjectTest, OnCollisionWarnTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, object.getCircle().radius + 10.0f };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::WARNED, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::WARNED, actual.getStatus())
        << "The status of consumable object after another non-consumable object approached it should become GameObjectStatus::WARNED";
}

TEST(ConsumableObjectTest, OnCollisionConsumableTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::CONSUMABLE);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::NORMAL, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::NORMAL, actual.getStatus())
        << "The status of consumable object after a collision with another consumable object should not change";
}

TEST(ConsumableObjectTest, OnCollisionConsumableWarningTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::CONSUMABLE);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, object.getCircle().radius + 10.0f };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::NORMAL, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::NORMAL, actual.getStatus())
        << "The status of consumable object after another consumable object approached it should not change";
}

TEST(ConsumableObjectTest, OnCollisionDestroyedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of destroyed consumable object after a collision should remain GameObjectStatus::DESTROYED";
}

TEST(ConsumableObjectTest, OnCollisionDestroyedWarningTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, object.getCircle().radius + 10.0f };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of destroyed consumable object after a another object approached it should remain GameObjectStatus::DESTROYED";
}

TEST(ConsumableObjectTest, OnCollisionDestroyedNoCollisionTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, 2 * CONSUMABLE_WARNED_MULTIPLIER * object.getCircle().radius };
    TestConsumableObject actual = object;
    actual.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << onCollision_error_msg(&object, &other, info, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of destroyed consumable object should remain GameObjectStatus::DESTROYED";
}

std::string update_error_msg(GameObject* object, GameObjectStatus expected, GameObjectStatus actual) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  object.update(delta)" << "\n";
    stream << "Test data:" << "\n"
           << "  object.getKind() = " << object->getKind() << "\n"
           << "  object.getStatus() = " << object->getStatus() << "\n";
    stream << "Expected result:\n"
           << "  object.getStatus() = " << expected << "\n";
    stream << "Actual result:\n"
           << "  object.getStatus() = " << actual << "\n";
    return stream.str();
}

TEST(ConsumableObjectTest, UpdateNormalTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestConsumableObject actual = object;
    actual.update(sf::milliseconds(10));

    ASSERT_EQ(GameObjectStatus::NORMAL, actual.getStatus())
        << update_error_msg(&object, GameObjectStatus::NORMAL, actual.getStatus())
        << "The status of consumable object after an update should remain GameObjectStatus::NORMAL";
}

TEST(ConsumableObjectTest, UpdateWarnedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::WARNED);

    TestConsumableObject actual = object;
    actual.update(sf::milliseconds(10));

    ASSERT_EQ(GameObjectStatus::NORMAL, actual.getStatus())
        << update_error_msg(&object, GameObjectStatus::NORMAL, actual.getStatus())
        << "The status of warned consumable object after an update should become GameObjectStatus::NORMAL";
}

TEST(ConsumableObjectTest, UpdateDestroyedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    TestConsumableObject actual = object;
    actual.update(sf::milliseconds(10));

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << update_error_msg(&object, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of destroyed consumable object after an update should remain GameObjectStatus::DESTROYED";
}