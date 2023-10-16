#ifndef CPPBASICS_COLLISION_HPP
#define CPPBASICS_COLLISION_HPP

#include "circle.hpp"

struct CollisionInfo {
    bool collide;
    float distance;
};

CollisionInfo collisionInfo(const Circle& circle1, const Circle& circle2);

#endif // CPPBASICS_COLLISION_HPP
