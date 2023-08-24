#ifndef CPPBASICS_UTILS_HPP
#define CPPBASICS_UTILS_HPP

#include "point.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

float distance(Point2D a, Point2D b);

float generateFloat(float min, float max);

bool generateBool(float prob = 0.5f);

Point2D generatePoint(const Rectangle& boundingBox);

Circle generateCircle(float radius, const Rectangle& boundingBox);

#endif // CPPBASICS_UTILS_HPP
