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

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(Color) << std::endl;

    std::cout << sizeof(Foo) << std::endl;
    std::cout << alignof(Foo) << std::endl;

    std::cout << sizeof(FooLayout) << std::endl;
    std::cout << alignof(FooLayout) << std::endl;

    std::cout << sizeof(Bar) << std::endl;
    std::cout << alignof(Bar) << std::endl;

    Bar bar;
    std::cout << (void*) &bar << std::endl;
    std::cout << (void*) &(bar.x) << std::endl;
    std::cout << (void*) &(bar.a) << std::endl;
    std::cout << (void*) &(bar.y) << std::endl;
    std::cout << (void*) &(bar.b) << std::endl;

    return 0;
}