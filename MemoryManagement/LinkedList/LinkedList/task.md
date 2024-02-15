With all the knowledge you obtained about manual memory management in C++, 
we are now turning back to our game, so you can apply your new skills in practice.

Remember, previously we could only have a fixed number of consumable objects on the scene
because we were only aware of the arrays of fixed static size.
Now, your task will be to implement a dynamic data structure that would 
allow us to place an arbitrary number of consumable objects on the scene
and, moreover, to add new objects during the game!

You will need to implement a basic dynamic data structure 
called [_doubly linked list_](https://en.wikipedia.org/wiki/Doubly_linked_list).
This data structure allows storing an arbitrary, not known apriori,
number of elements and add or remove elements dynamically.

In the task description below, we will refer to the doubly linked list 
simply as a list (in general, there are other kinds of [lists](https://en.wikipedia.org/wiki/Linked_list)).
The list consists of _nodes_, represented by the following structure:

```c++
struct Node {
    void* data;
    Node* next;
    Node* prev;
};
```

Each node holds a pointer to the element itself 
and also a pair of pointers pointing to the next and previous nodes. 
Note that we used `void*` as a pointer to an element – 
it allows the user of the list to store elements of an arbitrary type
and do all the necessary type castings on the user's side. 
For simplicity, we will require that the elements themselves should be 
properly allocated by the end user of the list via `malloc`.  

As a starting point, implement two functions to allocate and deallocate memory for a new node:

```c++
Node* createNode(void* data);

void freeNode(Node* node);
```

The function `createNode` should allocate memory for the new node and initialize 
its `data` field with the `data` variable passed as an argument.
Assume that the memory pointed to by `data` is already allocated on the calling site. 
The function `freeNode` should deallocate the memory occupied by the node passed by the pointer,
including the memory pointed to by its `data` field (assuming this memory was allocated using `malloc`).

The next function you should implement is `link`:

```c++
void link(Node* cursor, Node* node);
```

It should link together the `cursor` and `node` nodes, putting `node` right after `cursor`.
Make sure to properly update the `next` and `prev` fields of all relevant nodes, 
that is, the nodes pointed by the `cursor`, `cursor->next`, and `node` pointers. 
You might assume that all nodes which are reachable from `cursor` through `next` and `prev`
are valid nodes and none of their `next` or `prev` pointers are null
(we will see why this is true for our intended list implementation later).

Conversely, the `unlink` function should unlink the node passed by the pointer from its neighbors:

```c++
void unlink(Node* node);
```

It should redirect the `next` and `prev` pointers of `node`'s neighboring nodes
so that they point to each other, instead of `node`.

Now that we have some functions to work with nodes, we can proceed to the list itself.
The list unites a series of nodes into a single data structure.
In fact, because the nodes themselves keep pointers to their neighbors,
it is sufficient to store just a single node in the list data structure – 
all other nodes can be accessed from that single node.

We propose an implementation of the list utilizing the idea of 
[_sentinel node_](https://en.wikipedia.org/wiki/Sentinel_node).
It is a special node that does not hold any useful information itself 
but is used as a sentry always present in a list.
This way, we can avoid handling null pointers in the cases when,
for example, we need to add a first node to the list – in such a 
case, we can just link the node to the sentry.

```c++
struct List {
    Node sentry;
};
```

For this scheme to work properly, we also have to initialize the 
`next` and `prev` fields of the `sentry` node.
We can make them both point to the `sentry` node. 
Therefore, in our encoding, an empty list is modeled as 
a list consisting of a single sentinel node whose `next` and `prev` pointers form a cycle.
Write code for the function `initList` implementing this idea
(set the `data` field of the `sentry` node to `nullptr`):

```c++
void initList(List& list);
```

Next, implement a function that inserts a new node containing given data into the list:

```c++
void insert(List& list, void* data); 
```

And, finally, write a function that removes all the nodes 
whose data satisfy some predicate given as pointer-to-function:

```c++
void remove(List& list, bool (*pred)(void*));
```

It should iterate through all the nodes of the list, excluding the `sentry` node,
call the `pred` function, pass the `data` field of the current node as an argument,
and check what `pred` returns. 
- If it returns `true`, then the `remove` function should
  unlink the current node from the list and free its occupied memory.
  Please use `unlink` and `freeNode` functions to achieve this behavior. 
- If it returns `false`, it should keep the current node in the list and move on to the next node.

Once you implement all these functions correctly (all the tests should pass!),
you will be able to see a consumable star objects popping up on the screen dynamically during the game!
You can try inspecting the modified [main.cpp](course://MemoryManagement/LinkedList/LinkedList/src/main.cpp)
file to see how the list manipulating functions you have implemented are used 
to maintain a dynamic set of consumable objects!

<div class="hint">

As you might have noticed, the code in 
the [main.cpp](course://MemoryManagement/LinkedList/LinkedList/src/main.cpp) file is becoming quite messy. 
In the next module of the course, we will learn about the 
_object-oriented_ features of C++ that will help us better structure the code of our game, 
which will allow us to deliver more complex new functionality with ease!

</div>