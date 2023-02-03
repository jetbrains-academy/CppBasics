#include <gtest/gtest.h>

int sumPositive(int array[], int size);

namespace expected {
    int sumPositive(int array[], int size) {
        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (array[i] > 0) {
                result += array[i];
            }
        }
        return result;
    }
}

TEST(SumPositiveTest, SmokeTest) {
    int a[] = { 1, 2, 3 };
    ASSERT_EQ(6, sumPositive(a, 3));
}

TEST(SumPositiveTest, EmptyTest) {
    int a[1];
    ASSERT_EQ(0, sumPositive(a, 0));
}

TEST(SumPositiveTest, NegativeZeroTest) {
    int a[] = { -1, -2, -3 };
    ASSERT_EQ(0, sumPositive(a, 3));
}

TEST(SumPositiveTest, NegativeSmokeTest) {
    int a[] = { -1, 2, -3 };
    ASSERT_EQ(2, sumPositive(a, 3));
}

TEST(SumPositiveTest, SizeTest) {
    int a[] = { 1, 2, 3 };
    ASSERT_EQ(1, sumPositive(a, 1));
}

const int N_ITER = 20;
const int SIZE = 20;

TEST(SumPositiveTest, RandomTest) {
    int a[SIZE];
    for (int i = 0; i < N_ITER; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[j] = -1000 + rand() % 2000;
        }
        ASSERT_EQ(expected::sumPositive(a, SIZE),
                  sumPositive(a, SIZE));
    }
}