#ifndef CPPBASICS_DLLIST_HPP
#define CPPBASICS_DLLIST_HPP

#include <cstdlib>

struct Node {
    void* data;
    Node* next;
    Node* prev;
};

Node* createNode(void* data);
void freeNode(Node* node);

void link(Node* cursor, Node* node);
void unlink(Node* node);

struct List {
    Node sentry;
};

void initList(List& list);

void insert(List& list, void* data);
void remove(List& list, bool (*pred)(void*));

inline bool truePred(void* data) {
    return true;
}

inline bool falsePred(void* data) {
    return false;
}

inline void freeList(List& list) {
    remove(list, truePred);
}

#endif // CPPBASICS_DLLIST_HPP
