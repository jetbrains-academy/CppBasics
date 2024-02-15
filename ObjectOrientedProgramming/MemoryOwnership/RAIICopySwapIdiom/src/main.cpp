#include "../include/int_array.hpp"

int main() {

    std::cout << "create an empty array 'a':\n";
    int_array a;
    std::cout << "a = " << a << "\n";
    std::cout << "\n";

    std::cout << "create a non-empty array 'b':\n";
    int_array b = int_array(10);
    for (size_t i = 0; i < b.size(); ++i) {
        b[i] = (int) i + 1;
    }
    std::cout << "b = " << b << "\n";
    std::cout << "\n";

    std::cout << "create a copy 'c' of array 'b':\n";
    int_array c = b;
    std::cout << "c = " << c << "\n";
    std::cout << "\n";

    std::cout << "modify 'c', check that the original 'b' is left unchanged:\n";
    for (size_t i = 0; i < c.size(); ++i) {
        c[i] = -c[i];
    }
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "\n";

    std::cout << "move data from 'c' to 'b':\n";
    b = std::move(c);
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "\n";

    std::cout << "move data from 'b' to 'a':\n";
    a = std::move(b);
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "\n";

    return 0;
}