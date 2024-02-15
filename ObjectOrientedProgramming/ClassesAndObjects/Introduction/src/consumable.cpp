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
    // TODO: write your solution here
}

void ConsumableObject::onCollision(const GameObject &object, const CollisionInfo &info) {
    // TODO: write your solution here
}

const sf::Texture* ConsumableObject::getTexture(TextureManager& textureManager) const {
    // TODO: write your solution here
}
