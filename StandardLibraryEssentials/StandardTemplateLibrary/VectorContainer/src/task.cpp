#include <iostream>
#include <vector>

std::vector<int> create_and_fill_vector() {
    std::vector<int> vec;
    vec.reserve(10);
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);
    }
    return vec;
}

std::vector<int> modify_vector(std::vector<int>& vec) {
    vec.pop_back();
    vec[0] = 100;
    vec.at(vec.size() - 1) = 200;
    return vec;
}

void print_vector(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

void print_size_and_capacity(const std::vector<int>& vec) {
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << '\n';
}

void clear_vector(std::vector<int>& vec) {
    vec.clear();
    std::cout << "Vector cleared.\n";
}

int main() {
    std::vector<int> vec = create_and_fill_vector();
    print_vector(vec);
    print_size_and_capacity(vec);

    vec = modify_vector(vec);
    print_vector(vec);
    print_size_and_capacity(vec);

    clear_vector(vec);
    print_vector(vec);
    print_size_and_capacity(vec);

    return 0;
}