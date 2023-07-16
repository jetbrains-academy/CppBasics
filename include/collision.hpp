#ifndef CPPBASICS_COLLISION_HPP
#define CPPBASICS_COLLISION_HPP

#include "circle.hpp"

struct CollisionData {
    bool collide;
    float distance;
    Point2D normalVector;
};

CollisionData collision(const Circle& circle1, const Circle& circle2);

bool areApproaching(const Circle& circle1, const Circle& circle2, const CollisionData& collisionData);

Point2D calculateResolutionVector(const Circle& circle1, const Circle& circle2,
                                  const CollisionData& collisionData, float resolutionFactor = 1.0f);

#endif // CPPBASICS_COLLISION_HPP
