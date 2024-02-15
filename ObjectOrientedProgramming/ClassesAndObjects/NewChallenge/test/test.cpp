#include <gtest/gtest.h>

#include "enemy.hpp"
#include "operators.hpp"

#include "testscene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e3;
const float MAX = 10e3;

const Rectangle generateArea = { { MIN, MIN }, { MAX, MAX } };

std::string updateVelocity_error_msg(GameObject* object, Point2D velocity) {
    std::ostringstream stream;
    stream << "Testing expression:\n"
           << "  object.updateVelocity()" << "\n";
    stream << "Test data:" << "\n"
           << "  object.getKind() = " << object->getKind() << "\n"
           << "  object.getStatus() = " << object->getStatus() << "\n"
           << "  object.getVelocity() = " << object->getVelocity() << "\n";
    stream << "Result:\n"
           << "  object.getVelocity() = " << velocity << "\n";
    return stream.str();
}

TEST(EnemyObjectTest, UpdateVelocityChangedTest) {
    TestEnemyObject object = TestEnemyObject();
    // set some initial velocity, which does not satisfy
    // the constraints specified in the task description;
    // thus the call to `updateVelocity` should change it to some other value
    Point2D initialVelocity = { -5.0f, -5.0f };
    object.performSetStatus(GameObjectStatus::NORMAL);
    object.performSetVelocity(initialVelocity);

    TestEnemyObject actual = object;
    actual.performUpdateVelocity();

    Point2D velocity = actual.getVelocity();
    ASSERT_FALSE(velocity.x == initialVelocity.x && velocity.y == initialVelocity.y)
        << updateVelocity_error_msg(&object, actual.getVelocity())
        << "The velocity has not changed!";
}

TEST(EnemyObjectTest, UpdateVelocityInBoundsTest) {
    property_test(
        [] () {
            TestEnemyObject object = TestEnemyObject();
            object.performSetStatus(GameObjectStatus::NORMAL);
            object.performSetVelocity(Point2D { 0.0f, 0.0f });
            return std::make_tuple(object);
        },
        [] (std::tuple<TestEnemyObject> data) {
            TestEnemyObject object;
            std::tie(object) = data;
            TestEnemyObject actual = object;
            actual.performUpdateVelocity();
            Point2D velocity = actual.getVelocity();
            ASSERT_TRUE(abs(velocity.x) < EPS || abs(abs(velocity.x) - SPEED) < EPS)
                << updateVelocity_error_msg(&object, actual.getVelocity())
                << "The speed of velocity along x-axis is invalid!";
            ASSERT_TRUE(abs(velocity.y) < EPS || abs(abs(velocity.y) - SPEED) < EPS)
                << updateVelocity_error_msg(&object, actual.getVelocity())
                << "The speed of velocity along y-axis is invalid!";
        }
    );
}

TEST(EnemyObjectTest, UpdateVelocityRandomnessTest) {
    randomness_test(
        [] () {
            TestEnemyObject object = TestEnemyObject();
            object.performSetStatus(GameObjectStatus::NORMAL);
            object.performSetVelocity(Point2D { 0.0f, 0.0f });
            object.performUpdateVelocity();
            return object;
        },
        [] (const TestEnemyObject& object1, const TestEnemyObject& object2) {
            Point2D velocity1 = object1.getVelocity();
            Point2D velocity2 = object2.getVelocity();
            return (abs(velocity1.x - velocity2.x) < EPS) && (abs(velocity1.y - velocity2.y) < EPS);
        },
        [] (const TestEnemyObject& object) {
            std::stringstream stream;
            stream << "object.getVelocity() = " << object.getVelocity();
            return stream.str();
        }
    );
}

TEST(EnemyObjectTest, GetTextureTest) {
    TextureManager textureManager = TextureManager();
    bool init = textureManager.initialize();
    ASSERT_TRUE(init) << "Internal error: failed to initialize texture manager";

    TestEnemyObject object = TestEnemyObject();

    object.performSetStatus(GameObjectStatus::NORMAL);
    const sf::Texture* normalTexture = object.getTexture(textureManager);
    ASSERT_EQ(textureManager.getTexture(GameTextureID::BLACKHOLE), normalTexture)
        << "Texture of enemy object in GameObjectStatus::NORMAL status is not equal to GameTextureID::BLACKHOLE";
}

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

TEST(EnemyObjectTest, OnCollisionPlayerDestroyedTest) {
    TestEnemyObject enemy = TestEnemyObject();
    PlayerObject player = PlayerObject();

    CollisionInfo info = CollisionInfo { true, 0.0f };
    PlayerObject actual = player;
    actual.onCollision(enemy, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << onCollision_error_msg(&player, &enemy, info, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of player object after a collision with enemy object should become GameObjectStatus::DESTROYED";
}

TEST(EnemyObjectTest, OnCollisionPlayerNoCollisionTest) {
    TestEnemyObject enemy = TestEnemyObject();
    PlayerObject player = PlayerObject();

    CollisionInfo info = CollisionInfo { false, player.getCircle().radius + enemy.getCircle().radius + 10.0f };
    PlayerObject actual = player;
    actual.onCollision(enemy, info);

    ASSERT_EQ(GameObjectStatus::NORMAL, actual.getStatus())
        << onCollision_error_msg(&player, &enemy, info, GameObjectStatus::NORMAL, actual.getStatus())
        << "The status of player object after should not change in case when enemy approaches it, but does not collide";
}

TEST(EnemyObjectTest, OnCollisionConsumableDestroyedTest) {
    TestEnemyObject enemy = TestEnemyObject();
    ConsumableObject consumable = ConsumableObject();

    CollisionInfo info = CollisionInfo { true, 0.0f };
    ConsumableObject actual = consumable;
    actual.onCollision(enemy, info);

    ASSERT_EQ(GameObjectStatus::DESTROYED, actual.getStatus())
        << onCollision_error_msg(&consumable, &enemy, info, GameObjectStatus::DESTROYED, actual.getStatus())
        << "The status of consumable object after a collision with enemy object should become GameObjectStatus::DESTROYED";
}

TEST(EnemyObjectTest, OnCollisionConsumableWarnedTest) {
    TestEnemyObject enemy = TestEnemyObject();
    ConsumableObject consumable = ConsumableObject();

    CollisionInfo info = CollisionInfo { false, consumable.getCircle().radius + enemy.getCircle().radius + 10.0f };
    ConsumableObject actual = consumable;
    actual.onCollision(enemy, info);

    ASSERT_EQ(GameObjectStatus::WARNED, actual.getStatus())
        << onCollision_error_msg(&consumable, &enemy, info, GameObjectStatus::WARNED, actual.getStatus())
        << "The status of consumable object after a enemy object approached it should become GameObjectStatus::WARNED";
}

TEST(EnemyObjectTest, OnCollisionConsumableNormalTest) {
    TestEnemyObject enemy = TestEnemyObject();
    ConsumableObject consumable = ConsumableObject();

    CollisionInfo info = CollisionInfo { false, 2 * CONSUMABLE_WARNED_MULTIPLIER * consumable.getCircle().radius };
    ConsumableObject actual = consumable;
    actual.onCollision(enemy, info);

    ASSERT_EQ(GameObjectStatus::NORMAL, actual.getStatus())
        << onCollision_error_msg(&consumable, &enemy, info, GameObjectStatus::NORMAL, actual.getStatus())
        << "The status of consumable object should not have changed, because the enemy object is too far away from it";
}