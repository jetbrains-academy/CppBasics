#include <gtest/gtest.h>
#include "gobjectlist.hpp"
#include "testscene.hpp"

TEST(GObjectListTest, FindNext) {
    GameObjectList list;
    auto object1 = std::make_shared<TestConsumableObject>();
    auto object2 = std::make_shared<TestConsumableObject>();
    auto object3 = std::make_shared<TestConsumableObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    ASSERT_EQ(list.findNext(object1.get()), object2.get());
    ASSERT_EQ(list.findNext(object2.get()), object3.get());
    ASSERT_EQ(list.findNext(object3.get()), nullptr);
}

TEST(GObjectListTest, FindNextEmpty) {
    GameObjectList list;
    auto object1 = std::make_shared<TestConsumableObject>();
    auto object2 = std::make_shared<TestConsumableObject>();

    ASSERT_EQ(list.findNext(object1.get()), nullptr);
    ASSERT_EQ(list.findNext(object2.get()), nullptr);
}
