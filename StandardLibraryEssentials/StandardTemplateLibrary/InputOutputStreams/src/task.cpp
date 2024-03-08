#include <iostream>
#include <sstream>
#include <iomanip>

bool isNumber(const std::string& token) {
    if (token.empty() || (token.size() == 1 && token[0] == '-')) {
        return false;
    }
    int dotCount = 0;
    int minusCount = 0;
    for (size_t i = 0; i < token.size(); ++i) {
        char c = token[i];
        if (c == '.') {
            if (dotCount > 0 || i == 0 || (i == 1 && token[0] == '-') || i == token.size() - 1) {
                return false;
            }
            dotCount++;
        }
        else if (c == '-') {
            if (minusCount > 0 || i != 0) {
                return false;
            }
            minusCount++;
        }
        else if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

void streamReader() {
    std::stringstream strStream;
    std::string token;
    std::cin >> token;
    while (token != "end") {
        if (isNumber(token)) {
            strStream << "Got number: " << std::setprecision(3) << std::fixed << std::stod(token) << "\n";
        } else {
            strStream << "Got string: " << token << "\n";
        }
        std::cin >> token;
    }
    std::cout << strStream.str();
}

int main() {
    streamReader();
    return 0;
}