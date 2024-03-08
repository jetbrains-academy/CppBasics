#include <iostream>
#include <list>
#include <deque>

std::list<int> sum_adjacent_elements(const std::list<int>& nums) {
    std::list<int> result;
    auto it = nums.begin();
    while (it != nums.end()) {
        int sum = *it;
        if (++it != nums.end()) {
            sum += *it;
            result.push_back(sum);
        }
        if (it != nums.end()) {
            ++it;
        }
    }
    return result;
}

std::deque<int> sum_adjacent_elements(const std::deque<int>& nums) {
    std::deque<int> result;
    for (size_t i = 0; i < nums.size(); i += 2) {
        int sum = nums[i];
        if (i + 1 < nums.size()) {
            sum += nums[i + 1];
            result.push_back(sum);
        }
    }
    return result;
}

int main() {
    std::list<int> nums1 = {1, 2, 3, 4, 5, 6};
    std::list<int> result1 = sum_adjacent_elements(nums1);
    for (auto it = result1.begin(); it != result1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::deque<int> nums2 = {1, 2, 3, 4, 5, 6};
    std::deque<int> result2 = sum_adjacent_elements(nums2);
    for (auto it = result2.begin(); it != result2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}