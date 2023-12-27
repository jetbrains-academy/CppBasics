#include <gtest/gtest.h>
#include <memory>

void transfer(std::unique_ptr<int[]>& from, std::unique_ptr<int[]>& to);

TEST(TransferTest, TransferTest) {
    std::unique_ptr<int[]> p = std::make_unique<int[]>(8);
    std::unique_ptr<int[]> q = std::make_unique<int[]>(8);
    int* expected = p.get();
    transfer(p, q);
    EXPECT_EQ(nullptr, p.get());
    EXPECT_EQ(expected, q.get());
}