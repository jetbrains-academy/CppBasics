#include <iostream>

int* escape() {
    int a = 42;
    return &a;
}

void escapeCaller() {
    int* p = escape();
    std::cout << (void*) p << "\n";
}

void leak() {
    char* p = (char*) malloc(8);
    std::cout << (void*) p << "\n";
}

int main() {
    // (1): address escape
    escapeCaller();

    // (2): out-of-bounds accesses
    char* a = (char*) malloc(8);
    *(a + 2) = 1;
    *(a + 9) = 2;
    *(a - 1) = 3;

    free(a);

    // (3): memory leak
    leak();

    // (4): use after free
    char* p = (char*) malloc(8);
    free(p);
    *p = 7;

    // (5): double free
    char* q = (char*) malloc(8);
    free(q);
    free(q);

    return 0;
}