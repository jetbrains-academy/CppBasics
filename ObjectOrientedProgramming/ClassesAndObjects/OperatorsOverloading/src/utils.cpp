#include "utils.hpp"

#include <cstdlib>
#include <cmath>
#include <algorithm>

float distance(Point2D a, Point2D b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

float generateFloat(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

int generateInt(int min, int max) {
    return min + rand() % (max - min + 1);
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

Rectangle generateRectangle(const Rectangle& boundingBox) {
    return createRectangle(generatePoint(boundingBox), generatePoint(boundingBox));
}