#include "utils.hpp"

#include <cstdlib>

// TODO: move `distance` here

float generateFloat(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

bool generateBool(float prob) {
    return generateFloat(0.0f, 1.0f) < prob;
}

Point2D generatePoint(const Rectangle& boundingBox) {
    Point2D point = { 0.0f, 0.0f, };
    point.x = generateFloat(boundingBox.topLeft.x, boundingBox.botRight.x);
    point.y = generateFloat(boundingBox.topLeft.y, boundingBox.botRight.y);
    return point;
}

Circle generateCircle(float radius, const Rectangle& boundingBox) {
    Circle circle = { { 0.0f, 0.0f }, 0.0f };
    if (radius > std::min(width(boundingBox), height(boundingBox))) {
        return circle;
    }
    // TODO: replace with rectangle arithmetics operators?
    circle.center.x = generateFloat(
        boundingBox.topLeft.x + radius,
        boundingBox.botRight.x - radius
    );
    circle.center.y = generateFloat(
        boundingBox.topLeft.x + radius,
        boundingBox.botRight.x - radius
    );
    circle.radius = radius;
    return circle;
}