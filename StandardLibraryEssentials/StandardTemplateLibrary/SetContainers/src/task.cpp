#include <iostream>
#include <set>
#include <string>
#include <cctype>

std::set<std::string> splitIntoWords(const std::string& str) {
    std::set<std::string> words;
    std::string buffer;
    for (char c : str) {
        if (std::isalpha(c)) {
            buffer += std::tolower(c);
        } else if (!buffer.empty()) {
            words.insert(buffer);
            buffer.clear();
        }
    }
    if (!buffer.empty()) {
        words.insert(buffer);
    }
    return words;
}

int main() {
    std::string str = "Hello, world! This is a test. Test again, hello.";
    std::set<std::string> words = splitIntoWords(str);
    for (const std::string& word : words) {
        std::cout << word << std::endl;
    }
    return 0;
}