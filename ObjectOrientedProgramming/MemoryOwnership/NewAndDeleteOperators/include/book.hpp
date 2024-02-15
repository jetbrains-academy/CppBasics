#ifndef CPPBASICS_BOOK_HPP
#define CPPBASICS_BOOK_HPP

#include <cstddef>
#include <iostream>
#include <string>

class Book {
public:
    explicit Book(const std::string& name) : name(name) {
        std::cout << "Book is open!\n";
        counter++;
    }

    ~Book() {
        std::cout << "Book is closed!\n";
    }

    static size_t getBooksCounter() {
        return counter;
    }
private:
    std::string name;
    static size_t counter;
};

#endif // CPPBASICS_BOOK_HPP
