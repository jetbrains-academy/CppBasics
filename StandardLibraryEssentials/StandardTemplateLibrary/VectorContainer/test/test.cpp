#include <gtest/gtest.h>

std::vector<int> create(std::size_t capacity);
std::vector<int> fill(std::vector<int>& vec, std::size_t size, int value);
void debugPrint(const std::vector<int>& vec);

TEST(VectorTest, CreateVector) {
    std::vector<int> vec = create(10);
    std::vector<int> expected_vec;
    expected_vec.reserve(10);
    ASSERT_EQ(vec, expected_vec);
}

TEST(VectorTest, FillVector) {
    std::vector<int> vec;
    vec = fill(vec, 10, 4);
    std::vector<int> expected_vec = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    ASSERT_EQ(vec, expected_vec);
}

TEST(VectorTest, DebugPrint) {
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    std::vector<int> vec = {1, 2, 3, 4, 5};
    debugPrint(vec);

    std::cout.rdbuf(prevcoutbuf);

    std::string expected_output = "Size: 5, Capacity: 5\n"
                                  "Vector: 1 2 3 4 5 \n";

    ASSERT_EQ(buffer.str(), expected_output);
}

TEST(VectorTest, DebugPrintEmpty) {
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    std::vector<int> vec;
    debugPrint(vec);

    std::cout.rdbuf(prevcoutbuf);

    std::string expected_output = "Size: 0, Capacity: 0\n"
                                  "Vector: \n";

    ASSERT_EQ(buffer.str(), expected_output);
}

TEST(VectorTest, DebugPrintNoElements) {
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    std::vector<int> vec;
    vec.reserve(10);
    debugPrint(vec);

    std::cout.rdbuf(prevcoutbuf);

    std::string expected_output = "Size: 0, Capacity: 10\n"
                                  "Vector: \n";

    ASSERT_EQ(buffer.str(), expected_output);
}
