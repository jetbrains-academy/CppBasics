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

void placeAnimals() {
    std::size_t numberOfAnimals = 3;
    char* animalBox = new char[sizeof(Cat) * numberOfAnimals];

    for (int i = 0; i < numberOfAnimals; ++i) {
        new (animalBox + i * sizeof(Cat)) Cat(i + 1, "Cat" + std::to_string(i + 1));
    }

    for (int i = 0; i < numberOfAnimals; ++i) {
        reinterpret_cast<Cat*>(animalBox + i * sizeof(Cat))->~Cat();
    }

    for (int i = 0; i < numberOfAnimals; ++i) {
        new (animalBox + i * sizeof(Dog)) Dog(i + 1, "Dog" + std::to_string(i + 1));
    }

    for (int i = 0; i < numberOfAnimals; ++i) {
        reinterpret_cast<Dog*>(animalBox + i * sizeof(Dog))->~Dog();
    }

    delete[] animalBox;
}

int main() {
    placeAnimals();
    return 0;
}