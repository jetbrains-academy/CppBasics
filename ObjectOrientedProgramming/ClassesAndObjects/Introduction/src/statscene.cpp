#include "statscene.hpp"

#include "constants.hpp"

GameplayStaticScene::GameplayStaticScene() : Scene(SCENE_WIDTH, SCENE_HEIGHT) {}

void GameplayStaticScene::activate() {
    fitInto(player);
    fitInto(consumable);
    fitInto(enemy);
}

void GameplayStaticScene::deactivate() {
    return;
}

SceneID GameplayStaticScene::getID() const {
    return SceneID::STATIC_GAME_FIELD;
}

SceneID GameplayStaticScene::getNextSceneID() const {
    return SceneID::STATIC_GAME_FIELD;
}

void GameplayStaticScene::processEvent(const sf::Event& event) {
    return;
}

void GameplayStaticScene::update(sf::Time delta) {
    player.update(delta);
    consumable.update(delta);
    enemy.update(delta);
    move(player, delta);
    move(consumable, delta);
    move(enemy, delta);
    detectCollision(player, consumable);
    detectCollision(enemy, player);
    detectCollision(enemy, consumable);
}

void GameplayStaticScene::draw(sf::RenderWindow &window, TextureManager& textureManager) {
    drawBackground(window, textureManager.getTexture(GameTextureID::SPACE));
    player.draw(window, textureManager);
    consumable.draw(window, textureManager);
    enemy.draw(window, textureManager);
}