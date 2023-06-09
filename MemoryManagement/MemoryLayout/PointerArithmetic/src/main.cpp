#include <iostream>

int main() {
    const int SIZE = 10;
    char a[SIZE] = "abcdefgh";

    char* p0 = &a[0];
    std::cout << *p0 << "\n";

    char* p1 = p0 + 1;
    std::cout << *p1 << "\n";
    std::cout << *(p0 + 1) << "\n";

    char* p = p0;
    ++p;
    std::cout << *p << "\n";

    std::cout << *(p0 + 5) << "\n";

    // std::cout << *(p0 + 20) << "\n";

    char* q = p1 - 1;
    std::cout << *q << "\n";

    char* p8 = p0 + 8;
    int diff = p8 - p0;
    std::cout << diff << "\n";

    int b[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7 };

    int* r = &b[0];
    ++r;
    std::cout << *r << "\n";

    return 0;
}