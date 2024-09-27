#include "scenes.hpp"

bool SceneManager::initialize() {
    dynamicScene.activate();
    return true;
}

Scene* SceneManager::getCurrentScene() {
    return &dynamicScene;
}

Scene* SceneManager::transitionScene(SceneID sceneID) {
    return nullptr;
    // TODO: Implement your solution here.
}
