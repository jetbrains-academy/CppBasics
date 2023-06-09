#include <iostream>

void g() {
    int a = 1;
    int b = 2;
    std::cout << &a << "\n";
    std::cout << &b << "\n";
}

void f() {
    g();
    int c = 3;
    int d = 4;
    std::cout << &c << "\n";
    std::cout << &d << "\n";
}

int main() {
    f();
    return 0;
}