#include <iostream>

enum Color {
    RED, GREEN, BLUE
};

struct Foo {
    int x;
    char a;
    char b;
    int y;
};

struct FooLayout {
    int x;
    char a;
    char b;
    char _padding[2];
    int y;
};

struct Bar {
    int x;
    char a;
    int y;
    char b;
};

int main() {

    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(Color) << "\n";

    std::cout << sizeof(Foo) << "\n";
    std::cout << alignof(Foo) << "\n";

    std::cout << sizeof(FooLayout) << "\n";
    std::cout << alignof(FooLayout) << "\n";

    std::cout << sizeof(Bar) << "\n";
    std::cout << alignof(Bar) << "\n";

    Bar bar;
    std::cout << (void*) &bar << "\n";
    std::cout << (void*) &(bar.x) << "\n";
    std::cout << (void*) &(bar.a) << "\n";
    std::cout << (void*) &(bar.y) << "\n";
    std::cout << (void*) &(bar.b) << "\n";

    char* p = (char*)&bar;
    p += offsetof(struct Bar, y);
    int* pi = (int*) p;
    * pi = 42;
    std::cout << bar.y << "\n";

    return 0;
}