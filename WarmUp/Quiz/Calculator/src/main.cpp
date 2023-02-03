#include <iostream>
#include <string>

int main() {
    while (true) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "sum") {
            int n, m;
            std::cin >> n >> m;
            std::cout << n + m << std::endl;
            continue;
        }
        if (cmd == "sub") {
            int n, m;
            std::cin >> n >> m;
            std::cout << n - m << std::endl;
            continue;
        }
        if (cmd == "mul") {
            int n, m;
            std::cin >> n >> m;
            std::cout << n * m << std::endl;
            continue;
        }
        if (cmd == "div") {
            int n, m;
            std::cin >> n >> m;
            std::cout << n / m << std::endl;
            continue;
        }
        if (cmd == "exit") {
            break;
        }
        std::cout << "Sorry, could not understand your command" << std::endl;
    }
    return 0;
}