#include <gtest/gtest.h>

#include "gobjectlist.hpp"

#include "testscene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

TEST(GameObjectListTest, DefaultConstructorTest) {
    GameObjectList list;

    size_t counter = 0;
    list.foreach([&] (GameObject& it) {
        counter++;
    });
    ASSERT_EQ(0, counter)
        << "The default constructed list is not empty\n";
}

TEST(GameObjectListTest, InsertTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object = std::make_shared<TestGameObject>();
    list.insert(object);

    size_t counter = 0;
    list.foreach([&] (GameObject& it) {
        counter++;
    });
    ASSERT_EQ(1, counter)
        << "The size of the list is not equal to 1\n";

    list.foreach([&] (GameObject& it) {
        ASSERT_EQ(&it, object.get())
            << "The list contains another object (not the one that was inserted)\n";
    });
}

TEST(GameObjectListTest, InsertNullPtrTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object;
    list.insert(object);

    size_t counter = 0;
    list.foreach([&] (GameObject& it) {
        counter++;
    });
    ASSERT_EQ(0, counter)
        << "The size of the list is not equal to 1\n";
}

TEST(GameObjectListTest, InsertMultipleTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    std::vector<GameObject*> expected { object1.get(), object2.get(), object3.get() };
    std::vector<GameObject*> actual;
    list.foreach([&] (GameObject& it) {
        actual.push_back(&it);
    });
    ASSERT_EQ(expected, actual);
}

TEST(GameObjectListTest, RemoveTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    list.remove([&] (const GameObject& it) {
        return &it == object2.get();
    });
    std::vector<GameObject*> expected1 { object1.get(), object3.get() };
    std::vector<GameObject*> actual1;
    list.foreach([&] (GameObject& it) {
        actual1.push_back(&it);
    });
    ASSERT_EQ(expected1, actual1);

    list.remove([&] (const GameObject& it) {
        return &it == object3.get();
    });
    std::vector<GameObject*> expected2 { object1.get() };
    std::vector<GameObject*> actual2;
    list.foreach([&] (GameObject& it) {
        actual2.push_back(&it);
    });
    ASSERT_EQ(expected2, actual2);

    list.remove([&] (const GameObject& it) {
        return &it == object1.get();
    });
    std::vector<GameObject*> expected3 {};
    std::vector<GameObject*> actual3;
    list.foreach([&] (GameObject& it) {
        actual3.push_back(&it);
    });
    ASSERT_EQ(expected3, actual3);
}

TEST(GameObjectListTest, RemoveAllTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    list.remove([&] (const GameObject& it) {
        return true;
    });
    std::vector<GameObject*> expected { };
    std::vector<GameObject*> actual;
    list.foreach([&] (GameObject& it) {
        actual.push_back(&it);
    });
    ASSERT_EQ(expected, actual);
}

TEST(GameObjectListTest, CopyConstructorTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    GameObjectList copy(list);

    std::vector<GameObject*> expected { object1.get(), object2.get(), object3.get() };
    std::vector<GameObject*> actual1;
    list.foreach([&] (GameObject& it) {
        actual1.push_back(&it);
    });
    ASSERT_EQ(expected, actual1);

    std::vector<GameObject*> actual2;
    copy.foreach([&] (GameObject& it) {
        actual2.push_back(&it);
    });
    ASSERT_EQ(expected, actual2);
}

TEST(GameObjectListTest, MoveConstructorTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    GameObjectList copy(std::move(list));

    std::vector<GameObject*> expected1 { object1.get(), object2.get(), object3.get() };
    std::vector<GameObject*> actual1;
    copy.foreach([&] (GameObject& it) {
        actual1.push_back(&it);
    });
    ASSERT_EQ(expected1, actual1);

    std::vector<GameObject*> expected2;
    std::vector<GameObject*> actual2;
    list.foreach([&] (GameObject& it) {
        actual2.push_back(&it);
    });
    ASSERT_EQ(expected2, actual2);
}

TEST(GameObjectListTest, CopyAssignmentTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    GameObjectList copy;
    copy = list;

    std::vector<GameObject*> expected { object1.get(), object2.get(), object3.get() };
    std::vector<GameObject*> actual1;
    list.foreach([&] (GameObject& it) {
        actual1.push_back(&it);
    });
    ASSERT_EQ(expected, actual1);

    std::vector<GameObject*> actual2;
    copy.foreach([&] (GameObject& it) {
        actual2.push_back(&it);
    });
    ASSERT_EQ(expected, actual2);
}

TEST(GameObjectListTest, MoveAssignmentTest) {
    GameObjectList list;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list.insert(object1);
    list.insert(object2);
    list.insert(object3);

    GameObjectList copy;
    copy = std::move(list);

    std::vector<GameObject*> expected1 { object1.get(), object2.get(), object3.get() };
    std::vector<GameObject*> actual1;
    copy.foreach([&] (GameObject& it) {
        actual1.push_back(&it);
    });
    ASSERT_EQ(expected1, actual1);

    std::vector<GameObject*> expected2;
    std::vector<GameObject*> actual2;
    list.foreach([&] (GameObject& it) {
        actual2.push_back(&it);
    });
    ASSERT_EQ(expected2, actual2);
}

TEST(GameObjectListTest, SwapTest) {
    GameObjectList list1;
    GameObjectList list2;
    std::shared_ptr<TestGameObject> object1 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object2 = std::make_shared<TestGameObject>();
    std::shared_ptr<TestGameObject> object3 = std::make_shared<TestGameObject>();
    list1.insert(object1);
    list2.insert(object2);
    list2.insert(object3);

    using std::swap;
    swap(list1, list2);

    std::vector<GameObject*> expected1 { object2.get(), object3.get() };
    std::vector<GameObject*> actual1;
    list1.foreach([&] (GameObject& it) {
        actual1.push_back(&it);
    });
    ASSERT_EQ(expected1, actual1);

    std::vector<GameObject*> expected2 { object1.get() };
    std::vector<GameObject*> actual2;
    list2.foreach([&] (GameObject& it) {
        actual2.push_back(&it);
    });
    ASSERT_EQ(expected2, actual2);
}