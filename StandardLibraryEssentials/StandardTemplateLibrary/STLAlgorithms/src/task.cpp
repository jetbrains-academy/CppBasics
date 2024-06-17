#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int sumInRange(std::vector<int>& vec, int lowerBound, int upperBound) {
    std::sort(vec.begin(), vec.end());
    auto lower = std::lower_bound(vec.begin(), vec.end(), lowerBound);
    auto upper = std::upper_bound(vec.begin(), vec.end(), upperBound);
    return std::accumulate(lower, upper, 0);
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lowerBound = 3;
    int upperBound = 7;
    int sum = sumInRange(v, lowerBound, upperBound);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}