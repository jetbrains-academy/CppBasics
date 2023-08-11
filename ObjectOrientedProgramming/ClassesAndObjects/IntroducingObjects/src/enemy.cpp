#include "enemy.hpp"

#include "constants.hpp"

EnemyObject::EnemyObject() {
    circle = { { ENEMY_START_X, ENEMY_START_Y }, ENEMY_RADIUS };
}

Point2D EnemyObject::getVelocity() const {
    return { 0.0f, 0.0f };
}

const sf::Texture* EnemyObject::getTexture(TextureManager& textureManager) const {
    return textureManager.getTexture(GameTextureID::BLACK_HOLE);
}

void EnemyObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    return;
}