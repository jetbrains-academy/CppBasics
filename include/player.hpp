#ifndef CPPBASICS_PLAYER_HPP
#define CPPBASICS_PLAYER_HPP

#include "cgobject.hpp"

class PlayerObject : public CircleGameObject {
public:
    void onCollision(const GameObject &object, const CollisionData &collisionData) override;
};

#endif // CPPBASICS_PLAYER_HPP
