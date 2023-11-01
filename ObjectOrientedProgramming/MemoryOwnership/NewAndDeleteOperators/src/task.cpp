#include <iostream>

struct Book {
    std::string name;

    explicit Book(std::string name) : name(std::move(name)) {
        std::cout << "Book is open!\n";
    }

    ~Book() {
        std::cout << "Book is closed!\n";
    }
};

void createAndDeleteBook() {
    Book *favourite_book = new Book("Harry Potter");
    delete favourite_book;
}

void allocateAndFreeBook() {
    Book *favourite_book = (Book *) malloc(sizeof(Book));
    free(favourite_book);
}

int main() {
    createAndDeleteBook();
    std::cout << "-------------------\n";
    allocateAndFreeBook();
    std::cout << "Did something come out in the console?\n"
                 "Nothing came out... :(" << std::endl;
    return 0;
}