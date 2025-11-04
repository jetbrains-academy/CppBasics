#include <gtest/gtest.h>
#include "../include/DataPair.hpp"

TEST(DataPairTest, Creation) {
    DataPair<int, int> pair(1, 2);
    ASSERT_EQ(pair.getFirst(), 1);
    ASSERT_EQ(pair.getSecond(), 2);
}

TEST(DataPairTest, CreationDiffTypes) {
    DataPair<std::string, double> pair("Hello", 3.14);
    ASSERT_EQ(pair.getFirst(), "Hello");
    ASSERT_EQ(pair.getSecond(), 3.14);
}

TEST(DataPairTest, Setters) {
    DataPair<int, int> pair(1, 2);
    pair.setFirst(3);
    pair.setSecond(4);
    ASSERT_EQ(pair.getFirst(), 3);
    ASSERT_EQ(pair.getSecond(), 4);
}

TEST(DataPairTest, SettersDiffTypes) {
    DataPair<std::string, double> pair("Hello", 3.14);
    pair.setFirst("World");
    pair.setSecond(6.28);
    ASSERT_EQ(pair.getFirst(), "World");
    ASSERT_EQ(pair.getSecond(), 6.28);
}

TEST(DataPairTest, MakePair) {
    DataPair<int, int> pair = makePair(1, 2);
    ASSERT_EQ(pair.getFirst(), 1);
    ASSERT_EQ(pair.getSecond(), 2);
}

TEST(DataPairTest, MakePairDiffTypes) {
    DataPair<std::string, double> pair = makePair<std::string, double>("Hello", 3.14);
    ASSERT_EQ(pair.getFirst(), "Hello");
    ASSERT_EQ(pair.getSecond(), 3.14);
}