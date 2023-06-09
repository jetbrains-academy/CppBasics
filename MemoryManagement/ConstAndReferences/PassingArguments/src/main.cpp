#include <iostream>

struct Point2D {
    float x;
    float y;
};

// rectangle defined by its top-left
// and bottom-right corner points
struct Rectangle {
    Point2D topLeft;
    Point2D botRight;
};

void scale(Rectangle& rect, float factor) {
    float width = rect.botRight.x - rect.topLeft.x;
    float height = rect.topLeft.y - rect.botRight.y;
    rect.botRight.x = rect.topLeft.x + width * factor;
    rect.botRight.y = rect.topLeft.y - height * factor;
}

void scalePtr(Rectangle* rect, float factor) {
    float width = rect->botRight.x - rect->topLeft.x;
    float height = rect->topLeft.y - rect->botRight.y;
    rect->botRight.x = rect->topLeft.x + width * factor;
    rect->botRight.y = rect->topLeft.y - height * factor;
}

void print(const Rectangle& rect) {
    std::cout << "{ "
              << "{ " << rect.topLeft.x  << ", " << rect.topLeft.y  << "}, "
              << "{ " << rect.botRight.x << ", " << rect.botRight.y << "}"
              << " }";
}

void swap(int a, int b) {
    int c = a;
    a = b;
    b = c;
}

int main() {

    // (1): arguments passed by values are copied
    int a = 5;
    int b = 7;
    swap(a, b);
    std::cout << a << "\n";
    std::cout << b << "\n";

    // (2): size of Rectangle type
    std::cout << sizeof(Rectangle) << "\n";

    // (3): arguments passed by reference are not copied
    //      and can be modified inside called function
    Rectangle rect = { {1, 5}, {6, 3} };
    scale(rect, 2);
    // prints { {1, 5}, {11, 1} }
    print(rect);
    std::cout << "\n";

    return 0;
}