#include "game.hpp"

Point2D getDirection(Direction direction) {
    switch (direction) {
        case North:
            return {  0.0f, -1.0f };
        case East:
            return {  1.0f,  0.0f };
        case South:
            return {  0.0f,  1.0f };
        case West:
            return { -1.0f,  0.0f };
        default:
            return { 0.0f, 0.0f };
    }
}