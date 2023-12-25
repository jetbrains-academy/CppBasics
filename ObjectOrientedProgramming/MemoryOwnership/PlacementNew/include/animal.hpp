#ifndef CPPBASICS_ANIMAL_HPP
#define CPPBASICS_ANIMAL_HPP

#include <cstddef>
#include <iostream>
#include <string>

class Cat {
public:
    explicit Cat(const std::string& name) : name(name) {
        std::cout << "Cat " << this->name << " jumped into the box!\n";
        counter++;
    }

    ~Cat() {
        counter--;
        std::cout << "Cat " << this->name << " jumped out of the box!\n";
    }

    std::string getName() const {
        return name;
    }

    static size_t getCounter() {
        return counter;
    }
private:
    std::string name;
    static size_t counter;
};

class Mouse {
public:
    explicit Mouse(const std::string& name) : name(name) {
        std::cout << "Mouse " << this->name << " jumped into the box!\n";
        counter++;
    }

    ~Mouse() {
        counter--;
        std::cout << "Mouse " << this->name << " jumped out of the box!\n";
    }

    std::string getName() const {
        return name;
    }

    static size_t getCounter() {
        return counter;
    }
private:
    std::string name;
    static size_t counter;
};

#endif // CPPBASICS_ANIMAL_HPP
