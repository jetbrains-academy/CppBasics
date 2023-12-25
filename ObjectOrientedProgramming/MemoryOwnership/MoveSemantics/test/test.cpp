#include <gtest/gtest.h>
#include <memory>

std::unique_ptr<int> transfer_ownership(std::unique_ptr<int> &ptr);

void swap_ownership(std::unique_ptr<int>& ptr1, std::unique_ptr<int>& ptr2);

TEST(MoveUniquePtrTest, MoveTest) {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::unique_ptr<int> new_ptr = transfer_ownership(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(*new_ptr, 42);
}

TEST(SwapUniquePtrTest, SwapTest) {
    std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
    std::unique_ptr<int> ptr2 = std::make_unique<int>(20);
    swap_ownership(ptr1, ptr2);
    EXPECT_EQ(*ptr1, 20);
    EXPECT_EQ(*ptr2, 10);
}