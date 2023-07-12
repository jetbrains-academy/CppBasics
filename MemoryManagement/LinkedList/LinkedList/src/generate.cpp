#include "game.hpp"

#include <cstdlib>

Circle generateCircle(float radius) {
    Circle circle = { { 600, 150 }, radius };
    circle.center.x = generateCoordinate(WEST_BORDER + radius, EAST_BORDER - radius);
    circle.center.y = generateCoordinate(NORTH_BORDER + radius, SOUTH_BORDER - radius);
    return circle;
}

float generateCoordinate(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}
