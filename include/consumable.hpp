#ifndef CPPBASICS_CONSUMABLE_HPP
#define CPPBASICS_CONSUMABLE_HPP

#include "cgobject.hpp"

class ConsumableObject : public CircleGameObject {
public:
    ConsumableObject(Circle circle, sf::Texture *texture);

    Point2D getVelocity() const override;

    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;
};

#endif // CPPBASICS_CONSUMABLE_HPP
