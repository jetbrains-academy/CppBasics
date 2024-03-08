#include <iostream>
#include <vector>
#include <string>

std::string find_maximum(const std::vector<int>& container) {
    if (container.empty()) {
        return "Vector is empty";
    }
    int max_element = container[0];
    for (auto it = container.begin() + 1; it != container.end(); ++it) {
        if (*it > max_element) {
            max_element = *it;
        }
    }
    return "Maximum element is " + std::to_string(max_element);
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::cout << find_maximum(vec) << std::endl;

    std::vector<int> empty_vec;
    std::cout << find_maximum(empty_vec) << std::endl;

    return 0;
}