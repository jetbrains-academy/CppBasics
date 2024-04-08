#include <gtest/gtest.h>

std::map<char, int> countLetters(const std::string& str);

TEST(MapTest, BasicTest) {
    std::string str = "The distribution of letters in any text is uneven. Letter frequency is the number of times letters of the alphabet appear on average in written language. The data may vary from source to source, but almost everywhere it is indicated that the letter ‘e’ is the most common in the English text. The rarest letter is ‘z’";
    std::map<char, int> expected = {
            {'a', 17}, {'b', 4}, {'c', 5}, {'d', 4}, {'e', 42}, {'f', 5}, {'g', 4},
            {'h', 12}, {'i', 17}, {'l', 9}, {'m', 8}, {'n', 15},
            {'o', 13}, {'p', 3}, {'q', 1}, {'r', 19}, {'s', 15}, {'t', 38}, {'u', 8},
            {'v', 4}, {'w', 2}, {'x', 2}, {'y', 5}, {'z', 1}
    };
    ASSERT_EQ(countLetters(str), expected);
}

TEST(MapTest, EmptyString) {
    std::string str = "";
    std::map<char, int> expected = {};
    ASSERT_EQ(countLetters(str), expected);
}

TEST(MapTest, SingleLetter) {
    std::string str = "A";
    std::map<char, int> expected = {{'a', 1}};
    ASSERT_EQ(countLetters(str), expected);
}

TEST(MapTest, SeparatorCharacters) {
    std::string str = ",.!?:;";
    std::map<char, int> expected = {};
    ASSERT_EQ(countLetters(str), expected);
}

TEST(MapTest, NoDuplicateLetters) {
    std::string str = "Abcdefghijklmnopqrstuvwxyz";
    std::map<char, int> expected = {
            {'a', 1}, {'b', 1}, {'c', 1}, {'d', 1}, {'e', 1}, {'f', 1}, {'g', 1}, {'h', 1},
            {'i', 1}, {'j', 1}, {'k', 1}, {'l', 1}, {'m', 1}, {'n', 1}, {'o', 1}, {'p', 1},
            {'q', 1}, {'r', 1}, {'s', 1}, {'t', 1}, {'u', 1}, {'v', 1}, {'w', 1}, {'x', 1},
            {'y', 1}, {'z', 1}
    };
    ASSERT_EQ(countLetters(str), expected);
}

TEST(MapTest, OnlyDuplicateLetters) {
    std::string str = "AAAAAaaaaa";
    std::map<char, int> expected = {{'a', 10}};
    ASSERT_EQ(countLetters(str), expected);
}

TEST(MapTest, FullUpperCaseWords) {
    std::string str = "HELLO WORLD THIS IS A TEST";
    std::map<char, int> expected = {
            {'a', 1}, {'d', 1}, {'e', 2}, {'h', 2}, {'i', 2}, {'l', 3}, {'o', 2}, {'r', 1},
            {'s', 3}, {'t', 3}, {'w', 1}
    };
    ASSERT_EQ(countLetters(str), expected);
}