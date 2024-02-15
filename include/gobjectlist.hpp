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
    GameObjectList();

    /**
     * Constructs a copy of the given list.
     * The game objects itself are not copied, but shared by the original list and its copy.
     */
    GameObjectList(const GameObjectList& other);

    /**
     * Moves game objects from another list.
     * The list passed as the argument becomes empty.
     */
    GameObjectList(GameObjectList&& other) noexcept;

    /**
     * Re-assigns the list (either by copying or by moving elements from another list).
     */
    GameObjectList& operator=(GameObjectList other);

    /**
     * Destructs the list.
     */
    ~GameObjectList() = default;

    /**
     * Swaps the contents of two game object lists.
     */
    friend void swap(GameObjectList& first, GameObjectList& second);

    /**
     * Inserts a game object passed as a std::shared_ptr into the list.
     */
    void insert(const std::shared_ptr<GameObject>& object);

    /**
     * Removes objects from the collection for which the given predicate evaluates to true.
     *
     * @param pred The predicate function used to determine whether an object should be removed.
     */
    void remove(const std::function<bool (const GameObject&)>& pred);

    /**
     * Applies a given function to each game object inside the list.
     *
     * @param apply A function that accept a single game object reference parameter.
     */
    void foreach(const std::function<void (GameObject&)>& apply);

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
    static void link(Node* cursor, std::unique_ptr<Node>&& node);

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
    static void unlink(Node* node);

    std::unique_ptr<Node> head;
    Node* tail;
};

#endif // CPPBASICS_GOBJECTLIST_HPP
