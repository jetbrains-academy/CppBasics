#include <memory>
#include <utility>
#include <iostream>

void transfer(std::unique_ptr<int[]>& from, std::unique_ptr<int[]>& to) {
    to = std::move(from);
}

int main() {
    std::unique_ptr<int[]> p = std::make_unique<int[]>(8);
    std::unique_ptr<int[]> q = std::make_unique<int[]>(8);
    transfer(p, q);
    if (!p && q) {
        std::cout << "Ownership is transferred!" << std::endl;
    }
    return 0;
}