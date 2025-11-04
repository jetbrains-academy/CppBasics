#include <iostream>
#include <vector>

std::vector<int> create(std::size_t capacity) {
    std::vector<int> vec;
    vec.reserve(capacity);
    return vec;
}

std::vector<int> fill(std::vector<int>& vec, std::size_t size, int value) {
    vec.resize(size, value);
    return vec;
}

void debugPrint(const std::vector<int>& vec) {
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << '\n';
    std::cout << "Vector: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec = create(10);
    debugPrint(vec);
    vec = fill(vec, 10, 1);
    debugPrint(vec);
    vec.clear();
    debugPrint(vec);
    return 0;
}