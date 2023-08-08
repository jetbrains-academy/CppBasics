#ifndef CPPBASICS_COLLISION_HPP
#define CPPBASICS_COLLISION_HPP

#include "circle.hpp"
#include "gobject.hpp"

struct CollisionInfo {
    bool collide;
    float distance;
    Point2D normalVector;
};

CollisionInfo collision(const Circle& circle1, const Circle& circle2);

bool areApproaching(const Circle& circle1, const Circle& circle2, const CollisionInfo& collisionData);

Point2D calculateResolutionVector(const Circle& circle1, const Circle& circle2,
                                  const CollisionInfo& collisionData, float resolutionFactor = 1.0f);

CollisionInfo collision(const GameObject& object1, const GameObject& object2);

#endif // CPPBASICS_COLLISION_HPP
