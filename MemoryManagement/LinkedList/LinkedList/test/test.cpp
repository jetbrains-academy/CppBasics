#include <gtest/gtest.h>

#include "dllist.hpp"
#include "testing.hpp"

TEST(CreateNodeTest, CreateNodeTest) {
    void* data = malloc(8);
    auto uptr = unique_Cstr((char*) data);

    Node* node = createNode(data);
    ASSERT_TRUE(node != nullptr);

    uptr.release();
    EXPECT_EQ(data, node->data);
    freeNode(node);
}

TEST(LinkTest, LinkTest) {
    int l = 0;
    int m = 0;
    int r = 0;
    void* pl = &l;
    void* pm = &m;
    void* pr = &r;
    Node left, mid, right;

    left.data = pl;
    left.next = &right;
    left.prev = nullptr;

    right.data = pr;
    right.prev = &left;
    right.next = nullptr;

    mid.data = pm;
    link(&left, &mid);

    ASSERT_EQ(pl, left.data);
    ASSERT_EQ(pm, mid.data);
    ASSERT_EQ(pr, right.data);

    ASSERT_EQ(&mid, left.next);
    ASSERT_EQ(nullptr, left.prev);

    ASSERT_EQ(&mid, right.prev);
    ASSERT_EQ(nullptr, right.next);

    ASSERT_EQ(&left, mid.prev);
    ASSERT_EQ(&right, mid.next);
}

TEST(UnlinkTest, UnlinkTest) {
    int l = 0;
    int m = 0;
    int r = 0;
    void* pl = &l;
    void* pm = &m;
    void* pr = &r;
    Node left, mid, right;

    left.data = pl;
    left.next = &mid;
    left.prev = nullptr;

    right.data = pr;
    right.prev = &mid;
    right.next = nullptr;

    mid.data = pm;
    mid.prev = &left;
    mid.next = &right;

    unlink(&mid);

    ASSERT_EQ(pl, left.data);
    ASSERT_EQ(pm, mid.data);
    ASSERT_EQ(pr, right.data);

    ASSERT_EQ(&right, left.next);
    ASSERT_EQ(nullptr, left.prev);

    ASSERT_EQ(&left, right.prev);
    ASSERT_EQ(nullptr, right.next);
}

TEST(InitListTest, InitListTest) {
    List list;
    initList(list);

    ASSERT_EQ(nullptr, list.sentry.data);
    ASSERT_EQ(&list.sentry, list.sentry.next);
    ASSERT_EQ(&list.sentry, list.sentry.prev);
}

struct Cleanup {
    List* list = nullptr;

    Cleanup(List* list):
        list(list)
    {}

    ~Cleanup() {
        if (!list)
            return;
        freeList(*list);
    }
};

TEST(InsertTest, InsertTest) {
    List list;
    initList(list);
    Cleanup cleanup(&list);

    void* data = malloc(8);
    insert(list, data);

    Node* node = list.sentry.next;

    ASSERT_EQ(nullptr, list.sentry.data);
    ASSERT_EQ(node, list.sentry.next);
    ASSERT_EQ(node, list.sentry.prev);

    ASSERT_EQ(data, node->data);
    ASSERT_EQ(&list.sentry, node->next);
    ASSERT_EQ(&list.sentry, node->prev);
}

TEST(RemoveTest, RemoveFalseTest) {
    List list;
    initList(list);
    Cleanup cleanup(&list);

    void* data = malloc(8);
    insert(list, data);
    remove(list, falsePred);

    Node* node = list.sentry.next;

    ASSERT_EQ(nullptr, list.sentry.data);
    ASSERT_EQ(node, list.sentry.next);
    ASSERT_EQ(node, list.sentry.prev);

    ASSERT_EQ(data, node->data);
    ASSERT_EQ(&list.sentry, node->next);
    ASSERT_EQ(&list.sentry, node->prev);
}

TEST(RemoveTest, RemoveTrueTest) {
    List list;
    initList(list);
    Cleanup cleanup(&list);

    void* data = malloc(8);
    insert(list, data);
    remove(list, truePred);

    ASSERT_EQ(nullptr, list.sentry.data);
    ASSERT_EQ(&list.sentry, list.sentry.next);
    ASSERT_EQ(&list.sentry, list.sentry.prev);
}