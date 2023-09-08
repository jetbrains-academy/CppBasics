#ifndef CPPBASICS_CGOBJECT_HPP
#define CPPBASICS_CGOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "gobject.hpp"
#include "circle.hpp"

class CircleGameObject : public GameObject {
public:
    CircleGameObject(Circle circle);

    Point2D getPosition() const override;

    void setPosition(Point2D position) override;

    Rectangle getBoundingBox() const override;

    Circle getCircle() const;

    GameObjectStatus getStatus() const override;

    void setStatus(GameObjectStatus newState) override;

    void draw(sf::RenderWindow &window, TextureManager& textureManager) const override;

private:
    Circle circle;
    GameObjectStatus state;
};

#endif // CPPBASICS_CGOBJECT_HPP
