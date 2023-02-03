#include <iostream>
#include <string>

int main() {
    std::string name;
    int age = 0;
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;
    std::cout << "What is your age?" << std::endl;
    std::cin >> age;

    std::cout << "Hello " << name << std::endl << age;

    return 0;
}