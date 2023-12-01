#include "statscene.hpp"

void StaticScene::activate() {
    fitInto(player);
    fitInto(consumable);
    fitInto(enemy);
}

void StaticScene::deactivate() {
    return;
}

SceneID StaticScene::getID() const {
    return SceneID::STATIC_GAME_FIELD;
}

SceneID StaticScene::getNextSceneID() const {
    return SceneID::STATIC_GAME_FIELD;
}

void StaticScene::processEvent(const sf::Event& event) {
    return;
}

void StaticScene::update(sf::Time delta) {
    player.update(delta);
    consumable.update(delta);
    enemy.update(delta);
    move(player, delta);
    move(enemy, delta);
    move(consumable, delta);
    detectCollision(player, consumable);
    detectCollision(enemy, player);
    detectCollision(enemy, consumable);
}

void StaticScene::draw(sf::RenderWindow &window, TextureManager& textureManager) {
    drawBackground(window, textureManager.getTexture(GameTextureID::SPACE));
    player.draw(window, textureManager);
    consumable.draw(window, textureManager);
    enemy.draw(window, textureManager);
}