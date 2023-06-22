#include <gtest/gtest.h>

int maxInt(int a, int b);

const int N_ITER = 20;

TEST(MaxIntTest, MaxIntTest) {
    ASSERT_EQ(42, maxInt(0, 42));
    ASSERT_EQ(42, maxInt(42, 0));
    ASSERT_EQ(0,  maxInt(-2, 0));
    for (int i = 0; i < N_ITER; ++i) {
        int a = -1000 + rand() % 2000;
        int b = -1000 + rand() % 2000;
        int max = std::max(a, b);
        ASSERT_EQ(max, maxInt(a, b))
            << "  a = " << a << ", b = " << b << "\n";
    }
}