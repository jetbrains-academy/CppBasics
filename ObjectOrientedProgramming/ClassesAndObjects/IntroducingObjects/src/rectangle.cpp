#include "rectangle.hpp"

#include "operators.hpp"

Point2D center(const Rectangle& rect) {
    // TODO: explain this C++ initialization syntax
    return rect.topLeft + 0.5f * Point2D { width(rect), height(rect) };
}

Rectangle createRectangle(Point2D p1, Point2D p2) {
    Rectangle rect;
    rect.topLeft  = { std::min(p1.x, p2.x), std::min(p1.y, p2.y) };
    rect.botRight = { std::max(p1.x, p2.x), std::max(p1.y, p2.y) };
    return rect;
}

Rectangle fitInto(const Rectangle& rect, const Rectangle& intoRect) {
    if (width(rect) > width(intoRect) || height(rect) > height(intoRect)) {
        return rect;
    }
    Point2D vector = { 0.0f, 0.0f };
    if (rect.topLeft.x < intoRect.topLeft.x) {
        vector.x += intoRect.topLeft.x - rect.topLeft.x;
    }
    if (rect.topLeft.y < intoRect.topLeft.y) {
        vector.y += intoRect.topLeft.y - rect.topLeft.y;
    }
    if (rect.botRight.x > intoRect.botRight.x) {
        vector.x += intoRect.botRight.x - rect.botRight.x;
    }
    if (rect.botRight.y > intoRect.botRight.y) {
        vector.y += intoRect.botRight.y - rect.botRight.y;
    }
    return rect + vector;
}