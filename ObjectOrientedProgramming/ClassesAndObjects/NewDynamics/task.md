Next, we need to restore the dynamic behavior of our game — the ability
to add and remove objects dynamically during play.
To do so, we will re-implement the doubly linked list data structure
in terms of object-oriented programming.
Before proceeding with this task, please first finish the `Ownership` module,
as we will need some concepts taught there.

First of all, instead of completely rewriting the `GameplayStaticScene` class,
we will just add a new class — `GameplayDynamicScene`, where we will implement the new dynamic functionality.

Please have a look at the declaration of the `GameplayDynamicScene` class (file `dynscene.hpp`),
and its definition (file `dynscene.cpp`).
You can find the brief description of its methods in the documentation comments.

The `GameplayDynamicScene` class has a field `objects` of `GameObjectList` class.
This is the main class we are going to work with in this task — it will implement the doubly linked list.
Its declaration and definition can be found in the files `gobjectlist.hpp` and `gobjectlist.cpp` respectively.

This time, using the object-oriented programming and ownership model,
we will implement a list that will own its nodes.
The nodes will be destructed and deallocated automatically upon destruction of the list itself,
and copying of the list will result in all of its nodes being copied too.

The nodes of the list are represented by the `Node` structure,
which implement the ownership semantics — each node is owning its successor.
Let us have a closer look on the fields of the `Node` structure.

- `next` field is an owning pointer `std::unique_ptr<Node>`.
  Whenever a node is destructed, all its succeeding nodes will also be destructed,
  due to its ownership semantics.
- `prev` field is a plain pointer `Node*`, storing the pointer to a previous node.
  It is a non-owning pointer, because if it was made an owning pointer, then it would
  result into ownership cycle.
  Indeed, giving a node `x`, `x.prev` can point to a node `y`, such that `y.next` points to `x` ---
  this is clearly a cycle.
- `object` field is a shared pointer `std::shared_ptr<GameObject>` to a game object stored in the node.
  It has the shared ownership semantics, so that the shared pointers to game objects
  can be safely returned from the methods of the `GameObjectList` class.
  Also, the shared ownership of game objects will allow us to implement
  the copying of a list — a copy would simply store copies of shared pointers.


The static methods `link` and `unlink` implement the linking and unlinking of nodes respectively.
You have already seen these functions in the `LinkedList` task.
Here is a reminder of their semantics:

```c++
static void link(Node* cursor, std::unique_ptr<Node>&& node);
```

- Links together the `cursor` and `node` nodes, putting `node` right after `cursor`.

```c++
static void unlink(Node* node);
```

- Unlinks the node from its neighboring nodes.

Please implement these methods.
Pay attention to the different ownership semantics of `next`, `prev`, and `object` pointers,
and use `std::move` to manage the ownership.
Remember that `std::unique_ptr` transitions into `nullptr` state after ownership transfer,
and so the order of `std::move` and pointer dereferences becomes important!

Next, consider the fields of the `GameObjectList` class.

- `head` is an owning pointer `std::unique_ptr<Node>` to the first node of the list.
- `tail` is a non-owning pointer `Node*` to the last node of the list.
  It is a non-owning pointer because the pointed-to node is actually owned
  by its predecessor via its `next` pointer.

Because the `head` pointer of the list is owning one, the whole sequence of nodes
belonging to the list will be destroyed automatically upon destruction of the list itself.
This is the reason why we left the default implementation of the class' destructor:

```c++
~GameObjectList() = default;
```

<div class="hint">

Indeed, the destructor of the `GameObjectList` will call
the `~std::unique_ptr()` destructor of the `head` field.
In turn, it will call the destructor of the `Node`,
which will call the destructor `~std::unique_ptr()` of its `next` field,
and so on, until all nodes will be destructed.

</div>

Note that in the previous implementation of the list (in the `LinkedList` task),
we used a single sentinel node to simplify the implementation of some list operating functions.
Moreover, under the hood the list was organized into a cyclic list:
the `next` field of the last node was pointing the first (sentinel) node.
This time we cannot reuse this trick, since a cyclic list would result into ownership cycle.
Therefore, we would need two sentinel nodes — one as the first node, and the second as a last node.

Take a look at the pre-defined methods `foreach` and `remove` of the list
that utilize this list representation:
- `foreach` applies the function given as an argument to every game object stored in the list;
- `remove` unlinks nodes (effectively removing them), whose game object satisfies predicate given as an argument.

<div class="hint">

You might find the type `std::function<...>` unfamiliar.
In essence, it is just an object-oriented counterpart of a function pointer.
We will have a closer look at this type in the later modules of the course.

</div>

Now please implement the default constructor of the `GameObjectList` class
that should initialize two sentinel nodes of the list:

```c++
GameObjectList();
```

Next implement the method for inserting a game object into the end of the list
(just before the last sentinel node):

```c++
void insert(const std::shared_ptr<GameObject>& object);
```

Keep in mind that:
- the first and the last nodes should remain sentinel nodes;
- only the sentinel nodes can store null pointer `nullptr` inside `object` field.

In order to complete this task, also finish the implementation of the ownership semantics of
the `GameObjectList` class, following the rule-of-file and copy-and-swap idiom.
In particular, please implement:

- copy constructor
```c++
GameObjectList(const GameObjectList& other);
```

- moving constructor
```c++ 
GameObjectList(GameObjectList&& other) noexcept;
```

- assignment operator
```c++
GameObjectList& operator=(GameObjectList other);
```

- swap function
```c++
friend void swap(GameObjectList& first, GameObjectList& second);
```

Once you do this, you should be able to run the instance of the game with the new dynamic scene!
