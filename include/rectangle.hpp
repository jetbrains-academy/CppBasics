#ifndef CPPBASICS_RECTANGLE_HPP
#define CPPBASICS_RECTANGLE_HPP

#include "point.hpp"
#include "operators.hpp"

struct Rectangle {
    Point2D topLeft;
    Point2D botRight;
};

inline bool isEmpty(const Rectangle& rect) {
    return (rect.topLeft.x == rect.botRight.x) || (rect.topLeft.y == rect.botRight.y);
}

inline float width(const Rectangle& rect) {
    return rect.botRight.x - rect.topLeft.x;
}

inline float height(const Rectangle& rect) {
    return rect.botRight.y - rect.topLeft.y;
}

inline Point2D center(const Rectangle& rect) {
    // TODO: explain this C++ initialization syntax
    return 0.5f * Point2D { width(rect), height(rect) };
}

inline Rectangle createRectangle(Point2D p1, Point2D p2) {
    Rectangle rect;
    rect.topLeft  = { std::min(p1.x, p2.x), std::min(p1.y, p2.y) };
    rect.botRight = { std::max(p1.x, p2.x), std::max(p1.y, p2.y) };
    return rect;
}

Rectangle fitInto(const Rectangle& rect, const Rectangle& intoRect);

#endif // CPPBASICS_RECTANGLE_HPP
