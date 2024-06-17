#include <iostream>
#include <string>
#include "../include/DataPair.hpp"

int main() {
    DataPair<int, std::string> pair1;
    pair1.setFirst(10);
    pair1.setSecond("Hello");
    int first = pair1.getFirst();
    std::cout << first << std::endl;
    std::string second = pair1.getSecond();
    std::cout << second << std::endl;
    DataPair<double, const char*> pair2 = makePair(20.22, "World");
    std::cout << pair2.getFirst() << " " << pair2.getSecond() << std::endl;
    return 0;
}