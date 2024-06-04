Besides `std::vector`, the STL includes other sequential containers. The `std::forward_list`, `std::list`, and `std::deque` are sequential containers that allow dynamic resizing and provide different trade-offs in terms of performance and functionality.

[`std::forward_list`](https://en.cppreference.com/w/cpp/container/forward_list) is a [singly linked list](https://en.wikipedia.org/wiki/Linked_list) introduced in C++11. It consumes less memory than `std::list` because it only keeps a link to the next element, but it only supports forward iteration. Notably, you can insert elements and erase them from any position in the list as long as you have an iterator to the element before the position where you want to perform operations.

[`std::list`](https://en.cppreference.com/w/cpp/container/list) is a [doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list). It allows constant-time insert and erase operations anywhere within the sequence and supports iteration in both directions. However, it does not provide fast random access, is not [cache-friendly](https://stackoverflow.com/questions/16699247/what-is-a-cache-friendly-code) due to non-contiguous memory allocation, and uses extra memory to store the linking information associated with each element.

[`std::deque`](https://en.cppreference.com/w/cpp/container/deque), aka a [double-ended queue](https://en.wikipedia.org/wiki/Double-ended_queue), is similar to `std::vector` but allows fast insert and erase operations at both its beginning and end. Unlike `std::vector`, it does not guarantee that all its elements are contiguous in memory, but it does provide fast random access. It is a good general-purpose data structure when both ends of the sequence need to be modified frequently.

Here is an example of usage for each of these containers.

```cpp
// Forward list creation and manipulation
std::forward_list<int> fl = {1, 2, 3};
fl.push_front(0); // fl = {0, 1, 2, 3}
//   fl.push_back(4);  Error: push_back is not supported
fl.pop_front();   // fl = {1, 2, 3}
//   fl.pop_back();    Error: pop_back is not supported
//   fl[1] = 5;        Error: operator[] is not supported
auto second_fl = fl.begin();
fl.insert_after(second_fl, 5); // fl = {1, 5, 2, 3}, O(1) complexity

// List creation and manipulation
std::list<int> l = {1, 2, 3};
l.push_front(0); // l = {0, 1, 2, 3}
l.push_back(4);  // l = {0, 1, 2, 3, 4}
l.pop_front();   // l = {1, 2, 3, 4}
l.pop_back();    // l = {1, 2, 3}
//    l[1] = 5;        Error: operator[] is not supported
auto second_l = std::next(l.begin());
l.insert(second_l, 5); // l = {1, 5, 2, 3}, O(1) complexity

// Deque creation and manipulation
std::deque<int> d = {1, 2, 3};
d.push_front(0); // d = {0, 1, 2, 3}
d.push_back(4);  // d = {0, 1, 2, 3, 4}
d.pop_front();   // d = {1, 2, 3, 4}
d.pop_back();    // d = {1, 2, 3}
d[1] = 5;        // d = {1, 5, 3}
auto second_d = std::next(d.begin());
d.insert(second_d, 0); // d = {1, 0, 5, 3}, O(n) complexity
```

Common methods of these containers are:  
 - `push_front(x)` and `push_back(x)` add an element to the beginning and end of the container, respectively.
 - `pop_front()` and `pop_back()` remove the first and last element from the container, respectively.
 - `insert(x)` is used to insert a single element or a range of elements into the container. For forward lists, use `insert_after(x)` instead.
 - `erase(x)` is used to remove a single element or a range of elements from the container. For forward lists, use `erase_after(x)` instead.
 - `size()` returns the number of elements in the container. Note that `std::forward_list` does not provide a `size()` method.
 - `empty()` checks if the container is empty.
 - `clear()` removes all elements from the container.

One more container worth mentioning is [`std::array`](https://en.cppreference.com/w/cpp/container/array). It is a sequential container that encapsulates fixed-size arrays. It is similar to C-style arrays but provides an interaction interface akin to those of other STL containers. It includes bounds checking using `at()`, a `size()` method, compatibility with a range of functions that accept containers as arguments (moreover, it doesn't decay to a pointer as C arrays might), and support for iterators. It is a good alternative to C-style arrays when the size of the array is known at compile time.

```cpp
// Array creation and initialization
std::array<int, 3> a = {1, 2, 3};

// Accessing elements
std::cout << "First element: " << a.front() << "\n";
std::cout << "Last element: " << a.back() << "\n";

// Size of the array
std::cout << "Size of the array: " << a.size() << "\n";
```

Your task is to write a function called `sum_adjacent_elements`, which takes a collection of integers `nums` of size `n` as input and returns a new collection of the same type with size `n/2`, containing pairwise sums of the elements in `nums`. If an element does not have a pair, it should not be copied into the new collection.
You are required to implement the function using both `std::list` and `std::deque`.

<div class="hint">
  Remember the difference between the two containers. Since `std::deque` allows for random access, you can use the `[]` operator to access elements. Conversely, `std::list` does not support random access, so you will need to use iterators to access elements.
</div>
