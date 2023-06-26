#include "scene.hpp"

Point2D operator+(Point2D a, Point2D b) {
    return add(a, b);
}

Point2D operator*(float s, Point2D a) {
    return mul(s, a);
}