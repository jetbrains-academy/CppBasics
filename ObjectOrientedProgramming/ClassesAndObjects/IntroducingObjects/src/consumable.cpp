#include "consumable.hpp"

#include "constants.hpp"

ConsumableObject::ConsumableObject()
    : CircleGameObject({ { CONSUMABLE_START_X, CONSUMABLE_START_Y }, CONSUMABLE_RADIUS })
{}

GameObjectKind ConsumableObject::getKind() const {
    return GameObjectKind::CONSUMABLE;
}

Point2D ConsumableObject::getVelocity() const {
    return { 0.0f, 0.0f };
}

void ConsumableObject::update(sf::Time delta) {
    if (CircleGameObject::getStatus() != GameObjectStatus::DESTROYED) {
        CircleGameObject::setStatus(GameObjectStatus::NORMAL);
    }
}

void ConsumableObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    if (CircleGameObject::getStatus() == GameObjectStatus::DESTROYED) {
        return;
    }
    if (collisionData.collide) {
        CircleGameObject::setStatus(GameObjectStatus::DESTROYED);
        return;
    }
    if (CircleGameObject::getStatus() == GameObjectStatus::CONCERNED) {
        return;
    }
    if (collisionData.distance < 6 * getCircle().radius) {
        CircleGameObject::setStatus(GameObjectStatus::CONCERNED);
        return;
    }
}

const sf::Texture* ConsumableObject::getTexture(TextureManager& textureManager) const {
    switch (getStatus()) {
        case GameObjectStatus::NORMAL:
            return textureManager.getTexture(GameTextureID::STAR);
        case GameObjectStatus::CONCERNED:
            return textureManager.getTexture(GameTextureID::STAR_CONCERNED);
        case GameObjectStatus::DESTROYED:
            return nullptr;
    }
}
