#ifndef CPPBASICS_GOBJECTLIST_HPP
#define CPPBASICS_GOBJECTLIST_HPP

#include <memory>
#include <functional>

#include "gobject.hpp"


/**
 * @class GameObjectList
 * @brief Represents a list of game objects.
 *
 * The class provides functionality to insert, remove, and iterate over game objects.
 */
class GameObjectList {
public:

    /**
     * Constructs an empty list.
     */
    GameObjectList() {
        head = std::make_unique<Node>();
        head->next = std::make_unique<Node>();
        tail = head->next.get();
        tail->prev = head.get();
    }

    /**
     * Constructs a copy of the given list.
     * The game objects itself are not copied, but shared by the original list and its copy.
     */
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

    /**
     * Moves game objects from another list.
     * The list passed as the argument becomes empty.
     */
    GameObjectList(GameObjectList&& other) noexcept : GameObjectList() {
        swap(*this, other);
    }

    /**
     * Re-assigns the list (either by copying or by moving elements from another list).
     */
    GameObjectList& operator=(GameObjectList other) {
        swap(*this, other);
        return *this;
    }

    /**
     * Destructs the list.
     */
    ~GameObjectList() = default;

    /**
     * Swaps the contents of two game object lists.
     */
    inline friend void swap(GameObjectList& first, GameObjectList& second) {
        using std::swap;
        swap(first.head, second.head);
        swap(first.tail, second.tail);
    }

    /**
     * Inserts a game object passed as a std::shared_ptr into the list.
     */
    void insert(const std::shared_ptr<GameObject>& object) {
        if (!object) {
            return;
        }
        std::unique_ptr<Node> node = std::make_unique<Node>();
        node->object = object;
        link(head.get(), std::move(node));
    }

    /**
     * Removes objects from the collection for which the given predicate evaluates to true.
     *
     * @param pred The predicate function used to determine whether an object should be removed.
     */
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


    /**
     * Applies a given function to each game object inside the list.
     *
     * @param apply A function that accept a single game object reference parameter.
     */
    void foreach(const std::function<void (GameObject&)>& apply) {
        Node* curr = head->next.get();
        while (curr != tail) {
            apply(*curr->object);
            curr = curr->next.get();
        }
    }

private:

    /**
     * A node of the doubly-linked list of game objects.
     */
     struct Node {
        Node* prev = nullptr;
        std::unique_ptr<Node> next;
        std::shared_ptr<GameObject> object;
    };


    /**
     * Links a new node into the list after the given cursor node.
     *
     * @param cursor A pointer to the cursor node.
     * @param node A unique pointer to the new node to be linked.
     *
     * @note The ownership of the new node is transferred to the cursor.
     * @note The cursor and node should not be null pointers, otherwise this function will have undefined behavior.
     */
    static void link(Node* cursor, std::unique_ptr<Node>&& node) {
        cursor->next->prev = node.get();
        node->next = std::move(cursor->next);
        node->prev = cursor;
        cursor->next = std::move(node);
    }

    /**
     * Unlinks a given node from a linked list it currently belongs to.
     * It does so by updating the pointers of adjacent nodes.
     *
     * @param node The node to be unlinked from the linked list.
     *
     * @note The provided node should be a valid node in the linked list and should
     *       not be the head or tail of the list.
     *
     * @warning This function does not free the memory occupied by the unlinked node.
     */
    static void unlink(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = std::move(node->next);
    }

    std::unique_ptr<Node> head;
    Node* tail;
};

#endif // CPPBASICS_GOBJECTLIST_HPP
