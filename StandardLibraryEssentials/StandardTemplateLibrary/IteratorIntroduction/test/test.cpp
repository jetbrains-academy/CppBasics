#include <gtest/gtest.h>

std::string find_maximum(const std::vector<int>& container);

TEST(FindMaximumTest, EmptyVector) {
    std::vector<int> vec = {};
    std::string result = find_maximum(vec);
    EXPECT_EQ(result, "Vector is empty");
}

TEST(FindMaximumTest, NonEmptyVector) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::string result = find_maximum(vec);
    EXPECT_EQ(result, "Maximum element is 6");
}

TEST(FindMaximumTest, SingleElementVector) {
    std::vector<int> vec = {42};
    std::string result = find_maximum(vec);
    EXPECT_EQ(result, "Maximum element is 42");
}

TEST(FindMaximumTest, NegativeElementVector) {
    std::vector<int> vec = {-1, -2, -3, -4, -5, -6};
    std::string result = find_maximum(vec);
    EXPECT_EQ(result, "Maximum element is -1");
}