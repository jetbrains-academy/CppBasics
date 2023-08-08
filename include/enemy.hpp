#ifndef CPPBASICS_ENEMY_HPP
#define CPPBASICS_ENEMY_HPP

#include "cgobject.hpp"

class EnemyObject : public CircleGameObject {
public:
    EnemyObject(Circle circle, sf::Texture* texture);

    Point2D getVelocity() const override;

    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;
};

#endif // CPPBASICS_ENEMY_HPP
