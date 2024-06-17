In C++, [`std::vector`](https://en.cppreference.com/w/cpp/container/vector) functions as a dynamic array. It is one of the most popular containers because it combines the advantages of an array (fast random access) with dynamic resizing. Utilizing automatic memory management, it provides a great alternative to the regular array. It eliminates concerns about memory leaks, and its methods are more convenient to use.

`std::vector` is a sequential container, and besides the size, it also has a capacity parameter. The capacity of the container is the number of elements it can store without allocating more memory. The capacity is always either equal to or greater than the size of the container. When you add elements to the vector and the current capacity is not enough to store them, your program will create a larger vector for these elements. It allocates a new array with a larger capacity, copies the elements from the old array to the new one, and then deallocates the old array. The amount of memory that will be allocated is subject to the implementation, but usually, it depends on the current size, growing exponentially. That's why operations like `push_back()` are performed in [amortized constant time](https://en.wikipedia.org/wiki/Amortized_analysis).

To avoid dynamic memory allocation and deallocation, you can use the `reserve()` method to reserve space for a certain number of elements. When you know the maximum size in advance, this method can greatly improve the performance of your program.

You can create a vector of any type. For example, `std::vector<int>` is a vector of integers, `std::vector<std::string>` is a vector of strings, and `std::vector<std::vector<int>>` is a vector of vectors of integers (aka a 2D array).

Compared to a regular array, a vector provides functionality that safely refers to the elements of the array. The `at()` method can be used to access the elements of the vector. It performs bound checking and throws an exception if the index is out of range. However, it is worth noting that the `operator[]`, which does not perform bound checking, is more commonly used, since it is faster than `at()` and aligns with other containers' functionality.

When you create a vector and don't specify the element values, they are initialized with a default value. For example, `std::vector<int> v(3)` creates a vector of three integers, each initialized to zero. You can also specify an initial value. For example, `std::vector<int> v(3, 1)` creates a vector of three integers, each initialized to one.

A vector can be constructed in many different ways:

```cpp
// Empty vector
std::vector<int> v1;

// Add elements one by one
v1.push_back(1);
v1.push_back(2);
v1.push_back(3);
// v1 = {1, 2, 3}

// Creating a vector with a given size and initializing all elements with a given value
std::vector<int> v2(3, 1); // v2 = {1, 1, 1}

// Creating a vector from an existing array
int a[] = {1, 2, 3};
std::vector<int> v3(a, a + 3); // v3 = {1, 2, 3}

// Creating a vector using an initializer list
std::vector<int> v4 = {1, 2, 3}; // v4 = {1, 2, 3}

// Creating a vector with a given size, all elements are initialized with a default value
std::vector<int> v5(3); // v5 = {0, 0, 0}
```

Common methods of `std::vector` include:
 - `size()` returns the number of elements in the vector.
 - `capacity()` returns the capacity of the vector.
 - `empty()` checks if the vector is empty.
 - `clear()` removes all elements from the vector.
 - `push_back(x)` adds an element to the end of the vector.
 - `emplace_back(x)` constructs an element in-place at the end of the vector. It is faster than `push_back()` because it avoids copy and move operations, but it can only be used if the element hasn't been constructed already.
 - `pop_back()` removes the last element from the vector.
 - `resize(x)` changes the size of the vector. If you increase the size of the vector, new elements will be initialized with a given value (0 by default). If you decrease the size of the vector, all elements past the new size will be removed.
 - `swap(a, b)` swaps the contents of two vectors.
 - `front()` and `back()` return the first and the last elements of the vector, respectively.

Moreover, a vector allows you to insert and erase elements at any position. The methods are the following:
- `insert()` inserts a single element or a range of elements into the vector. It is relatively slow because it has to move all elements after the insert point, which implies linear complexity.
- `erase()` removes a single element or a range of elements from the vector. It works in the same way as `insert()`, so think twice before using it.

For `std::vector`, as well as for all other containers that may consist of a large number of elements, it is usually best to pass it by reference when passing it to a function. If not passed by reference, the vector will be copied. This is a big deal when you have a lot of elements in the container, as copying them can be time consuming.
```cpp
void print(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}
```
Note that this is not the case in every situation. If you're going to modify the container, you can either pass it by value (this way, the caller won't see the changes) or by non-const reference (in order to modify the initial container). For more details, see [this article](https://belaycpp.com/2022/02/15/constant-references-are-not-always-your-friends/).

Your task is to implement several functions, which should use vector member functions:
 - `create()` should construct a vector of integers and reserve a specific number of elements, given as a parameter.
 - `fill()` should populate the vector with 10 elements, ranging from 1 to 10.
 – `debugPrint()` should print the vector's size, capacity, and all elements to the standard output. The format is the following: 
   - `Size: <n>, Capacity: <n>`
   - `Vector: <element1> <element2> ... <elementN>`
