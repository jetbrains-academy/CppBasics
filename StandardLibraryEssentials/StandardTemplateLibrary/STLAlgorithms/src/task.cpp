#include <iostream>
#include <vector>
#include <numeric>
#include <random>

std::vector<int> create_and_fill(int n) {
    std::vector<int> vec(n);
    std::iota(vec.begin(), vec.end(), 1);
    return vec;
}

void shuffle_vector(std::vector<int>& vec) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
}

void sort_descending(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end(), std::greater<>());
}

void reverse_vector(std::vector<int>& vec) {
    std::reverse(vec.begin(), vec.end());
}

std::vector<int>::iterator find_value(std::vector<int>& vec, int x) {
    return std::find(vec.begin(), vec.end(), x);
}

int find_sum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int find_gcd(const std::vector<int>& vec, int x) {
    int sum = find_sum(vec);
    return std::gcd(sum, x);
}

int main() {
    int n = 10;
    int x = 5;

    std::vector<int> vec = create_and_fill(n);
    std::cout << "After create_and_fill: ";
    for (int i : vec) std::cout << i << ' ';
    std::cout << '\n';

    shuffle_vector(vec);
    std::cout << "After shuffle_vector: ";
    for (int i : vec) std::cout << i << ' ';
    std::cout << '\n';

    sort_descending(vec);
    std::cout << "After sort_descending: ";
    for (int i : vec) std::cout << i << ' ';
    std::cout << '\n';

    reverse_vector(vec);
    std::cout << "After reverse_vector: ";
    for (int i : vec) std::cout << i << ' ';
    std::cout << '\n';

    auto it = find_value(vec, x);
    if (it != vec.end()) {
        std::cout << "After find_value: Found " << x << " at position " << std::distance(vec.begin(), it) << '\n';
    } else {
        std::cout << "After find_value: " << x << " not found in the vector\n";
    }

    // Find the sum of the elements in the vector
    int sum = find_sum(vec);
    std::cout << "After find_sum: Sum = " << sum << '\n';

    // Find the GCD of the sum and x
    int gcd = find_gcd(vec, x);
    std::cout << "After find_gcd: GCD = " << gcd << '\n';

    return 0;
}