#ifndef CPPBASICS_CGOBJECT_HPP
#define CPPBASICS_CGOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "gobject.hpp"
#include "circle.hpp"

class CircleGameObject : public GameObject {
public:
    CircleGameObject(Circle circle, sf::Texture* texture);

    Point2D getPosition() const override;

    void setPosition(Point2D position) override;

    Rectangle boundingBox() const override;

    GameObjectState getState() const override;

    void setState(GameObjectState newState) override;

    void draw(sf::RenderWindow &window) const override;

protected:
    Circle circle;
    GameObjectState state;
    sf::Texture* texture;
};

#endif // CPPBASICS_CGOBJECT_HPP
