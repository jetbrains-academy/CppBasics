#include <gtest/gtest.h>

int* copy(int* p, size_t size);

TEST(CopyTest, CopyEmpty) {
    int a[10];
    ASSERT_EQ(nullptr, copy(a, 0));
}

TEST(CopyTest, Copy) {
    const size_t SIZE = 10;
    int a[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand() % 100;
    }
    int* p = copy(a, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        ASSERT_NE(a + i, p + i);
        ASSERT_EQ(a[i], p[i]);
    }
}