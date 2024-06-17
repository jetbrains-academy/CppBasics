#include "gobject.hpp"

#include "operators.hpp"

void GameObject::move(Point2D vector) {
    setPosition(getPosition() + vector);
}