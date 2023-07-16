#ifndef CPPBASICS_ENEMY_HPP
#define CPPBASICS_ENEMY_HPP

#include "cgobject.hpp"

class EnemyObject : public CircleGameObject {
public:
    void onCollision(const GameObject &object, const CollisionData &collisionData) override;
};

#endif // CPPBASICS_ENEMY_HPP
