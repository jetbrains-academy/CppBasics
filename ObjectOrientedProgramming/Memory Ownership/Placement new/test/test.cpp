#include <gtest/gtest.h>

class MyObject {
public:
    MyObject() {}
    ~MyObject() {}
};

void createAndDeleteArrayOfObjectsWithPlacementNew();

TEST(CreateAndDeleteArrayOfObjectsWithPlacementNewTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    createAndDeleteArrayOfObjectsWithPlacementNew();
}