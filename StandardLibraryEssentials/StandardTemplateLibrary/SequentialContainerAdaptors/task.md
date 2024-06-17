Sequential container adaptors in C++ provide a distinct interface for sequential containers. The `std::stack`, `std::queue`, and `std::priority_queue` are container adaptors that provide specific behaviors.

[`std::queue`](https://en.cppreference.com/w/cpp/container/queue) is a container adaptor that offers a queue data structure with [First-In-First-Out (FIFO)](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)) semantics. Elements are pushed to the end and popped from the front.

[`std::stack`](https://en.cppreference.com/w/cpp/container/stack) is a container adaptor that offers a stack data structure with [Last-In-First-Out (LIFO)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) semantics. Elements are pushed to and popped from only the end of the sequence.

Here is a code example illustrating the usage of `std::stack` and `std::queue`:

```cpp
// Stack creation and manipulation
std::stack<int> s;
s.push(1); // s = {1}
s.push(2); // s = {1, 2}
s.pop();   // s = {1}
std::cout << "Top of the stack: " << s.top() << "\n";

// Queue creation and manipulation
std::queue<int> q;
q.push(1); // q = {1}
q.push(2); // q = {1, 2}
q.pop();   // q = {2}
std::cout << "Front of the queue: " << q.front() << "\n";
```

[`std::priority_queue`](https://en.cppreference.com/w/cpp/container/priority_queue) is a container adaptor that provides a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) data structure. Elements are inserted in an arbitrary order and are removed according to their priority. The priority is defined by the `Compare` template parameter. The default value of `Compare` is `std::less<T>`, which sorts the elements in ascending order.

Here is a code example illustrating the usage of `std::priority_queue`:

```cpp
std::priority_queue<int> pq;
pq.push(2); // pq = {1}
pq.push(1); // pq = {2, 1}
pq.push(3); // pq = {3, 2, 1}
pq.pop();   // pq = {2, 1}
std::cout << "Top of the priority queue: " << pq.top() << "\n"; // Output: 2

std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // comparator is std::greater<int>
pq.push(2); // pq = {2}
pq.push(1); // pq = {1, 2}
pq.push(3); // pq = {1, 2, 3}
pq.pop();   // pq = {2, 3}
std::cout << "Top of the priority queue: " << pq.top() << "\n"; // Output: 2
```

As practice, you will implement a simple text editor that supports the following operations: 
- `insert(w, pos)` - appends the string `w` to the text at position `pos` 
- `erase(pos, len)` - deletes `len` characters from the text starting at position `pos`
- `undo()` - undoes the last operation (either `append` or `delete`)
- `redo()` - redoes the last operation that was undone

The `TextEditor` сlass is defined in `/include/textEditor.h`. 
