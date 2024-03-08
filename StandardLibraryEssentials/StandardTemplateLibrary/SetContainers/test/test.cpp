#include <gtest/gtest.h>

std::set<std::string> split_into_words(const std::string& str);

TEST(SetTest, BasicTest) {
    std::string str = "Hello, world! This is a test. Test again, hello.";
    std::set<std::string> expected = {"a", "again", "hello", "is", "test", "this", "world"};
    ASSERT_EQ(split_into_words(str), expected);
}

TEST(SetTest, EmptyString) {
    std::string str = "";
    std::set<std::string> expected = {};
    ASSERT_EQ(split_into_words(str), expected);
}

TEST(SetTest, SingleWord) {
    std::string str = "Hello";
    std::set<std::string> expected = {"hello"};
    ASSERT_EQ(split_into_words(str), expected);
}

TEST(SetTest, SeparatorCharacters) {
    std::string str = ",.!?:;";
    std::set<std::string> expected = {};
    ASSERT_EQ(split_into_words(str), expected);
}

TEST(SetTest, NoDuplicateWords) {
    std::string str = "Hello world this is a test";
    std::set<std::string> expected = {"a", "hello", "is", "test", "this", "world"};
    ASSERT_EQ(split_into_words(str), expected);
}

TEST(SetTest, OnlyDuplicateWords) {
    std::string str = "test test test test test";
    std::set<std::string> expected = {"test"};
    ASSERT_EQ(split_into_words(str), expected);
}

TEST(SetTest, FullUpperCaseWords) {
    std::string str = "HELLO WORLD THIS IS A TEST";
    std::set<std::string> expected = {"a", "hello", "is", "test", "this", "world"};
    ASSERT_EQ(split_into_words(str), expected);
}