#include "cgobject.hpp"

#include "operators.hpp"

Point2D CircleGameObject::getPosition() const {
    return shape.center;
}

Point2D CircleGameObject::setPosition(Point2D position) {
    shape.center = position;
}

Rectangle CircleGameObject::boundingBox() const {
    Point2D offset = { shape.radius, shape.radius };
    Point2D p1 = shape.center - offset;
    Point2D p2 = shape.center + offset;
    return createRectangle(p1, p2);
}
