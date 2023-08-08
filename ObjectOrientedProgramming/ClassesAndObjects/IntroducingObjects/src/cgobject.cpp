#include "cgobject.hpp"

#include "operators.hpp"

CircleGameObject::CircleGameObject(Circle circle, sf::Texture *texture)
    : circle(circle)
    , state(LIVE)
    , texture(texture)
{}

Point2D CircleGameObject::getPosition() const {
    return circle.center;
}

void CircleGameObject::setPosition(Point2D position) {
    circle.center = position;
}

Rectangle CircleGameObject::boundingBox() const {
    Point2D offset = { circle.radius, circle.radius };
    Point2D p1 = circle.center - offset;
    Point2D p2 = circle.center + offset;
    return createRectangle(p1, p2);
}

Circle CircleGameObject::getCircle() const {
    return circle;
}

GameObjectState CircleGameObject::getState() const {
    return state;
}

void CircleGameObject::setState(GameObjectState newState) {
    state = newState;
}

void CircleGameObject::draw(sf::RenderWindow &window) const {
    sf::CircleShape shape;
    shape.setPosition(circle.center.x, circle.center.y);
    shape.setOrigin(circle.center.x, circle.center.y);
    shape.setRadius(circle.radius);
    shape.setTexture(texture);
    window.draw(shape);
}
