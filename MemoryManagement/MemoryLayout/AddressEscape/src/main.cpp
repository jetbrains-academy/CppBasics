#include <iostream>

void callee(int* p) {
    std::cout << p << " -> " << *p << std::endl;
}

void caller() {
    int a = 42;
    callee(&a);
}

int* escape() {
    int a = 42;
    return &a;
}

void escapeCaller() {
    int* p = escape();
    std::cout << p << " -> " << *p << std::endl;
}

int* q = nullptr;

void escapeGlobal() {
    int a = 42;
    q = &a;
}

void escapeGlobalCaller() {
    escapeGlobal();
    std::cout << q << " -> " << *q << std::endl;
}

int main() {
    caller();
    escapeCaller();
    escapeGlobalCaller();
    return 0;
}