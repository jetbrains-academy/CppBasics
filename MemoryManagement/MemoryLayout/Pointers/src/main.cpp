#include <iostream>

int main() {

    int a = 42;
    int* p = &a;

    int b = *p;
    std::cout << b << "\n";

    std::cout << p << "\n";
    std::cout << *p << "\n";

    *p = 23;
    std::cout << *p << "\n";
    std::cout << a << "\n";
    std::cout << b << "\n";

    int* q = p;
    std::cout << "p = " << p << ", *p = " << *p << "\n";
    std::cout << "q = " << q << ", *q = " << *q << "\n";

    int c = 23;
    p = &c;
    std::cout << "p = " << p << ", *p = " << *p << "\n";
    std::cout << "q = " << q << ", *q = " << *q << "\n";

    return 0;
}