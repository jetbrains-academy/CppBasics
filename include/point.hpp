#ifndef CPPBASICS_POINT_HPP
#define CPPBASICS_POINT_HPP

struct Point2D {
    float x;
    float y;
};

Point2D add(Point2D a, Point2D b);

Point2D mul(float s, Point2D a);

Point2D move(Point2D position, Point2D velocity, float delta);

#endif // CPPBASICS_POINT_HPP
