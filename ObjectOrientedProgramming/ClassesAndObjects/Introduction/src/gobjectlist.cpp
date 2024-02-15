#include "gobjectlist.hpp"

void GameObjectList::link(GameObjectList::Node *cursor, std::unique_ptr<Node> &&node) {
    // TODO: write your solution here
}

void GameObjectList::unlink(GameObjectList::Node *node) {
    // TODO: write your solution here
}

GameObjectList::GameObjectList() {
    // TODO: write your solution here
}

void GameObjectList::insert(const std::shared_ptr<GameObject> &object) {
    // TODO: write your solution here
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

GameObjectList::GameObjectList(const GameObjectList &other) : GameObjectList() {
    // TODO: write your solution here
}

GameObjectList::GameObjectList(GameObjectList &&other) noexcept : GameObjectList() {
    // TODO: write your solution here
}

GameObjectList &GameObjectList::operator=(GameObjectList other) {
    // TODO: write your solution here
    return *this;
}

void swap(GameObjectList& first, GameObjectList& second) {
    using std::swap;
    // TODO: write your solution here
}
