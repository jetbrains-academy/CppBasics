#include "enemy.hpp"

EnemyObject::EnemyObject(Circle circle, sf::Texture *texture)
    : CircleGameObject(circle, texture)
{}

Point2D EnemyObject::getVelocity() const {
    return { 0.0f, 0.0f };
}

void EnemyObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    return;
}