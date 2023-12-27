#include <gtest/gtest.h>

std::map<char, int> count_letters(const std::string& str);

TEST(MapTest, CountLetters) {
    std::string str = "The distribution of letters in any text is uneven. Letter frequency is the number of times letters of the alphabet appear on average in written language. The data may vary from source to source, but almost everywhere it is indicated that the letter ‘e’ is the most common in the English text. The rarest letter is ‘z’";
    std::map<char, int> expected = {
            {'a', 17}, {'b', 4}, {'c', 5}, {'d', 4}, {'e', 42}, {'f', 5}, {'g', 4},
            {'h', 12}, {'i', 17}, {'l', 9}, {'m', 8}, {'n', 15},
            {'o', 13}, {'p', 3}, {'q', 1}, {'r', 19}, {'s', 15}, {'t', 38}, {'u', 8},
            {'v', 4}, {'w', 2}, {'x', 2}, {'y', 5}, {'z', 1}
    };
    ASSERT_EQ(count_letters(str), expected);
}