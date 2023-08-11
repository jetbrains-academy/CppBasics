#include "player.hpp"

#include "direction.hpp"
#include "constants.hpp"

PlayerObject::PlayerObject() {
    circle = { { PLAYER_START_X, PLAYER_START_Y }, RADIUS };
}

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

const sf::Texture* PlayerObject::getTexture(TextureManager& textureManager) const {
    return textureManager.getTexture(GameTextureID::PLANET);
}

void PlayerObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    return;
}