#include <iostream>

int main() {

    // (1): casting double to int with static_cast
    double pi = 3.14;
    int a = static_cast<int>(pi);
    std::cout << a << "\n";

    // (2): enum to int conversion with static_cast
    enum Color { RED, GREEN, BLUE };
    int red_code    = static_cast<int>(RED);
    int green_code  = static_cast<int>(GREEN);
    int blue_code   = static_cast<int>(BLUE);
    std::cout << red_code << ", " << green_code << ", " << blue_code << "\n";

    // (3): most pointer casts are forbidden by static_cast ...
    void*  q = malloc(2 * sizeof(int));
    int*  qi = static_cast<int*> (q);
    // char* qc = static_cast<char*>(qi);

    // (4): ... but allowed with reinterpret_cast
    char* qr = reinterpret_cast<char*>(qi);

    // (5): unsafe reinterpret_cast from void* to int* resulting in undefined behavior
    void* r = malloc(2);
    int* ri = reinterpret_cast<int*>(r);
    ri[0] = 42;

    return 0;
}