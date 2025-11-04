#ifndef CPPBASICS_DATAPAIR_HPP
#define CPPBASICS_DATAPAIR_HPP

#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
class DataPair {
private:
    T1 first;
    T2 second;

public:
    DataPair() : first(T1()), second(T2()) {}
    DataPair(T1 first, T2 second) : first(first), second(second) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    void setFirst(T1 value) {
        first = value;
    }

    void setSecond(T2 value) {
        second = value;
    }
};

template<typename T, typename U>
void printDataPair(const DataPair<T, U>& pair) {
    if constexpr (std::is_same<T, U>::value) {
        if constexpr (std::is_same<T, int>::value) {
            std::cout << "int DataPair: ";
        } else if constexpr (std::is_same<T, double>::value) {
            std::cout << "double DataPair: ";
        } else if constexpr (std::is_same<T, std::string>::value) {
            std::cout << "std::string DataPair: ";
        } else {
            std::cout << "DataPair: ";
        }
    } else {
        std::cout << "DataPair: ";
    }
    std::cout << pair.getFirst() << ", " << pair.getSecond() << std::endl;
}

#endif //CPPBASICS_DATAPAIR_HPP
