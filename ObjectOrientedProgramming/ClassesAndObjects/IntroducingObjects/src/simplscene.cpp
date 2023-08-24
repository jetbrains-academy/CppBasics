#include "simplscene.hpp"

void SimpleScene::initialize() {
    fitInto(player);
    fitInto(consumable);
    fitInto(enemy);
}

void SimpleScene::processEvent(const sf::Event& event) {
    switch (event.type) {
        case sf::Event::Closed:
            close();
            break;
        default:
            break;
    }
}

void SimpleScene::update(sf::Time delta) {
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

void SimpleScene::draw() {
    Scene::draw(player);
    Scene::draw(consumable);
    Scene::draw(enemy);
}