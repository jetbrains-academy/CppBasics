#include <gtest/gtest.h>

std::set<std::string> split_into_words(const std::string& str);

TEST(SetTest, SplitIntoWords) {
    std::string str = "Hello, world! This is a test. Test again, hello.";
    std::set<std::string> expected = {"a", "again", "hello", "is", "test", "this", "world"};
    ASSERT_EQ(split_into_words(str), expected);
}