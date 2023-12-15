#include "player.hpp"

#include "constants.hpp"
#include "direction.hpp"
#include "operators.hpp"

PlayerObject::PlayerObject()
    : CircleGameObject({ { PLAYER_START_X, PLAYER_START_Y }, RADIUS })
{}

GameObjectKind PlayerObject::getKind() const {
    return GameObjectKind::PLAYER;
}

Point2D PlayerObject::getVelocity() const {
    Point2D velocity = { 0.0f, 0.0f };
    if (CircleGameObject::getStatus() == GameObjectStatus::DESTROYED)
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

void PlayerObject::update(sf::Time delta) {
    return;
}

const sf::Texture* PlayerObject::getTexture(TextureManager& textureManager) const {
    switch (getStatus()) {
        case GameObjectStatus::NORMAL:
            return textureManager.getTexture(GameTextureID::PLANET);
        case GameObjectStatus::WARNED:
            return textureManager.getTexture(GameTextureID::PLANET);
        case GameObjectStatus::DESTROYED:
            return textureManager.getTexture(GameTextureID::PLANET_DEAD);
        default:
            return nullptr;
    }
}

void PlayerObject::onCollision(const GameObject &object, const CollisionInfo &info) {
    if (info.collide && object.getKind() == GameObjectKind::ENEMY) {
        setStatus(GameObjectStatus::DESTROYED);
    }
}