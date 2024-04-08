#include <gtest/gtest.h>

int sumInRange(std::vector<int>& vec, int lowerBound, int upperBound);

TEST(SumInRangeTest, Empty) {
    std::vector<int> v;
    int lowerBound = 3;
    int upperBound = 7;
    ASSERT_EQ(0, sumInRange(v, lowerBound, upperBound));
}

TEST(SumInRangeTest, SingleNumber) {
    std::vector<int> v = {3};
    int lowerBound = 3;
    int upperBound = 7;
    ASSERT_EQ(3, sumInRange(v, lowerBound, upperBound));
}

TEST(SumInRangeTest, SingleNumberNotInRange) {
    std::vector<int> v = {3};
    int lowerBound = 4;
    int upperBound = 7;
    ASSERT_EQ(0, sumInRange(v, lowerBound, upperBound));
}

TEST(SumInRangeTest, Shuffled) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int lowerBound = 3;
    int upperBound = 7;
    ASSERT_EQ(31, sumInRange(v, lowerBound, upperBound));
}

TEST(SumInRangeTest, NoInRange) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lowerBound = 10;
    int upperBound = 20;
    ASSERT_EQ(0, sumInRange(v, lowerBound, upperBound));
}

TEST(SumInRangeTest, AllInRange) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lowerBound = 1;
    int upperBound = 9;
    ASSERT_EQ(45, sumInRange(v, lowerBound, upperBound));
}

TEST(SumInRangeTest, SameBounds) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lowerBound = 5;
    int upperBound = 5;
    ASSERT_EQ(5, sumInRange(v, lowerBound, upperBound));
}

TEST(SumInRangeTest, Range) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lowerBound = 3;
    int upperBound = 7;
    ASSERT_EQ(25, sumInRange(v, lowerBound, upperBound));
}
