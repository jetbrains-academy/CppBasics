#include "consumable.hpp"

ConsumableObject::ConsumableObject(Circle circle, sf::Texture *texture)
    : CircleGameObject(circle, texture)
{}

Point2D ConsumableObject::getVelocity() const {
    return { 0.0f, 0.0f };
}

void ConsumableObject::onCollision(const GameObject &object, const CollisionInfo &collisionData) {
    if (collisionData.collide) {
        CircleGameObject::setState(DEAD);
    }
}