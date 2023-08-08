#ifndef CPPBASICS_PLAYER_HPP
#define CPPBASICS_PLAYER_HPP

#include "cgobject.hpp"

class PlayerObject : public CircleGameObject {
public:
    PlayerObject(Circle circle, sf::Texture* texture);

    Point2D getVelocity() const override;

    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;
};

#endif // CPPBASICS_PLAYER_HPP
