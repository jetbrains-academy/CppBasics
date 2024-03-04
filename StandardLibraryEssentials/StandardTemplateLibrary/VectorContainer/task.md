In C++, the [`std::vector`](https://en.cppreference.com/w/cpp/container/vector) is a dynamic array. It is one of the most popular containers because it combines the advantages of an array (fast random access) with dynamic resizing. Utilizing automatic memory management, it is a great alternative to the regular array, since you don't have to worry about memory leaks and buffer overflows. 

`std::vector` is a sequential container, and besides size it also has a capacity parameter. The capacity of the container is the number of elements it can store without allocating more memory. The capacity is always greater or equal to the size of the container. When you add elements to the vector and current capacity is not enough to store them, your program will create a bigger vector for the elements. It allocates a new array with a larger capacity, copies the elements from the old array to the new array, and then deallocates the old array. The amount of memory that will be allocated is implementation defined, but usually it depends on the current size, growing exponentially. That's why operations like `push_back()` are performed in [amortized constant time](https://en.wikipedia.org/wiki/Amortized_analysis).

To avoid dynamic memory allocation and deallocation, you can use the `reserve()` method to reserve a certain number of elements. When you know the maximum size in advance, it would be a great way to improve the performance of your program.

You can create vector of any type. For example, `std::vector<int>` is a vector of integers, `std::vector<std::string>` is a vector of strings, and `std::vector<std::vector<int>>` is a vector of vectors of integers (aka 2D array).

Compared to the regular array, vector can safely refer to the elements of the array. Method `at()` is used to access the elements of the vector. It performs bound checking and throws an exception if the index is out of range. You still can use `operator[]` that does not perform bound checking. It is faster than `at()` but it is not safe. 

When you create a vector and don't specify the elements, they are initialized with a default value. For example, `std::vector<int> v(3)` is a vector of three integers initialized with zeros. You can also specify the initial value. For example, `std::vector<int> v(3, 1)` is a vector of three integers initialized with ones.

Construction of vector can be done in many different ways:

```cpp
#include <iostream>
#include <vector>

int main() {
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

    return 0;
}
```

Common methods of `std::vector` are:
 - `size()` returns the number of elements in the vector
 - `capacity()` returns the capacity of the vector
 - `empty()` is used to check if the vector is empty
 - `clear()` removes all elements from the vector
 - `erase(x)` is used to remove a single element or a range of elements from the vector. It is relatively slow because it has to move all elements after the removed elements
 - `insert(x)` is used to insert a single element or a range of elements into the vector. It is working in the same way as `erase()`, so think twice before using it
 - `push_back(x)` adds an element to the end of the vector
 - `emplace_back(x)` is used to construct an element in-place at the end of the vector. It is faster than `push_back()` because it avoids the copy and move operations, but it can be used only if the element isn't already constructed
 - `pop_back()` removes the last element from the vector
 - `resize(x)` is used to change the size of the vector. If you increase the size of the vector, new elements will be initialized with a given value (0 by default). If you decrease the size of the vector, all elements after the new size will be removed
 - `swap(a, b)` swaps the contents of two vectors
 - `front()` and `back()` are returning the first and the last elements of the vector

Your task would be to implement a few functions, which should contain vector member functions:
 - `create_and_reserve()` should create a vector of integers and reserve a 10 elements capacity
 - `fill()` should fill the vector with 10 elements, from 1 to 10
 - `modify_vector()` should remove last element, and after that, make both first and new last elements equal to 200
 - `print_vector()` should print all elements of the vector, separated by a space, and then add a new line at the end
 - `print_size_and_capacity()` should print symbols "Size: " and the size of the vector, then "Capacity: " and the capacity of the vector, separated by a comma and a space, and then add a new line at the end
 - `clear_vector()` should clear the vector and write message `"Vector cleared"` to the standard output
