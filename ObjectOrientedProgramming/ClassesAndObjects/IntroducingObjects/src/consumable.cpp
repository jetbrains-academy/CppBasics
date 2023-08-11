#include "consumable.hpp"

#include "constants.hpp"

ConsumableObject::ConsumableObject() {
    circle = { { CONSUMABLE_START_X, CONSUMABLE_START_Y }, CONSUMABLE_RADIUS };
}

Point2D ConsumableObject::getVelocity() const {
    return { 0.0f, 0.0f };
}

const sf::Texture* ConsumableObject::getTexture(TextureManager& textureManager) const {
    switch (state) {
        case LIVE:
            return textureManager.getTexture(GameTextureID::STAR);
        // case DEAD:
        //     // TODO: return empty texture instead (?)
        //     return nullptr;
    }
    return nullptr;
}

void ConsumableObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    if (collisionData.collide) {
        CircleGameObject::setState(DEAD);
    }
}