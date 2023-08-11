#include "consumable.hpp"

#include "constants.hpp"

ConsumableObject::ConsumableObject()
    : CircleGameObject({ { CONSUMABLE_START_X, CONSUMABLE_START_Y }, CONSUMABLE_RADIUS })
{}

Point2D ConsumableObject::getVelocity() const {
    return { 0.0f, 0.0f };
}

const sf::Texture* ConsumableObject::getTexture(TextureManager& textureManager) const {
    switch (CircleGameObject::getState()) {
        case GameObjectState::NORMAL:
            return textureManager.getTexture(GameTextureID::STAR);
        case GameObjectState::CONCERNED:
            return textureManager.getTexture(GameTextureID::STAR_CONCERNED);
        default:
            return nullptr;
    }
}

GameObjectKind ConsumableObject::getKind() const {
    return GameObjectKind::CONSUMABLE;
}

void ConsumableObject::update(sf::Time delta) {
    if (CircleGameObject::getState() != GameObjectState::DEAD) {
        CircleGameObject::setState(GameObjectState::NORMAL);
    }
}

void ConsumableObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    if (CircleGameObject::getState() == GameObjectState::DEAD) {
        return;
    }
    if (collisionData.collide) {
        CircleGameObject::setState(GameObjectState::DEAD);
        return;
    }
    if (CircleGameObject::getState() == GameObjectState::CONCERNED) {
        return;
    }
    if (collisionData.distance < 6 * getCircle().radius) {
        CircleGameObject::setState(GameObjectState::CONCERNED);
        return;
    }
}