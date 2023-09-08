#ifndef CPPBASICS_CGOBJECT_HPP
#define CPPBASICS_CGOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "gobject.hpp"
#include "circle.hpp"

class CircleGameObject : public GameObject {
public:
    explicit CircleGameObject(Circle circle);

    Point2D getPosition() const override;

    void setPosition(Point2D position) override;

    GameObjectStatus getStatus() const override;

    void setStatus(GameObjectStatus newStatus) override;

    Circle getCircle() const;

    Rectangle getBoundingBox() const override;

    void draw(sf::RenderWindow &window, TextureManager& textureManager) const override;

private:
    Circle circle;
    GameObjectStatus status;
};

#endif // CPPBASICS_CGOBJECT_HPP
