#include "player.hpp"

#include "direction.hpp"
#include "constants.hpp"

PlayerObject::PlayerObject(Circle circle, sf::Texture *texture)
    : CircleGameObject(circle, texture)
{}

Point2D PlayerObject::getVelocity() const {
    Point2D velocity = { 0.0f, 0.0f };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity = velocity + getDirection(North);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity = velocity + getDirection(East);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocity = velocity + getDirection(South);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity = velocity + getDirection(West);
    }
    velocity = SPEED * velocity;
    return velocity;
}

void PlayerObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    return;
}