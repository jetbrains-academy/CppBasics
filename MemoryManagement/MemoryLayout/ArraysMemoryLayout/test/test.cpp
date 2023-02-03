#include <gtest/gtest.h>

int sum_size(int* p, size_t size);
int sum_ptrs(int* begin, int* end);

int sum(int* p, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += *(p + i);
    }
    return sum;
}

TEST(SumTest, SumTestEmpty) {
    int a[0];
    ASSERT_EQ(0, sum_size(a, 0));
    ASSERT_EQ(0, sum_ptrs(a, a));
}

const int N_ITER = 10;
const size_t SIZE = 20;

TEST(SumTest, SumTestRandom) {
    int a[SIZE];
    for (int i = 0; i < N_ITER; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[j] = rand() % 100;
        }
        int expected = sum(a, SIZE);
        ASSERT_EQ(expected, sum_size(a, SIZE));
        ASSERT_EQ(expected, sum_ptrs(a, a + SIZE));
    }
}