#include <gtest/gtest.h>

#include <new>
#include <string>
#include <iostream>

class Cat {
private:
    int age;
    std::string name;

public:
    Cat(int age, std::string name) : age(age), name(std::move(name)) {
        std::cout << "Cat " << this->name << " jumped into the box!\n";
    }

    ~Cat() {
        std::cout << "Cat " << this->name << " jumped out of the box!\n";
    }
};

class Dog {
private:
    int age;
    std::string name;

public:
    Dog(int age, std::string name) : age(age), name(std::move(name)) {
        std::cout << "Dog " << this->name << " jumped into the box!\n";
    }

    ~Dog() {
        std::cout << "Dog " << this->name << " jumped out of the box!\n";
    }
};

void placeAnimals();

TEST(PlacementNew, MovingAnimals) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    placeAnimals();
}