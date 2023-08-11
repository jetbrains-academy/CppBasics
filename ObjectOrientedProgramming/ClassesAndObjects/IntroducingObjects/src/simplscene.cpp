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
    detectCollision(player, consumable);
    detectCollision(enemy, player);
    detectCollision(enemy, consumable);
}

void SimpleScene::render() {
    draw(player);
    draw(consumable);
    draw(enemy);
}