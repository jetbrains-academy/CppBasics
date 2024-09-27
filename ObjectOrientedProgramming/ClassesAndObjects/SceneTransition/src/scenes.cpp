#include "scenes.hpp"

bool SceneManager::initialize() {
    dynamicScene.activate();
    return true;
}

Scene* SceneManager::getCurrentScene() {
    return &dynamicScene;
}

Scene* SceneManager::transitionScene(SceneID sceneID) {
    if (sceneID != currentScene->getID()) {
        currentScene->deactivate();
    }
    if (sceneID == SceneID::DYNAMIC_GAME_FIELD) {
        currentScene = &dynamicScene;
        dynamicScene.activate();
        return currentScene;
    }
    if (sceneID == SceneID::LEADERBOARD) {
        unsigned int score = 0;
        if (currentScene->getID() == SceneID::DYNAMIC_GAME_FIELD) {
            score = dynamicScene.getScore();
        }
        currentScene = &leaderboardScene;
        leaderboardScene.activate();
        leaderboardScene.recieveScore(score);
        return currentScene;
    }
    return currentScene;
}
