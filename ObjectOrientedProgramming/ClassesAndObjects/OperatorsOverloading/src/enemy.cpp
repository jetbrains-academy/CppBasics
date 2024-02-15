#include "enemy.hpp"

#include "constants.hpp"
#include "operators.hpp"
#include "utils.hpp"

EnemyObject::EnemyObject()
    : CircleGameObject({ { ENEMY_START_X, ENEMY_START_Y }, ENEMY_RADIUS })
{}

GameObjectKind EnemyObject::getKind() const {
    return GameObjectKind::ENEMY;
}

Point2D EnemyObject::getVelocity() const {
    return velocity;
}

void EnemyObject::update(sf::Time delta) {
    if (CircleGameObject::getStatus() == GameObjectStatus::DESTROYED)
        return;
    updateTimer += delta;
    if (updateTimer < sf::seconds(1.0f))
        return;
    updateTimer = sf::milliseconds(0.0f);
    updateVelocity();
}

void EnemyObject::setVelocity(Point2D velocity) {
    this->velocity = velocity;
}

void EnemyObject::updateVelocity() {
    // TODO: write your solution here
}

void EnemyObject::onCollision(const GameObject &object, const CollisionInfo &info) {
    return;
}

const sf::Texture* EnemyObject::getTexture(TextureManager& textureManager) const {
    // TODO: write your solution here
    return nullptr;
}
