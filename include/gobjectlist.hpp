#ifndef CPPBASICS_GOBJECTLIST_HPP
#define CPPBASICS_GOBJECTLIST_HPP

#include <memory>
#include <functional>

#include "gobject.hpp"

class GameObjectList {
public:

    GameObjectList() {
        head = std::make_unique<Node>();
        head->next = std::make_unique<Node>();
        tail = head->next.get();
        tail->prev = head.get();
    }

    GameObjectList(const GameObjectList& other) : GameObjectList() {
        Node* cursor = head.get();
        Node* curr = other.head->next.get();
        while (curr != other.tail) {
            link(cursor, std::make_unique<Node>());
            cursor = cursor->next.get();
            cursor->object = curr->object;
            curr = curr->next.get();
        }
    }

    GameObjectList(GameObjectList&& other) noexcept : GameObjectList() {
        swap(*this, other);
    }

    GameObjectList& operator=(GameObjectList other) {
        swap(*this, other);
        return *this;
    }

    friend void swap(GameObjectList& first, GameObjectList& second) {
        using std::swap;
        swap(first.head, second.head);
        swap(first.tail, second.tail);
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
        while (curr != tail) {
            Node* next = curr->next.get();
            if (pred(*curr->object)) {
                unlink(curr);
            }
            curr = next;
        }
    }

    void foreach(const std::function<void (GameObject&)>& apply) {
        Node* curr = head->next.get();
        while (curr != tail) {
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
    Node* tail;
};

#endif // CPPBASICS_GOBJECTLIST_HPP
