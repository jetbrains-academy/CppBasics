#include "../include/int_array.hpp"

int_array create_array(int value, size_t size) {
    if (size == 0) {
        return int_array();
    }
    int_array array = int_array(size);
    for (size_t i = 0; i < size; ++i) {
        array[i] = value;
    }
    return array;
}

int main() {

    std::cout << "create an array 'a' filled with value '1':\n";
    int_array a = create_array(0, 4);
    std::cout << "a = " << a << "\n";
    std::cout << "\n";

    std::cout << "create non-empty arrays 'b' and 'c':\n";
    int_array b = create_array(1, 4);
    int_array c = create_array(2, 4);
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "\n";

    std::cout << "transfer ownership from 'c' to 'b':\n";
    b = std::move(c);
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "\n";

    return 0;
}