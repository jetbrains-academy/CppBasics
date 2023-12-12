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

inline float width(const Rectangle& rect) {
    return rect.botRight.x - rect.topLeft.x;
}

inline float height(const Rectangle& rect) {
    return rect.botRight.y - rect.topLeft.y;
}

inline bool isInRectangle(Point2D p, const Rectangle& rect) {
    return (rect.topLeft.x <= p.x)  && (rect.topLeft.y <= p.y)  &&
           (p.x <= rect.botRight.x) && (p.y <= rect.botRight.y);
}

Point2D center(const Rectangle& rect);

Rectangle createRectangle(Point2D p1, Point2D p2);

Rectangle fitInto(const Rectangle& rect, const Rectangle& intoRect);

#endif // CPPBASICS_RECTANGLE_HPP
