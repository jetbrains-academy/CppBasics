#include <gtest/gtest.h>
#include "testscene.hpp"
#include "engine.hpp"
#include "scenes.hpp"

TEST(GameplayDynamicSceneTest, getNextSceneIdInitial) {
    TestGameplayDynamicScene scene;
    TestPlayerObject player;
    player.performSetPosition({50,50});
    scene.insertPlayerObject(player);
    ASSERT_EQ(scene.getNextSceneID(), SceneID::DYNAMIC_GAME_FIELD);
}

TEST(GameplayDynamicSceneTest, getNextSceneIdComplex) {
    TestGameplayDynamicScene scene;
    TestPlayerObject player;
    player.performSetPosition({50,50});
    scene.insertPlayerObject(player);
    ASSERT_EQ(scene.getNextSceneID(), SceneID::DYNAMIC_GAME_FIELD);
    TestEnemyObject enemy;
    enemy.performSetPosition({50,50});
    scene.insertEnemyObject(enemy);
    scene.update(sf::seconds(1));
    ASSERT_EQ(scene.getNextSceneID(), SceneID::LEADERBOARD);
}

TEST(SceneManagerTest, transitionScene) {
    SceneManager manager;
    manager.initialize();
    Scene *scene = manager.getCurrentScene();
    ASSERT_EQ(scene->getID(), SceneID::DYNAMIC_GAME_FIELD);
    scene = manager.transitionScene(SceneID::LEADERBOARD);
    ASSERT_EQ(scene->getID(), SceneID::LEADERBOARD);
}