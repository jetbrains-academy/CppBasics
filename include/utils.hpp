#ifndef CPPBASICS_UTILS_HPP
#define CPPBASICS_UTILS_HPP

#include "point.hpp"
#include "rectangle.hpp"
#include "circle.hpp"


/**
 * Calculates the distance between two 2D points.
 *
 * @param a The first point.
 * @param b The second point.
 * @return The Euclidean distance between the two points.
 */
float distance(Point2D a, Point2D b);


/**
 * Generates a random boolean value with a given probability.
 *
 * @param prob the probability of generating a 'true' value (default is 0.5)
 * @return a random boolean value
 */
bool generateBool(float prob = 0.5f);


/**
 * Generates a random integer between the given minimum and maximum values (inclusive).
 * that is between `min` and `max` (inclusive).
 *
 * @param min The minimum value for the generated integer.
 * @param max The maximum value for the generated integer.
 * @return A random integer between `min` and `max`.
 */
int generateInt(int min, int max);


/**
 * Generates a random float between the given minimum and maximum values (inclusive).
 *
 * @param min The minimum value for the range.
 * @param max The maximum value for the range.
 * @return float A random float value between the minimum and maximum values.
 */
float generateFloat(float min, float max);


/**
 * Generates a random 2D point within the given bounding box.
 *
 * @param boundingBox The rectangle bounding box within which to generate the point.
 * @return Point2D The generated 2D point.
 */
Point2D generatePoint(const Rectangle& boundingBox);


/**
 * Generates a random circle with the given radius inside the specified bounding box.
 *
 * @param radius The radius of the circle to be generated.
 * @param boundingBox The rectangle representing the bounding box.
 * @return Circle The generated circle.
 */
Circle generateCircle(float radius, const Rectangle& boundingBox);


/**
 * Generates a random rectangle inside the specified bounding box.
 *
 * @param boundingBox The bounding box within which the rectangle should be generated.
 * @return The generated rectangle within the bounding box.
 */
Rectangle generateRectangle(const Rectangle& boundingBox);


#endif // CPPBASICS_UTILS_HPP