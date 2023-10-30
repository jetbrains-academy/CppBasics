#include <memory>
#include <iostream>

std::unique_ptr<int> *create_unique_ptr_array(int size) {
    std::unique_ptr<int> *array = new std::unique_ptr<int>[size];
    for (int i = 0; i < size; i++) {
        array[i] = std::make_unique<int>();
    }
    return array;
}

int main() {
    std::unique_ptr<int> *array = create_unique_ptr_array(10);
    for (int i = 0; i < 10; i++) {
        *array[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << *array[i] << std::endl;
    }
    delete[] array;

    return 0;
}