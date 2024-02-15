#include <iostream>

#include "../include/book.hpp"

void newAndDeleteBook() {
    Book *favourite_book = new Book("Harry Potter");
    delete favourite_book;
}

void mallocAndFreeBook() {
    Book *favourite_book = (Book *) malloc(sizeof(Book));
    free(favourite_book);
}

int main() {
    newAndDeleteBook();
    mallocAndFreeBook();
    return 0;
}