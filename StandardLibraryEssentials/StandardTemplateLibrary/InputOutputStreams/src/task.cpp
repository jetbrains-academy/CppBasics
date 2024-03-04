#include <iostream>
#include <sstream>
#include <iomanip>

bool isNumber(const std::string& token) {
    if (token.empty()) {
        return false;
    }
    int dotCount = 0;
    int minusCount = 0;
    for (char c : token) {
        if (c == '.') {
            if (dotCount > 0) {
                return false;
            }
            dotCount++;
        }
        else if (c == '-') {
            if (minusCount > 0 || token[0] != '-') {
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