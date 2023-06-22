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

std::string error_msg(int* array, size_t size) {
    std::ostringstream stream;
    stream << "[";
    for (size_t i = 0; i < size; ++i) {
        stream << array[i];
        if (i != size - 1)
            stream << ", ";
    }
    stream << "]";
    return stream.str();
}

TEST(SumPositiveTest, SmokeTest) {
    int a[] = { 1, 2, 3 };
    ASSERT_EQ(6, sumPositive(a, 3))
        << "  a = " << error_msg(a, 3) << "\n";
}

TEST(SumPositiveTest, EmptyTest) {
    int a[1];
    ASSERT_EQ(0, sumPositive(a, 0))
        << "  a = " << error_msg(a, 0) << "\n";
}

TEST(SumPositiveTest, NegativeZeroTest) {
    int a[] = { -1, -2, -3 };
    ASSERT_EQ(0, sumPositive(a, 3))
        << "  a = " << error_msg(a, 3) << "\n";
}

TEST(SumPositiveTest, NegativeSmokeTest) {
    int a[] = { -1, 2, -3 };
    ASSERT_EQ(2, sumPositive(a, 3))
        << "  a = " << error_msg(a, 3) << "\n";
}

TEST(SumPositiveTest, SizeTest) {
    int a[] = { 1, 2, 3 };
    ASSERT_EQ(1, sumPositive(a, 1))
        << "  a = " << error_msg(a, 1) << "\n";
}

const int N_ITER = 20;
const int SIZE = 20;

TEST(SumPositiveTest, RandomTest) {
    int a[SIZE];
    for (int i = 0; i < N_ITER; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[j] = -1000 + rand() % 2000;
        }
        int result = expected::sumPositive(a, SIZE);
        ASSERT_EQ(result, sumPositive(a, SIZE))
            << "  a = " << error_msg(a, SIZE) << "\n";
    }
}