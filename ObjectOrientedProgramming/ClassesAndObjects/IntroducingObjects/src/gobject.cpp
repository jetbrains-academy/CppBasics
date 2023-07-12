#include "gobject.hpp"

void GameObject::move(Point2D vector) {
    setPosition(getPosition() + vector);
}