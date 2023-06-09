#include <iostream>

int main() {

    // (1): definition of reference
    int x = 1;
    int& r = x;

    // (2): usage of reference
    r = 2;
    std::cout << r << "\n";
    std::cout << x << "\n";

    // (3): definition of reference to constant
    const int& cr = x;
    std::cout << cr << "\n";
    // cr = 3;

    // (4): reference should be initialized
    // int& s;

    // (5): reference cannot be initialized with nullptr
    // int& s = nullptr;

    // (6): reference does not have its own memory address
    std::cout << &x << "\n";
    std::cout << &r << "\n";

    // Put your code here
    return 0;
}