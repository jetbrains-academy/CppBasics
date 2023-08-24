#include "statscene.hpp"

void StaticScene::initialize() {
    fitInto(player);
    fitInto(consumable);
    fitInto(enemy);
}

void StaticScene::processEvent(const sf::Event& event) {
    switch (event.type) {
        case sf::Event::Closed:
            close();
            break;
        default:
            break;
    }
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

void StaticScene::draw() {
    Scene::draw(player);
    Scene::draw(consumable);
    Scene::draw(enemy);
}