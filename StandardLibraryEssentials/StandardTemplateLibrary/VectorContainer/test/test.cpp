#include <gtest/gtest.h>

std::vector<int> create_and_reserve();
std::vector<int> fill(std::vector<int>& vec);
std::vector<int> modify_vector(std::vector<int>& vec);
void clear_vector(std::vector<int>& vec);
void play_with_vector();

TEST(MainTest, CorrectOutput) {
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    play_with_vector();

    std::cout.rdbuf(prevcoutbuf); // Reset to standard output again

    std::string expected_output = "Size: 0, Capacity: 10\n"
                                  "1 2 3 4 5 6 7 8 9 10 \n"
                                  "Size: 10, Capacity: 10\n"
                                  "100 2 3 4 5 6 7 8 200 \n"
                                  "Size: 9, Capacity: 9\n"
                                  "Vector cleared\n"
                                  "Size: 0, Capacity: 9\n";

    ASSERT_EQ(buffer.str(), expected_output);
}

TEST(VectorTest, CreateAndReserve) {
    std::vector<int> vec = create_and_reserve();
    std::vector<int> expected_vec;
    expected_vec.reserve(10);
    ASSERT_EQ(vec, expected_vec);
}

TEST(VectorTest, FillVector) {
    std::vector<int> vec;
    vec = fill(vec);
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
