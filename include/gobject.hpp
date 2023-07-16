#ifndef CPPBASICS_GOBJECT_HPP
#define CPPBASICS_GOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "rectangle.hpp"
#include "collision.hpp"

enum GameObjectState {
    LIVE, DEAD
};

class GameObject {
public:

    void move(Point2D vector);

    virtual Point2D getPosition() const = 0;

    virtual void setPosition(Point2D position) = 0;

    virtual Rectangle boundingBox() const = 0;

    virtual GameObjectState getState() const = 0;

    virtual void setState(GameObjectState newState) = 0;

    virtual void draw(sf::RenderWindow& window) const = 0;

    virtual void onCollision(const GameObject& object, const CollisionData& collisionData) = 0;

    virtual ~GameObject() {}

};

#endif // CPPBASICS_GOBJECT_HPP
