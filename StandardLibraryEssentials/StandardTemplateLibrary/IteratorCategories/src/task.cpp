#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/iterator.h"

VectorIterator::VectorIterator(pointer ptr) {
    ptr_ = ptr;
}

VectorIterator::reference VectorIterator::operator*() const {
    return *ptr_;
}

VectorIterator::pointer VectorIterator::operator->() {
    return ptr_;
}

VectorIterator &VectorIterator::operator++() {
    ++ptr_;
    return *this;
}

VectorIterator VectorIterator::operator++(int) {
    VectorIterator tmp = *this;
    ++(*this);
    return tmp;
}

VectorIterator &VectorIterator::operator--() {
    --ptr_;
    return *this;
}

VectorIterator VectorIterator::operator--(int) {
    VectorIterator tmp = *this;
    --(*this);
    return tmp;
}

bool operator==(const VectorIterator &a, const VectorIterator &b) {
    return a.ptr_ == b.ptr_;
};

bool operator!=(const VectorIterator &a, const VectorIterator &b) {
    return a.ptr_ != b.ptr_;
};

int main() {

    std::vector<int> v = {1, 2, 3, 4, 5};

    VectorIterator begin(v.data());
    VectorIterator end(v.data() + v.size());

    int accumulative_sum = 0;

    for (auto it = begin; it != end; ++it) {
        std::cout << *it << ' ';
        accumulative_sum += *it;
    }

    std::cout << std::endl << accumulative_sum << std::endl;

    VectorIterator rbegin(v.data() + v.size() - 1);
    VectorIterator rend(v.data() - 1);

    for (auto it = rbegin; it != rend; --it) {
        std::cout << *it << ' ';
        accumulative_sum -= *it;
    }

    std::cout << std::endl << accumulative_sum << std::endl;

    return 0;
}