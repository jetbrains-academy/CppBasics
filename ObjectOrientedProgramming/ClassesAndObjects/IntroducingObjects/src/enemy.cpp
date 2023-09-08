#include "enemy.hpp"

#include "utils.hpp"
#include "constants.hpp"

EnemyObject::EnemyObject()
    : CircleGameObject({ { ENEMY_START_X, ENEMY_START_Y }, ENEMY_RADIUS })
{}

Point2D EnemyObject::getVelocity() const {
    return velocity;
}

GameObjectKind EnemyObject::getKind() const {
    return GameObjectKind::ENEMY;
}

const sf::Texture* EnemyObject::getTexture(TextureManager& textureManager) const {
    return textureManager.getTexture(GameTextureID::BLACKHOLE);
}

void EnemyObject::update(sf::Time delta) {
    if (CircleGameObject::getStatus() == GameObjectStatus::DESTROYED)
        return;
    updateTimer += delta;
    if (updateTimer < sf::seconds(1.0f))
        return;
    updateTimer = sf::milliseconds(0.0f);
    velocity = { 0.0f, 0.0f };
    velocity.x = generateBool() ? 1.0f : -1.0f;
    velocity.y = generateBool() ? 1.0f : -1.0f;
    velocity = SPEED * velocity;
}

void EnemyObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    return;
}