In C++, the [`std::vector`](https://en.cppreference.com/w/cpp/container/vector) is a dynamic array. It is one of the most popular containers because it combines the advantages of an array (fast random access) with dynamic resizing. Utilizing automatic memory management, it is a great alternative to the regular array, since you don't have to worry about memory leaks and it's methods are more convenient to use.

`std::vector` is a sequential container, and besides size it also has a capacity parameter. The capacity of the container is the number of elements it can store without allocating more memory. The capacity is always greater or equal to the size of the container. When you add elements to the vector and current capacity is not enough to store them, your program will create a bigger vector for the elements. It allocates a new array with a larger capacity, copies the elements from the old array to the new array, and then deallocates the old array. The amount of memory that will be allocated is implementation defined, but usually it depends on the current size, growing exponentially. That's why operations like `push_back()` are performed in [amortized constant time](https://en.wikipedia.org/wiki/Amortized_analysis).

To avoid dynamic memory allocation and deallocation, you can use the `reserve()` method to reserve a certain number of elements. When you know the maximum size in advance, it would be a great way to improve the performance of your program.

You can create vector of any type. For example, `std::vector<int>` is a vector of integers, `std::vector<std::string>` is a vector of strings, and `std::vector<std::vector<int>>` is a vector of vectors of integers (aka 2D array).

Compared to the regular array, vector provides functionality to safely refer to the elements of the array. Method `at()` can be used to access the elements of the vector. It performs bound checking and throws an exception if the index is out of range. It is worth noting that the `operator[]` that does not perform bound checking, is more common, since it is faster than `at()` and similar to the other containers.

When you create a vector and don't specify the elements, they are initialized with a default value. For example, `std::vector<int> v(3)` is a vector of three integers initialized with zeros. You can also specify the initial value. For example, `std::vector<int> v(3, 1)` is a vector of three integers initialized with ones.

Construction of vector can be done in many different ways:

```cpp
// Empty vector
std::vector<int> v1;

// Add element one by one
v1.push_back(1);
v1.push_back(2);
v1.push_back(3);
// v1 = {1, 2, 3}

// Vector creation with a given size and initialization of all elements with a given value
std::vector<int> v2(3, 1); // v2 = {1, 1, 1}

// Creation of a vector from an existing array
int a[] = {1, 2, 3};
std::vector<int> v3(a, a + 3); // v3 = {1, 2, 3}

// Vector creation using an initializer list
std::vector<int> v4 = {1, 2, 3}; // v4 = {1, 2, 3}

// Creating a vector with a given size, all elements are initialized with a default value
std::vector<int> v5(3); // v5 = {0, 0, 0}
```

Common methods of `std::vector` are:
 - `size()` returns the number of elements in the vector
 - `capacity()` returns the capacity of the vector
 - `empty()` is used to check if the vector is empty
 - `clear()` removes all elements from the vector
 - `push_back(x)` adds an element to the end of the vector
 - `emplace_back(x)` is used to construct an element in-place at the end of the vector. It is faster than `push_back()` because it avoids the copy and move operations, but it can be used only if the element isn't already constructed
 - `pop_back()` removes the last element from the vector
 - `resize(x)` is used to change the size of the vector. If you increase the size of the vector, new elements will be initialized with a given value (0 by default). If you decrease the size of the vector, all elements after the new size will be removed
 - `swap(a, b)` swaps the contents of two vectors
 - `front()` and `back()` are returning the first and the last elements of the vector

Moreover, vector allows you to insert and erase elements at any position. The methods are:
- `insert()` is used to insert a single element or a range of elements into the vector. It is relatively slow because it has to move all elements after the removed elements, giving a linear complexity
- `erase()` is used to remove a single element or a range of elements from the vector. It is working in the same way as `insert()`, so think twice before using it

For `std::vector`, as well as for all other containers that may consist of a large number of elements, the right choice is, when you need to pass it to a function, to pass it by reference. If you don't pass it this way, the vector will be copied. It is a big deal when you have a lot of elements in container, because copying them can be time-consuming.
```cpp
void print(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}
```
Note that it is not the case in all situations. If you're going to modify the container, you can either pass it by value (this way the caller won't see the change) or by non-const reference (so that change would be made in an initial container). For more details, see [this article](https://belaycpp.com/2022/02/15/constant-references-are-not-always-your-friends/)

Your task would be to implement a few functions, which should contain vector member functions:
 - `create()` should create a vector of integers and reserve a number of the elements, given as a parameter
 - `fill()` should fill the vector with 10 elements, from 1 to 10
 – `debugPrint()` should print vector's size, capacity, and all elements to the standard output. The format is the following: 
   - `Size: <n>, Capacity: <n>`
   - `Vector: <element1> <element2> ... <elementN>`
