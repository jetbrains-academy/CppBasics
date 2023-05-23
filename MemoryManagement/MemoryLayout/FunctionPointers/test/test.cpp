#include <gtest/gtest.h>

int fold(int* array, size_t size, int init, int (*f)(int, int));

int plus(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

int sub(int a, int b) {
    return a - b;
}

TEST(FoldTest, SumTest) {
    const int size = 4;
    int array[4] = { 1, 2, 3, 4 };
    int res = fold(array, size, 0, plus);
    ASSERT_EQ(res, 10);
}

TEST(FoldTest, MultTest) {
    const int size = 4;
    int array[4] = { 1, 2, 3, 4 };
    int res = fold(array, size, 1, mult);
    ASSERT_EQ(res, 24);
}

TEST(FoldTest, SubTest) {
    const int size = 4;
    int array[4] = { 1, 2, 3, 4 };
    int res = fold(array, size, 10, sub);
    ASSERT_EQ(res, 0);
}

TEST(FoldTest, EmptyTest) {
    int array[4] = { 1, 2, 3, 4 };
    int res = fold(array, 0, 42, plus);
    ASSERT_EQ(res, 42);
}
