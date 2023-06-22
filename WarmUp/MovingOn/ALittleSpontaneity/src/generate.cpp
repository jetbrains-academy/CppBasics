#include "scene.hpp"

#include <cstdlib>

Circle generateCircle(float radius) {
    Circle circle = { { 0, 0 }, 0 };
    circle.center.x = generateCoordinate(WEST_BORDER + radius, EAST_BORDER - radius);
    circle.center.y = generateCoordinate(NORTH_BORDER + radius, SOUTH_BORDER - radius);
    circle.radius = radius;
    return circle;
}

float generateCoordinate(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}
