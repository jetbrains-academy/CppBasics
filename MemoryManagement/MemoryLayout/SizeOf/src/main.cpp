#include <iostream>
#include <cstdint>

int main() {
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(bool) << std::endl;
    std::cout << sizeof(std::int8_t) << std::endl;
    std::cout << sizeof(std::int16_t) << std::endl;
    std::cout << sizeof(std::int32_t) << std::endl;
    std::cout << sizeof(std::int64_t) << std::endl;
    return 0;
}