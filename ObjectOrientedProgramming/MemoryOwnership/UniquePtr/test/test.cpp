#include <gtest/gtest.h>
#include <memory>
#include <iostream>

std::unique_ptr<int> *create_unique_ptr_array(int size);

TEST(CreateUniquePtrArrayTest, Simple) {
    std::unique_ptr<int> *array = create_unique_ptr_array(10);
    for (int i = 0; i < 10; i++) {
        *array[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << *array[i] << std::endl;
    }
    delete[] array;
}