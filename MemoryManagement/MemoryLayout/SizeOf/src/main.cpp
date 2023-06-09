#include <iostream>
#include <cstdint>

int main() {
    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(long) << "\n";
    std::cout << sizeof(unsigned int) << "\n";
    std::cout << sizeof(unsigned long) << "\n";
    std::cout << sizeof(std::int8_t) << "\n";
    std::cout << sizeof(std::int16_t) << "\n";
    std::cout << sizeof(std::int32_t) << "\n";
    std::cout << sizeof(std::int64_t) << "\n";
    std::cout << sizeof(std::uint8_t) << "\n";
    std::cout << sizeof(std::uint16_t) << "\n";
    std::cout << sizeof(std::uint32_t) << "\n";
    std::cout << sizeof(std::uint64_t) << "\n";
    std::cout << sizeof(float) << "\n";
    std::cout << sizeof(double) << "\n";
    std::cout << sizeof(char) << "\n";
    std::cout << sizeof(bool) << "\n";
    return 0;
}