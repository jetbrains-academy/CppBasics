#include "gtest/gtest.h"
#include "testscene.hpp"
#include "dynscene.hpp"
#include "player.hpp"


TEST(PlayerTest, OnCollision) {
    TestPlayerObject player;
    TestConsumableObject consumable;
    CollisionInfo info;
    info.collide = true;
    player.onCollision(consumable, info);
    ASSERT_EQ(player.getScore(), 1000);
}

TEST(DynSceneTest, UpdateScore) {
    // tmp
}
