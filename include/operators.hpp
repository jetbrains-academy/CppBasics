#ifndef CPPBASICS_OPERATORS_HPP
#define CPPBASICS_OPERATORS_HPP

#include <iostream>

#include "point.hpp"

inline std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

inline std::ostream& operator<<(std::ostream& os, const Circle& c) {
    return os << "{ " << "center: " << c.center << "; radius: " << c.radius << " }";
}

inline std::string to_string(Direction direction) {
    switch (direction) {
        case North:
            return "North";
        case East:
            return "East";
        case South:
            return "South";
        case West:
            return "West";
        default:
            return "";
    }
}

inline std::ostream& operator<<(std::ostream& os, Direction direction) {
    return os << to_string(direction);
}

#endif // CPPBASICS_OPERATORS_HPP
