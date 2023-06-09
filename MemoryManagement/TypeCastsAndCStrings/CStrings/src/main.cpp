#include <iostream>
#include <cstring>
#include <string>

int main() {

    // (1): declaring and printing C style string
    const char* greetings = "Hello World!";
    std::cout << greetings << "\n";

    // (2): obtaining length of C style string
    std::cout << strlen(greetings) << "\n";

    // (3): safely reading C style string from input
    const size_t size = 20;
    char name[size];
    std::cin.getline(name, size);
    std::cout << name << "\n";

    // (4): conversions between C and C++ style strings
    std::string cppString = std::string(greetings);
    const char* cString = cppString.c_str();
    std::cout << cppString << "\n";
    std::cout << cString << "\n";

    return 0;
}