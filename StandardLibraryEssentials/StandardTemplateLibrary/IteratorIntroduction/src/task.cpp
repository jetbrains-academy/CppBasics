#include <iostream>
#include <vector>
#include <string>

std::vector<int>::iterator findMaximum(std::vector<int>& container) {
    if (container.empty()) {
        return container.end();
    }
    auto max_element = container.begin();
    for (auto it = container.begin() + 1; it != container.end(); ++it) {
        if (*it > *max_element) {
            max_element = it;
        }
    }
    return max_element;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::cout << *findMaximum(vec) << std::endl;

    std::vector<int> empty_vec;
    std::cout << *findMaximum(empty_vec) << std::endl;

    return 0;
}