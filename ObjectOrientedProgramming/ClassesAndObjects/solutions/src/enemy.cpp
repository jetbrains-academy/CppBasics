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

void EnemyObject::updateVelocity() {
    Direction direction1 = static_cast<Direction>(generateInt(0, 3));
    Direction direction2 = static_cast<Direction>(generateInt(0, 3));
    Point2D directionVector = (direction1 == direction2)
        ? getDirection(direction1)
        : (getDirection(direction1) + getDirection(direction2));
    velocity = SPEED * directionVector;
}

void EnemyObject::onCollision(const GameObject &object, const CollisionInfo &info) {
    return;
}

const sf::Texture* EnemyObject::getTexture(TextureManager& textureManager) const {
    return textureManager.getTexture(GameTextureID::BLACKHOLE);
}
