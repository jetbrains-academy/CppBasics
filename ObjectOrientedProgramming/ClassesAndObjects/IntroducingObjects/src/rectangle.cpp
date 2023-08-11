#include "rectangle.hpp"

#include "operators.hpp"

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
    // TODO: implement operators for Rectangle (and Circle) ?
    return { rect.topLeft + vector, rect.botRight + vector };
}