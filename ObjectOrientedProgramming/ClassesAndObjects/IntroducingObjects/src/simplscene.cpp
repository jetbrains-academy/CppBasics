#include "simplscene.hpp"

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
    move(player, 0.001f * delta.asMilliseconds() * player.getVelocity());
    move(enemy, 0.001f * delta.asMilliseconds() * enemy.getVelocity());
    detectCollision(player, consumable);
    detectCollision(enemy, player);
    detectCollision(enemy, consumable);
}

void SimpleScene::draw() {
    Scene::draw(player);
    Scene::draw(consumable);
    Scene::draw(enemy);
}