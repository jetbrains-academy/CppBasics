#include <cassert>

#include "collision.hpp"
#include "cgobject.hpp"
#include "utils.hpp"

CollisionInfo collisionInfo(const Circle& circle1, const Circle& circle2) {
    CollisionInfo info;
    info.distance = distance(circle1.center, circle2.center);
    info.collide = (info.distance < circle1.radius + circle2.radius);
    return info;
}

CollisionInfo collisionInfo(const GameObject& object1, const GameObject& object2) {
    const CircleGameObject* circleObject1 = dynamic_cast<const CircleGameObject*>(&object1);
    const CircleGameObject* circleObject2 = dynamic_cast<const CircleGameObject*>(&object2);
    if (circleObject1 && circleObject2) {
        return collisionInfo(circleObject1->getCircle(), circleObject2->getCircle());
    }
    assert(false);
}
