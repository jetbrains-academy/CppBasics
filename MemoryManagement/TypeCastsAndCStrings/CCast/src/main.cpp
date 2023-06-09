#include <iostream>
#include <cmath>

int main() {

    // (1): implicit conversion from int to double
    int x = 4;
    std::cout << sqrt(x) << "\n";

    // (2): implicit conversion from double to int
    double pi = 3.14;
    int a = pi;
    std::cout << a << "\n";

    // (3): C style cast from void* to int*
    void* q = malloc(2 * sizeof(int));
    int* qi = (int*) q;
    qi[0] = 42;

    // (4): unsafe C style cast from void* to int* resulting in undefined behavior
    void* r = malloc(2);
    int* ri = (int*) r;
    ri[0] = 42;

    return 0;
}