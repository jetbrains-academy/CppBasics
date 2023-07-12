#ifndef CPPBASICS_RECTANGLE_HPP
#define CPPBASICS_RECTANGLE_HPP

#include "point.hpp"

struct Rectangle {
    Point2D topLeft;
    Point2D botRight;
};

inline bool isEmpty(const Rectangle& rect) {
    return (rect.topLeft.x == rect.botRight.x) || (rect.topLeft.y == rect.botRight.y);
}

inline Rectangle createRectangle(Point2D p1, Point2D p2) {
    Rectangle rect;
    rect.topLeft  = { std::min(p1.x, p2.x), std::min(p1.y, p2.y) };
    rect.botRight = { std::max(p1.x, p2.x), std::max(p1.y, p2.y) };
    return rect;
}

Rectangle fitInto(const Rectangle& rect, const Rectangle& intoRect);

#endif // CPPBASICS_RECTANGLE_HPP
