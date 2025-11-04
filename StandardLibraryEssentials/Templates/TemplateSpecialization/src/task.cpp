#include "../include/DataPair.hpp"

int main() {
    DataPair<int, std::string> pair{10, "Hello"};
    printDataPair(pair);
    DataPair<double, double> double_pair{20.22, 30.33};
    printDataPair(double_pair);
}