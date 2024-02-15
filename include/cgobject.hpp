#ifndef CPPBASICS_CGOBJECT_HPP
#define CPPBASICS_CGOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "gobject.hpp"
#include "circle.hpp"

/**
 * A class that represents a game object with a circular shape.
 */
class CircleGameObject : public GameObject {
public:

    /**
     * Constructor initializing the object with the provided circle shape.
     */
    explicit CircleGameObject(Circle circle);

    /**
     * Returns position of the circle's center.
     */
    Point2D getPosition() const override;

    /**
     * Returns the current status of the object.
     */
    GameObjectStatus getStatus() const override;

    /**
     * Returns the current shape of the object.
     */
    Circle getCircle() const;

    /**
     * Returns the bounding box of the circle.
     */
    Rectangle getBoundingBox() const override;

    /**
     * Render the object on a window.
     */
    void draw(sf::RenderWindow &window, TextureManager& textureManager) const override;

protected:

    /**
     * Changes position of the circle's center.
     */
    void setPosition(Point2D position) override;

    /**
     * Changes the current status of the object.
     */
    void setStatus(GameObjectStatus newStatus);

private:
    Circle circle;
    GameObjectStatus status;
};

#endif // CPPBASICS_CGOBJECT_HPP
