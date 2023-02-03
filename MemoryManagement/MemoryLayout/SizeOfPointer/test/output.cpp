#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char** argv) {
    assert(argc > 1);
    char* filename = argv[1];
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cout << "Could not open file" << filename << std::endl;
        return 1;
    }

    out << sizeof(char*) << std::endl;
    out << sizeof(size_t) << std::endl;
    out << sizeof(ptrdiff_t) << std::endl;

    out.close();
    return 0;
}