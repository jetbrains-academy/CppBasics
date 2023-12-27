#include <gtest/gtest.h>

std::vector<int> create_and_fill_vector();
std::vector<int> modify_vector(std::vector<int>& vec);
void clear_vector(std::vector<int>& vec);

TEST(VectorTest, CreateAndFillVector) {
    std::vector<int> vec = create_and_fill_vector();
    std::vector<int> expected_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQ(vec, expected_vec);
}

TEST(VectorTest, ModifyVector) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec = modify_vector(vec);
    std::vector<int> expected_vec = {100, 2, 3, 4, 5, 6, 7, 8, 200};
    ASSERT_EQ(vec, expected_vec);
}

TEST(VectorTest, ClearVector) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    clear_vector(vec);
    std::vector<int> expected_vec = {};
    ASSERT_EQ(vec, expected_vec);
}