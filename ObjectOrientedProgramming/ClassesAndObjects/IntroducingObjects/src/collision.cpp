#include <cmath>

#include "collision.hpp"
#include "operators.hpp"
#include "utils.hpp"

CollisionData collision(const Circle& circle1, const Circle& circle2) {
    float dx = circle2.center.x - circle1.center.x;
    float dy = circle2.center.y - circle1.center.y;
    float dist = sqrt(dx * dx + dy * dy);
    Point2D d = { dx, dy };
    CollisionData collisionData;
    collisionData.collide = (dist < circle1.radius + circle2.radius);
    collisionData.distance = dist;
    collisionData.normalVector = (1 / dist) * d;
    return collisionData;
}

bool areApproaching(const Circle& circle1, const Circle& circle2, const CollisionData& collisionData) {
    return collisionData.distance < 3 * circle1.radius + circle2.radius;
}

Point2D calculateResolutionVector(const Circle& circle1, const Circle& circle2,
                                  const CollisionData& collisionData, float resolutionFactor) {
    Point2D border1 = circle1.center + circle1.radius * collisionData.normalVector;
    Point2D border2 = circle2.center - circle2.radius * collisionData.normalVector;
    float dist = distance(border1, border2);
    return -(dist * resolutionFactor) * collisionData.normalVector;
}
