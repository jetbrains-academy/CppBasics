#ifndef CPPBASICS_COLLISION_HPP
#define CPPBASICS_COLLISION_HPP

#include "circle.hpp"

/**
 * This structure provides a way to store information about a collision,
 * such as whether a collision occurred and the distance between colliding objects.
 */
struct CollisionInfo {
    bool collide;
    float distance;
};

/**
 * This function takes in two Circle objects and calculates the collision information between them.
 */
CollisionInfo collisionInfo(const Circle& circle1, const Circle& circle2);

#endif // CPPBASICS_COLLISION_HPP
