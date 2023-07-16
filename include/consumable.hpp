#ifndef CPPBASICS_CONSUMABLE_HPP
#define CPPBASICS_CONSUMABLE_HPP

#include "cgobject.hpp"

class ConsumableObject : public CircleGameObject {
public:
    void onCollision(const GameObject &object, const CollisionData &collisionData) override;
};

#endif // CPPBASICS_CONSUMABLE_HPP
