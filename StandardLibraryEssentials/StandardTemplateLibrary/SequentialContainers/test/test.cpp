#include <gtest/gtest.h>
#include <list>
#include <deque>

std::list<int> sum_adjacent_elements(const std::list<int>& nums);
std::deque<int> sum_adjacent_elements(const std::deque<int>& nums);

TEST(SumAdjacentElementsTest, ListEmpty) {
    std::list<int> nums = {};
    std::list<int> result = sum_adjacent_elements(nums);
    EXPECT_TRUE(result.empty());
}

TEST(SumAdjacentElementsTest, ListSingleElement) {
    std::list<int> nums = {1};
    std::list<int> result = sum_adjacent_elements(nums);
    EXPECT_TRUE(result.empty());
}

TEST(SumAdjacentElementsTest, ListMultipleElementsEven) {
    std::list<int> nums = {1, 2, 3, 4, 5, 6};
    std::list<int> expected = {3, 7, 11};
    std::list<int> result = sum_adjacent_elements(nums);
    EXPECT_EQ(result, expected);
}

TEST(SumAdjacentElementsTest, ListMultipleElementsOdd) {
    std::list<int> nums = {1, 2, 3, 4, 5, 6, 7};
    std::list<int> expected = {3, 7, 11};
    std::list<int> result = sum_adjacent_elements(nums);
    EXPECT_EQ(result, expected);
}

TEST(SumAdjacentElementsTest, DequeEmpty) {
    std::deque<int> nums = {};
    std::deque<int> result = sum_adjacent_elements(nums);
    EXPECT_TRUE(result.empty());
}

TEST(SumAdjacentElementsTest, DequeSingleElement) {
    std::deque<int> nums = {1};
    std::deque<int> result = sum_adjacent_elements(nums);
    EXPECT_TRUE(result.empty());
}

TEST(SumAdjacentElementsTest, DequeMultipleElementsEven) {
    std::deque<int> nums = {1, 2, 3, 4, 5, 6};
    std::deque<int> expected = {3, 7, 11};
    std::deque<int> result = sum_adjacent_elements(nums);
    EXPECT_EQ(result, expected);
}

TEST(SumAdjacentElementsTest, DequeMultipleElementsOdd) {
    std::deque<int> nums = {1, 2, 3, 4, 5, 6, 7};
    std::deque<int> expected = {3, 7, 11};
    std::deque<int> result = sum_adjacent_elements(nums);
    EXPECT_EQ(result, expected);
}