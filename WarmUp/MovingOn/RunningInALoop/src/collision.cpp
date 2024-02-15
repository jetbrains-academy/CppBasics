#include <cmath>

#include "game.hpp"

float distance(Point2D a, Point2D b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

bool collision(Circle circle1, Circle circle2) {
    return distance(circle1.center, circle2.center) < circle1.radius + circle2.radius;
}