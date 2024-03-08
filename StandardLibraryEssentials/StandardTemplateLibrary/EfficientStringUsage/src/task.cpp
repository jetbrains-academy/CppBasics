#include <string>
#include <string_view>
#include <cctype>
#include <iostream>

std::string preprocess(std::string_view str) {
    std::string result;
    for (char c : str) {
        if (isalpha(c))
            result += std::tolower(c);
    }
    return result;
}

bool isPalindrome(std::string_view word) {
    std::string preprocessedWord = preprocess(word);
    std::string reversedWord(preprocessedWord.rbegin(), preprocessedWord.rend());
    return preprocessedWord == reversedWord;
}

int main() {
    std::cout << "Hello: " << (isPalindrome("Hello world!") ? "true" : "false") << '\n';
    std::cout << "Madam: " << (isPalindrome("Madam") ? "true" : "false") << '\n';
    std::cout << "A man a plan a canal Panama: " << (isPalindrome("A man a plan a canal Panama") ? "true" : "false") << '\n';
    return 0;
}