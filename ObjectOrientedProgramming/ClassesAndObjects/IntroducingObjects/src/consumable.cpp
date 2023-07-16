#include "consumable.hpp"

void ConsumableObject::onCollision(const GameObject &object, const CollisionData &collisionData) {
    if (collisionData.collide) {
        CircleGameObject::setState(DEAD);
    }
}