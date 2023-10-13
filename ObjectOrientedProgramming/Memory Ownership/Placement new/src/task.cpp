#include <new>

class MyObject {
public:
    MyObject() {}
    ~MyObject() {}
};

void createAndDeleteArrayOfObjectsWithPlacementNew() {
    // Allocate a memory region of the appropriate size.
    char* buffer = new char[sizeof(MyObject) * 10];

    // Construct an array of MyObject objects in the memory region using placement new.
    MyObject* objects = new (buffer) MyObject[10];

    // Do something with the objects.

    // Call the destructors on every element of the array.
    for (int i = 0; i < 10; i++) {
        objects[i].~MyObject();
    }

    // Delete the memory region.
    delete[] buffer;
}

int main() {
    createAndDeleteArrayOfObjectsWithPlacementNew();

    return 0;
}