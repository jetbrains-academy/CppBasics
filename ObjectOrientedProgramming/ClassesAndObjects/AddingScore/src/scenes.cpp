#include "scenes.hpp"

bool SceneManager::initialize() {
    dynamicScene.activate();
    return true;
}

Scene* SceneManager::getCurrentScene() {
    return &dynamicScene;
}

Scene* SceneManager::transitionScene(SceneID sceneID, Scene* currentScene, unsigned int score) {
    switch (sceneID) {
        case SceneID::DYNAMIC_GAME_FIELD:
            dynamicScene.activate();
            return &dynamicScene;
        case SceneID::LEADERBOARD:
            leaderboardScene.activate();
            leaderboardScene.recieveScore(score);
            return &leaderboardScene;
        default:
            return currentScene;
    }
}
