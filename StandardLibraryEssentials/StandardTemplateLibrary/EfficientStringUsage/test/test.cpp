#include <gtest/gtest.h>

std::string lowerCase(std::string_view str);
bool isPalindrome(std::string_view word);

TEST(PalindromeTest, EmptyString) {
    std::string word = "";
    EXPECT_TRUE(isPalindrome(word));
}

TEST(PalindromeTest, SingleCharacter) {
    std::string word = "a";
    EXPECT_TRUE(isPalindrome(word));
}

TEST(PalindromeTest, WordPalindrome) {
    std::string word = "Level";
    EXPECT_TRUE(isPalindrome(word));
}

TEST(PalindromeTest, MultipleCharactersPalindrome) {
    std::string word = "Abacaba";
    EXPECT_TRUE(isPalindrome(word));
}

TEST(PalindromeTest, MultipleCharactersNotPalindrome) {
    std::string word = "Abacab";
    EXPECT_FALSE(isPalindrome(word));
}

TEST(PalindromeTest, PhrasePalindrome) {
    std::string word = "Live on time, emit no evil!";
    EXPECT_TRUE(isPalindrome(word));
}

TEST(PalindromeTest, PhraseNotPalindrome) {
    std::string word = "Is it crazy how saying sentences backwards creates backwards sentences saying how crazy it is?";
    EXPECT_FALSE(isPalindrome(word));
}