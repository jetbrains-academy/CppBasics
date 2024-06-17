#include <gtest/gtest.h>
#include "testscene.hpp"

TEST(DynSceneTest, updatePlayerStatus) {
    TestGameplayDynamicScene scene;
    ASSERT_EQ(scene.isPlayerAlive(), true);
    TestPlayerObject player;
    TestEnemyObject enemy;
    CollisionInfo info;
    info.collide = true;
    player.onCollision(enemy, info);
    scene.insertPlayerObject(player);
    scene.performUpdatePlayerStatus();
    ASSERT_EQ(scene.isPlayerAlive(), false);
}
