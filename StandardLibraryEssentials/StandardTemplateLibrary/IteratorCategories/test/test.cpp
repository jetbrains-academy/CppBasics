#include <gtest/gtest.h>

#include "../include/iterator.h"

TEST (VectorIteratorTest, PointerOperator) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    VectorIterator begin(v.data());
    VectorIterator end(v.data() + v.size());

    int i = 0;
    for (auto it = begin; it != end; ++it, ++i) {
        EXPECT_EQ(*it, v[i]);
    }
}

TEST (VectorIteratorTest, ArrowOperator) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    VectorIterator begin(v.data());
    VectorIterator end(v.data() + v.size());

    int i = 0;
    for (auto it = begin; it != end; ++it, ++i) {
        EXPECT_EQ(it.operator->(), &v[i]);
    }
}

TEST(VectorIteratorTest, ForwardIteration) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    VectorIterator begin(v.data());
    VectorIterator end(v.data() + v.size());

    int i = 0;
    for (auto it = begin; it != end; ++it, ++i) {
        EXPECT_EQ(*it, v[i]);
    }
}

TEST(VectorIteratorTest, BackwardIteration) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    VectorIterator rbegin(v.data() + v.size() - 1);
    VectorIterator rend(v.data() - 1);

    int i = v.size() - 1;
    for (auto it = rbegin; it != rend; --it, --i) {
        EXPECT_EQ(*it, v[i]);
    }
}

TEST(VectorIteratorTest, EqualityOperator) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    VectorIterator begin1(v.data());
    VectorIterator begin2(v.data());
    VectorIterator end(v.data() + v.size());

    EXPECT_TRUE(begin1 == begin2);
    EXPECT_FALSE(begin1 == end);
}

TEST(VectorIteratorTest, InequalityOperator) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    VectorIterator begin(v.data());
    VectorIterator end(v.data() + v.size());

    EXPECT_TRUE(begin != end);
    EXPECT_FALSE(begin != begin);
}