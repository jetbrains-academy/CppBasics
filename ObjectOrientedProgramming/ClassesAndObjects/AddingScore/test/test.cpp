#include "gtest/gtest.h"
#include "testscene.hpp"
#include "player.hpp"

TEST(PlayerTest, OnCollision) {
    TestPlayerObject player;
    TestConsumableObject consumable;
    CollisionInfo info{};
    info.collide = true;
    player.onCollision(consumable, info);
    ASSERT_EQ(player.getScore(), 1000);
}

TEST(DynSceneTest, UpdateScore) {
    TestGameplayDynamicScene scene;
    TestPlayerObject player;
    TestConsumableObject consumable;
    CollisionInfo info{};
    info.collide = true;
    player.onCollision(consumable, info);
    scene.insertPlayerObject(player);
    scene.performUpdateScore();
    ASSERT_EQ(scene.getScore(), 1000);
}
