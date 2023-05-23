#include "dllist.hpp"

Node* createNode(void* data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    return node;
}

void freeNode(Node* node) {
    free(node->data);
    free(node);
}

void link(Node* cursor, Node* node) {
    node->next = cursor->next;
    node->prev = cursor;
    cursor->next->prev = node;
    cursor->next = node;
}

void unlink(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

void initList(List& list) {
    list.sentry.data = nullptr;
    list.sentry.next = &list.sentry;
    list.sentry.prev = &list.sentry;
}

void insert(List& list, void* data) {
    Node* node = createNode(data);
    link(&list.sentry, node);
}

void remove(List& list, bool (*pred)(void*)) {
    Node* curr = list.sentry.next;
    while (curr != &list.sentry) {
        Node* next = curr->next;
        if (pred(curr->data)) {
            unlink(curr);
            freeNode(curr);
        }
        curr = next;
    }
}