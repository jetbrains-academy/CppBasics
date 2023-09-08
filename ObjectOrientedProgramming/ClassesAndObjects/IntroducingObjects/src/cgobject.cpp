#include "cgobject.hpp"

#include "operators.hpp"

CircleGameObject::CircleGameObject(Circle circle)
    : circle(circle)
    , status(GameObjectStatus::NORMAL)
{}

Point2D CircleGameObject::getPosition() const {
    return circle.center;
}

void CircleGameObject::setPosition(Point2D position) {
    circle.center = position;
}

GameObjectStatus CircleGameObject::getStatus() const {
    return status;
}

void CircleGameObject::setStatus(GameObjectStatus newStatus) {
    status = newStatus;
}

Circle CircleGameObject::getCircle() const {
    return circle;
}

Rectangle CircleGameObject::getBoundingBox() const {
    Point2D offset = { circle.radius, circle.radius };
    Point2D p1 = circle.center - offset;
    Point2D p2 = circle.center + offset;
    return createRectangle(p1, p2);
}

void CircleGameObject::draw(sf::RenderWindow &window, TextureManager& textureManager) const {
    const sf::Texture* texture = getTexture(textureManager);
    if (texture == nullptr)
        return;
    sf::CircleShape shape;
    shape.setPosition(circle.center.x, circle.center.y);
    shape.setOrigin(circle.radius, circle.radius);
    shape.setRadius(circle.radius);
    shape.setTexture(texture);
    window.draw(shape);
}
