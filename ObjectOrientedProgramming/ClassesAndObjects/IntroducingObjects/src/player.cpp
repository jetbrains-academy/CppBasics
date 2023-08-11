#include "player.hpp"

#include "direction.hpp"
#include "constants.hpp"

PlayerObject::PlayerObject()
    : CircleGameObject({ { PLAYER_START_X, PLAYER_START_Y }, RADIUS })
{}

Point2D PlayerObject::getVelocity() const {
    Point2D velocity = { 0.0f, 0.0f };
    if (CircleGameObject::getState() == GameObjectState::DEAD)
        return velocity;
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

GameObjectKind PlayerObject::getKind() const {
    return GameObjectKind::PLAYER;
}

const sf::Texture* PlayerObject::getTexture(TextureManager& textureManager) const {
    switch (CircleGameObject::getState()) {
        case GameObjectState::LIVE:
            return textureManager.getTexture(GameTextureID::PLANET);
        case GameObjectState::DEAD:
            return textureManager.getTexture(GameTextureID::PLANET_DEAD);
        default:
            return nullptr;
    }
}

void PlayerObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    if (collisionData.collide && object.getKind() == GameObjectKind::ENEMY) {
        CircleGameObject::setState(GameObjectState::DEAD);
    }
    return;
}