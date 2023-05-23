#include <iostream>
#include <fstream>
#include <cstdint>
#include <cassert>

int main(int argc, char** argv) {
    assert(argc > 1);
    char* filename = argv[1];
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cout << "Could not open file" << filename << std::endl;
        return 1;
    }

    out << sizeof(int) << std::endl;
    out << sizeof(long) << std::endl;
    out << sizeof(unsigned int) << std::endl;
    out << sizeof(unsigned long) << std::endl;
    out << sizeof(std::int8_t) << std::endl;
    out << sizeof(std::int16_t) << std::endl;
    out << sizeof(std::int32_t) << std::endl;
    out << sizeof(std::int64_t) << std::endl;
    out << sizeof(std::uint8_t) << std::endl;
    out << sizeof(std::uint16_t) << std::endl;
    out << sizeof(std::uint32_t) << std::endl;
    out << sizeof(std::uint64_t) << std::endl;
    out << sizeof(float) << std::endl;
    out << sizeof(double) << std::endl;
    out << sizeof(char) << std::endl;
    out << sizeof(bool) << std::endl;

    out.close();
    return 0;
}