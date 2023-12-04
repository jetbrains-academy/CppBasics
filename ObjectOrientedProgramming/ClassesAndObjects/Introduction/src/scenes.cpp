#include "scenes.hpp"

bool SceneManager::initialize() {
    staticScene.activate();
    return true;
}

Scene* SceneManager::getCurrentScene() {
    return &staticScene;
}

void SceneManager::transitionScene(SceneID id) {
    return;
}