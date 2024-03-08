#include <gtest/gtest.h>

std::vector<int> create_and_fill(int n);
void shuffle_vector(std::vector<int>& vec);
void sort_descending(std::vector<int>& vec);
void reverse_vector(std::vector<int>& vec);
std::vector<int>::iterator find_value(std::vector<int>& vec, int x);
int find_sum(const std::vector<int>& vec);
int find_gcd(const std::vector<int>& vec, int x);

TEST(VectorAlgorithmsTest, CreateAndFill) {
    int n = 12;
    std::vector<int> vec = create_and_fill(n);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    EXPECT_EQ(vec, expected);
}

TEST(VectorAlgorithmsTest, SortDescending) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    sort_descending(vec);
    std::vector<int> expected = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    EXPECT_EQ(vec, expected);
}

TEST(VectorAlgorithmsTest, ReverseVector) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    reverse_vector(vec);
    std::vector<int> expected = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    EXPECT_EQ(vec, expected);
}

TEST(VectorAlgorithmsTest, FindValue) {
    std::vector<int> vec = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto it = find_value(vec, 11);
    EXPECT_EQ(*it, 11);
}

TEST(VectorAlgorithmsTest, FindSum) {
    std::vector<int> vec = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sum = find_sum(vec);
    EXPECT_EQ(sum, 78);
}

TEST(VectorAlgorithmsTest, FindGcd) {
    std::vector<int> vec = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int gcd = find_gcd(vec, 4);
    EXPECT_EQ(gcd, 2);
}