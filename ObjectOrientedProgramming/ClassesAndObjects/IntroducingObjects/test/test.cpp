#include <gtest/gtest.h>

// Headers of objects that student should implement:
int sum(int a, int b);


// Tests:
// todo: replace this with an actual test
TEST(SumTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(sum(1, 2), 3);
}