#include "../include/int_array.hpp"

int main() {

    std::cout << "create a non-empty array 'a':\n";
    int_array a = int_array(10);
    for (size_t i = 0; i < a.size(); ++i) {
        a[i] = (int) i + 1;
    }
    std::cout << "a = " << a << "\n";
    std::cout << "\n";

    std::cout << "create a copy 'b' of array 'a':\n";
    int_array b(a);
    std::cout << "b = " << b << "\n";
    std::cout << "\n";

    std::cout << "modify 'b', check that the original 'a' is left unchanged:\n";
    for (size_t i = 0; i < b.size(); ++i) {
        b[i] = -b[i];
    }
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "\n";

    std::cout << "create another non-empty array 'c':\n";
    int_array c = int_array(4);
    for (size_t i = 0; i < c.size(); ++i) {
        c[i] = 0;
    }
    std::cout << "c = " << c << "\n";
    std::cout << "\n";

    std::cout << "re-assign 'c' to the copy of 'a':\n";
    c = a;
    std::cout << "a = " << a << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "\n";

    return 0;
}