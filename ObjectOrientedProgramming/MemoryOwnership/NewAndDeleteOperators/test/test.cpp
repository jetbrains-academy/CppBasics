#include <gtest/gtest.h>

void createAndDeleteBook();
void allocateAndFreeBook();

TEST(CreateAndDeleteBookTest, SimpleBookTest) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    createAndDeleteBook();
    allocateAndFreeBook();
}