#include "scenes.hpp"

bool SceneManager::initialize() {
    staticScene.activate();
    return true;
}

Scene* SceneManager::getCurrentScene() {
    return &staticScene;
}

Scene* SceneManager::transitionScene(SceneID sceneID, Scene* currentScene, unsigned int score) {
    return nullptr;
    // TODO: Implement your solution here.
}
