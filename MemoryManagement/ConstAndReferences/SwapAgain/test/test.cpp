#include <gtest/gtest.h>

void swap(int& a, int& b);

const int N_ITER = 10;

TEST(SwapTest, SwapTest) {
    for (int i = 0; i < N_ITER; ++i) {
        int a = rand();
        int b = rand();
        int a_ = a;
        int b_ = b;
        swap(a, b);
        ASSERT_EQ(a, b_);
        ASSERT_EQ(b, a_);
    }
}