#include <gtest/gtest.h>

void createAndDeleteObject();

TEST(CreateAndDeleteObjectTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    createAndDeleteObject();
}