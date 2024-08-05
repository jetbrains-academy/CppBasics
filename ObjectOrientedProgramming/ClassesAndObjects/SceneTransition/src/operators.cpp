#include "game.hpp"

Point2D operator+(Point2D a, Point2D b) {
    return add(a, b);
}

Point2D operator-(Point2D a) {
    return { -a.x, -a.y };
}

Point2D operator-(Point2D a, Point2D b) {
    return add(a, -b);
}

Point2D operator*(float s, Point2D a) {
    return mul(s, a);
}

Circle operator+(Circle c, Point2D v) {
    return { c.center + v, c.radius };
}

Circle operator-(Circle c, Point2D v) {
    return { c.center - v, c.radius };
}

Rectangle operator+(Rectangle r, Point2D v) {
    return { r.topLeft + v, r.botRight + v };
}

Rectangle operator-(Rectangle r, Point2D v) {
    return { r.topLeft - v, r.botRight - v };
}

Circle operator*(float s, Circle c) {
    return { c.center, s * c.radius };
}

Rectangle operator*(float s, Rectangle r) {
    Point2D v = { width(r), height(r) };
    return { r.topLeft, r.topLeft + s * v };
}