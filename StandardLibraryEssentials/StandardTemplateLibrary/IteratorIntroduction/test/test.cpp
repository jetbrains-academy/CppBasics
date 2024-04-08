#include <gtest/gtest.h>

std::vector<int>::iterator findMaximum(std::vector<int>& container);

TEST(FindMaximumTest, EmptyVector) {
    std::vector<int> vec = {};
    auto result = findMaximum(vec);
    EXPECT_EQ(result, vec.end());
}

TEST(FindMaximumTest, NonEmptyVector) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto result = findMaximum(vec);
    EXPECT_EQ(*result, 6);
}

TEST(FindMaximumTest, SingleElementVector) {
    std::vector<int> vec = {42};
    auto result = findMaximum(vec);
    EXPECT_EQ(*result, 42);
}

TEST(FindMaximumTest, NegativeElementVector) {
    std::vector<int> vec = {-1, -2, -3, -4, -5, -6};
    auto result = findMaximum(vec);
    EXPECT_EQ(*result, -1);
}