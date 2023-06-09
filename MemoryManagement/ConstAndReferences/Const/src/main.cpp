#include <iostream>

int main() {

    // (1): definition of pointer to constant variable
    const int x = 5;
    const int* p = &x;

    // (2): pointer to constant cannot be used to re-assign its value
    // *p = 6;

    // (3): ordinary pointer cannot point-to constant
    // int* q = &x;

    // (4): pointer to constant itself can be re-assigned
    const int y = 11;
    p = &y;

    // (5): definition and usage of constant pointer
    int z = 17;
    int* const r = &z;
    *r = 21;
    std::cout << z << "\n";
    // int w = 32;
    // r = &w;

    // (6): definition of constant pointer to constant variable
    const int* const s = &x;
    // *s = 0;
    // s = &y;

    return 0;
}