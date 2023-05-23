#include <iostream>

int main() {

    int a = 42;
    int* p = &a;

    int b = *p;
    std::cout << b << std::endl;

    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    *p = 23;
    std::cout << *p << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    int* q = p;
    std::cout << "p = " << p << ", *p = " << *p << std::endl;
    std::cout << "q = " << q << ", *q = " << *q << std::endl;

    int c = 23;
    p = &c;
    std::cout << "p = " << p << ", *p = " << *p << std::endl;
    std::cout << "q = " << q << ", *q = " << *q << std::endl;

    return 0;
}