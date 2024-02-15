#include <gtest/gtest.h>

#include "../include/book.hpp"

void newAndDeleteBook();
void mallocAndFreeBook();

TEST(CreateAndDeleteBookTest, SimpleBookTest) {
    newAndDeleteBook();
    mallocAndFreeBook();
    ASSERT_EQ(1, Book::getBooksCounter())
        << "Expected constructor of Book() to be called inside `newAndDeleteBook` function.";
}