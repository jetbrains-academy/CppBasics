#ifndef CPPBASICS_OPERATORS_HPP
#define CPPBASICS_OPERATORS_HPP

#include <iostream>

#include "point.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "collision.hpp"
#include "direction.hpp"
#include "enums.hpp"

Point2D operator+(Point2D a, Point2D b);
Point2D operator-(Point2D a, Point2D b);
Point2D operator-(Point2D a);
Point2D operator*(float s, Point2D a);

Circle operator+(Circle c, Point2D v);
Circle operator-(Circle c, Point2D v);
Circle operator*(float s, Circle c);

Rectangle operator+(Rectangle r, Point2D v);
Rectangle operator-(Rectangle r, Point2D v);
Rectangle operator*(float s, Rectangle r);

inline std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

inline std::istream& operator>>(std::istream& is, Point2D& p) {
    return is >> p.x >> p.y;
}

inline std::ostream& operator<<(std::ostream& os, const Circle& c) {
    return os << "{ " << "center: " << c.center << "; radius: " << c.radius << " }";
}

inline std::istream& operator>>(std::istream& is, Circle& c) {
    return is >> c.center >> c.radius;
}

inline std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    return os << "{ " << "top-left: " << r.topLeft << "; bottom-right: " << r.botRight << " }";
}

inline std::istream& operator>>(std::istream& is, Rectangle& r) {
    return is >> r.topLeft >> r.botRight;
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

inline std::string to_string(GameObjectKind kind) {
    switch (kind) {
        case GameObjectKind::PLAYER:
            return "GameObjectKind::PLAYER";
        case GameObjectKind::CONSUMABLE:
            return "GameObjectKind::CONSUMABLE";
        case GameObjectKind::ENEMY:
            return "GameObjectKind::ENEMY";
        default:
            return "";
    }
}

inline std::ostream& operator<<(std::ostream& os, GameObjectKind kind) {
    return os << to_string(kind);
}

inline std::string to_string(GameObjectStatus status) {
    switch (status) {
        case GameObjectStatus::NORMAL:
            return "GameObjectStatus::NORMAL";
        case GameObjectStatus::WARNED:
            return "GameObjectStatus::WARNED";
        case GameObjectStatus::DESTROYED:
            return "GameObjectStatus::DESTROYED";
        default:
            return "";
    }
}

inline std::ostream& operator<<(std::ostream& os, GameObjectStatus status) {
    return os << to_string(status);
}

inline std::ostream& operator<<(std::ostream& os, const CollisionInfo& info) {
    return os << "CollisionInfo = { " << "collide: " << info.collide << "; distance: " << info.distance << " }";
}

#endif // CPPBASICS_OPERATORS_HPP
