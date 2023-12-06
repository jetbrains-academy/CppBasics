#include "gobjectlist.hpp"

void GameObjectList::link(GameObjectList::Node *cursor, std::unique_ptr<Node> &&node) {
    cursor->next->prev = node.get();
    node->next = std::move(cursor->next);
    node->prev = cursor;
    cursor->next = std::move(node);
}

void GameObjectList::unlink(GameObjectList::Node *node) {
    node->next->prev = node->prev;
    node->prev->next = std::move(node->next);
}

void GameObjectList::insert(const std::shared_ptr<GameObject> &object) {
    if (!object) {
        return;
    }
    std::unique_ptr<Node> node = std::make_unique<Node>();
    node->object = object;
    link(head.get(), std::move(node));
}

void GameObjectList::remove(const std::function<bool(const GameObject &)> &pred) {
    GameObjectList::Node* curr = head->next.get();
    while (curr != tail) {
        Node* next = curr->next.get();
        if (pred(*curr->object)) {
            unlink(curr);
        }
        curr = next;
    }
}

void GameObjectList::foreach(const std::function<void (GameObject&)>& apply) {
    Node* curr = head->next.get();
    while (curr != tail) {
        apply(*curr->object);
        curr = curr->next.get();
    }
}

GameObjectList::GameObjectList() {
    head = std::make_unique<Node>();
    head->next = std::make_unique<Node>();
    tail = head->next.get();
    tail->prev = head.get();
}

GameObjectList::GameObjectList(const GameObjectList &other) : GameObjectList() {
    Node* cursor = head.get();
    Node* curr = other.head->next.get();
    while (curr != other.tail) {
        link(cursor, std::make_unique<Node>());
        cursor = cursor->next.get();
        cursor->object = curr->object;
        curr = curr->next.get();
    }
}

GameObjectList::GameObjectList(GameObjectList &&other) noexcept : GameObjectList() {
    swap(*this, other);
}

GameObjectList &GameObjectList::operator=(GameObjectList other) {
    swap(*this, other);
    return *this;
}

void swap(GameObjectList& first, GameObjectList& second) {
    using std::swap;
    swap(first.head, second.head);
    swap(first.tail, second.tail);
}
