#ifndef CPPBASICS_CGOBJECT_HPP
#define CPPBASICS_CGOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "gobject.hpp"
#include "circle.hpp"

class CircleGameObject : public GameObject {
public:
    CircleGameObject();

    Point2D getPosition() const override;

    void setPosition(Point2D position) override;

    Rectangle boundingBox() const override;

    Circle getCircle() const;

    GameObjectState getState() const override;

    void setState(GameObjectState newState) override;

    void draw(sf::RenderWindow &window, TextureManager& textureManager) const override;

// TODO: make private
protected:
    Circle circle;
    GameObjectState state;
};

#endif // CPPBASICS_CGOBJECT_HPP
