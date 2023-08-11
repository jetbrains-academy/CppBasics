#include "utils.hpp"

#include <cstdlib>

// TODO: move `distance` here

float generateFloat(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

bool generateBool(float prob) {
    return generateFloat(0.0f, 1.0f) < prob;
}