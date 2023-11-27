#include <gtest/gtest.h>
#include "../src/dynamic_array.h"

TEST(DynamicArrayTest, DefaultConstructor) {
    dynamic_array array;
    EXPECT_EQ(array.size(), 0);
}

TEST(DynamicArrayTest, ConstructorWithSizeAndInit) {
    dynamic_array array(5, 3);
    EXPECT_EQ(array.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], 3);
    }
}

TEST(DynamicArrayTest, CopyConstructor) {
    dynamic_array array(5, 3);
    dynamic_array copy_array(array);
    EXPECT_EQ(copy_array.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(copy_array[i], 3);
    }
}

TEST(DynamicArrayTest, MoveConstructor) {
    dynamic_array array(5, 3);
    dynamic_array moved_array = std::move(array);
    EXPECT_EQ(moved_array.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(moved_array[i], 3);
    }
    EXPECT_EQ(array.size(), 0);
}

TEST(DynamicArrayTest, CopyAssignmentOperator) {
    dynamic_array array(5, 3);
    dynamic_array copy_array;
    copy_array = array;
    EXPECT_EQ(copy_array.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(copy_array[i], 3);
    }
}

TEST(DynamicArrayTest, MoveAssignmentOperator) {
    dynamic_array array(5, 3);
    dynamic_array moved_array;
    moved_array = std::move(array);
    EXPECT_EQ(moved_array.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(moved_array[i], 3);
    }
    EXPECT_EQ(array.size(), 0);
}

TEST(DynamicArrayTest, Destructor) {
    {
        dynamic_array array(5, 3);
    }
}

TEST(DynamicArrayTest, SizeMethod) {
    dynamic_array array(5, 3);
    EXPECT_EQ(array.size(), 5);
}

TEST(DynamicArrayTest, AccessOperator) {
    dynamic_array array(5, 3);
    EXPECT_EQ(array[0], 3);
    EXPECT_EQ(array[3], 3);
}

TEST(DynamicArrayTest, ConstAccessOperator) {
    const dynamic_array array(5, 3);
    EXPECT_EQ(array[0], 3);
    EXPECT_EQ(array[3], 3);
}