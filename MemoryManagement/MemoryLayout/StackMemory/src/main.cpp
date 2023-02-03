#include <iostream>

void g() {
    int a = 1;
    int b = 2;
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
}

void f() {
    g();
    int c = 3;
    int d = 4;
    std::cout << &c << std::endl;
    std::cout << &d << std::endl;
}

int main() {
    f();
    return 0;
}