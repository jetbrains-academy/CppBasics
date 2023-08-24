#ifndef CPPBASICS_GOBJECTLIST_HPP
#define CPPBASICS_GOBJECTLIST_HPP

#include <memory>
#include <functional>

#include "gobject.hpp"

class GameObjectList {
public:

    GameObjectList() {

    }

    void insert(const std::shared_ptr<GameObject>& object) {
        if (!object) {
            return;
        }
        std::unique_ptr<Node> node = std::make_unique<Node>();
        node->object = object;
        link(head.get(), std::move(node));
    }

    void remove(const std::function<bool (const GameObject&)>& pred) {
        Node* curr = head->next.get();
        while (curr) {
            Node* next = curr->next.get();
            if (pred(*curr->object)) {
                unlink(curr);
            }
            curr = next;
        }
    }

    void foreach(const std::function<void (GameObject&)>& apply) {
        Node* curr = head->next.get();
        while (curr) {
            apply(*curr->object);
            curr = curr->next.get();
        }
    }

private:
    struct Node {
        Node* prev = nullptr;
        std::unique_ptr<Node> next;
        std::shared_ptr<GameObject> object;
    };

    static void link(Node* cursor, std::unique_ptr<Node>&& node) {
        cursor->next->prev = node.get();
        node->next = std::move(cursor->next);
        node->prev = cursor;
        cursor->next = std::move(node);
    }

    static void unlink(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = std::move(node->next);
    }

    std::unique_ptr<Node> head;
};

#endif // CPPBASICS_GOBJECTLIST_HPP
