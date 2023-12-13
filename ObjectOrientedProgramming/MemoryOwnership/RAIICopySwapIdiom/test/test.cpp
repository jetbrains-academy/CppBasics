#include <gtest/gtest.h>
#include "../src/dynarray.h"

TEST(DynarrayTest, DefaultConstructor) {
    dynarray arr;
    EXPECT_EQ(arr.size(), 0);
}

TEST(DynarrayTest, ConstructorWithSize) {
    const std::size_t size = 5;
    dynarray arr(size);
    EXPECT_EQ(arr.size(), size);
}

TEST(DynarrayTest, CopyConstructor) {
    dynarray arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    dynarray arr2(arr1);
    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
}

TEST(DynarrayTest, MoveConstructor) {
    dynarray arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    dynarray arr2(std::move(arr1));
    EXPECT_EQ(arr1.size(), 0); // arr1 is moved from, so it should be empty
    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
}

TEST(DynarrayTest, CopyAssignmentOperator) {
    dynarray arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    dynarray arr2;
    arr2 = arr1;
    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
}

TEST(DynarrayTest, MoveAssignmentOperator) {
    dynarray arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    dynarray arr2;
    arr2 = std::move(arr1);
    EXPECT_EQ(arr1.size(), 0); // arr1 is moved from, so it should be empty
    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
}

TEST(DynarrayTest, Destructor) {
    dynarray* arr = new dynarray(5);
    delete arr; // Destructor should be called without memory leaks
}

TEST(DynarrayTest, Size) {
    dynarray arr(4);
    EXPECT_EQ(arr.size(), 4);
}

TEST(DynarrayTest, SubscriptOperatorNonConst) {
    dynarray arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}

TEST(DynarrayTest, OutputOperator) {
    dynarray arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    testing::internal::CaptureStdout(); // Redirect std::cout for testing
    std::cout << arr;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 \n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
