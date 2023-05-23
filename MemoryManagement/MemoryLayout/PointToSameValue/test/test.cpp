#include <gtest/gtest.h>

bool pointToSameValue(int* a, int* b);

TEST(Test, Test) {
    int a = 42;
    int b = 42;
    int c = 23;

    ASSERT_TRUE(pointToSameValue(&a, &a));
    ASSERT_TRUE(pointToSameValue(&a, &b));
    ASSERT_FALSE(pointToSameValue(&a, &c));
    ASSERT_FALSE(pointToSameValue(&b, &c));
    ASSERT_FALSE(pointToSameValue(&a, nullptr));
    ASSERT_FALSE(pointToSameValue(nullptr, &a));
    ASSERT_TRUE(pointToSameValue(nullptr, nullptr));
}