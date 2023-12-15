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

TEST(ConsumableOjectTest, OnCollisionDestroyTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::DESTROYED << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of consumable object after a collision with another non-consumable object should become GameObjectStatus::DESTROYED";
}

TEST(ConsumableOjectTest, OnCollisionDestroyWarnedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::WARNED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::WARNED << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::DESTROYED << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of consumable object after a collision with another non-consumable object should become GameObjectStatus::DESTROYED";
}

TEST(ConsumableOjectTest, OnCollisionWarnTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, object.getCircle().radius };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::WARNED, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::WARNED << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of consumable object after another non-consumable object approached it should become GameObjectStatus::WARNED";
}

TEST(ConsumableOjectTest, OnCollisionConsumableTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::CONSUMABLE);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::NORMAL, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of consumable object after a collision with another consumable object should not change";
}

TEST(ConsumableOjectTest, OnCollisionConsumableWarningTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::CONSUMABLE);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, object.getCircle().radius };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::NORMAL, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of consumable object after another consumable object approached it should not change";
}

TEST(ConsumableOjectTest, OnCollisionDestroyedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { true, 0.0f };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::DESTROYED << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of destroyed consumable object after a collision should remain GameObjectStatus::DESTROYED";
}

TEST(ConsumableOjectTest, OnCollisionDestroyedWarningTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, object.getCircle().radius };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::DESTROYED << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of destroyed consumable object after a another object approached it should remain GameObjectStatus::DESTROYED";
}

TEST(ConsumableOjectTest, OnCollisionDestroyedNoCollisionTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    TestGameObject other = TestGameObject();
    other.setKind(GameObjectKind::PLAYER);
    other.setStatus(GameObjectStatus::NORMAL);

    CollisionInfo info = CollisionInfo { false, 2 * CONSUMABLE_WARNED_MULTIPLIER * object.getCircle().radius };
    object.onCollision(other, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, object.getStatus())
        << "Testing expression:\n"
        << "  object.onCollision(other, info)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::DESTROYED << "\n"
        << "  other.getKind() = " << other.getKind() << "\n"
        << "  other.getStatus() = " << other.getStatus() << "\n"
        << "  info = " << info << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of destroyed consumable object should remain GameObjectStatus::DESTROYED";
}

TEST(ConsumableOjectTest, UpdateNormalTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::NORMAL);

    object.update(sf::milliseconds(10));

    ASSERT_EQ(GameObjectStatus::NORMAL, object.getStatus())
        << "Testing expression:\n"
        << "  object.update(delta)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of consumable object after an update should remain GameObjectStatus::NORMAL";
}

TEST(ConsumableOjectTest, UpdateWarnedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::WARNED);

    object.update(sf::milliseconds(10));

    ASSERT_EQ(GameObjectStatus::NORMAL, object.getStatus())
        << "Testing expression:\n"
        << "  object.update(delta)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::WARNED << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::NORMAL << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of warned consumable object after an update should become GameObjectStatus::NORMAL";
}

TEST(ConsumableOjectTest, UpdateDestroyedTest) {
    TestConsumableObject object = TestConsumableObject();
    object.performSetStatus(GameObjectStatus::DESTROYED);

    object.update(sf::milliseconds(10));

    ASSERT_EQ(GameObjectStatus::DESTROYED, object.getStatus())
        << "Testing expression:\n"
        << "  object.update(delta)" << "\n"
        << "Test data:" << "\n"
        << "  object.getKind() = " << object.getKind() << "\n"
        << "  object.getStatus() = " << GameObjectStatus::DESTROYED << "\n"
        << "Expected result:\n"
        << "  object.getStatus() = " << GameObjectStatus::DESTROYED << "\n"
        << "Actual result:\n"
        << "  object.getStatus() = " << object.getStatus() << "\n"
        << "The status of destroyed consumable object after an update should remain GameObjectStatus::DESTROYED";
}