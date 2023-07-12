#include "game.hpp"

Point2D adjustToBorders(Point2D position) {
    Point2D result = position;
    if (result.x - RADIUS < WEST_BORDER) {
        result.x = WEST_BORDER + RADIUS;
    }
    if (result.x + RADIUS > EAST_BORDER) {
        result.x = EAST_BORDER - RADIUS;
    }
    if (result.y - RADIUS < NORTH_BORDER) {
        result.y = NORTH_BORDER + RADIUS;
    }
    if (result.y + RADIUS > SOUTH_BORDER) {
        result.y = SOUTH_BORDER - RADIUS;
    }
    return result;
}