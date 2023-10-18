#include <iostream>

void createAndDeleteObject() {
    // Create an integer object using the new operator.
    int* p = new int();

    // Assign any value to the object.
    *p = 42;

    // Delete the object using the delete operator.
    delete p;
}