Sometimes you will need to create your own iterators. For example, you may want to create an iterator that iterates over a custom data structure. In such cases, you will need to know how to create iterators that conform to the standard iterator categories. Different iterator categories are expected in different situations. For example, the algorithms in the STL require iterators that support the forward iterator category. If you want to use an algorithm that requires forward iterators, you will need to ensure that your custom iterator supports the forward iterator category.
In C++, iterators are classified into several categories based on their capabilities and behaviors. The primary iterator categories include:

1. **Input Iterators**: Supports reading values from the pointed-to elements. Once read, the iterator can be incremented to point to the next element.
2. **Output Iterators**: Supports writing values to the pointed-to elements. Once written, the iterator can be incremented to point to the next element.
3. **Forward Iterators**: Combines the features of both input and output iterators. Allows multiple passes through a range and supports both read and write operations.
4. **Bidirectional Iterators**: Enhances forward iterators by adding the ability to move backward through a range using the `--` operator.
5. **Random Access Iterators**: The most feature-rich iterators, providing constant time access to any element in the range, arithmetic operations, and pointer-like behavior.

More information about the iterator categories, as well as comprehensive table, can be found in the [C++ reference](https://en.cppreference.com/w/cpp/iterator).

Iterators can be invalidated by certain operations performed on the container it is tied to. Understanding iterator invalidation is crucial to avoid undefined behavior. Common scenarios leading to iterator invalidation are:
 - **Insertion and Deletion**: Inserting or deleting elements in the container may invalidate iterators pointing to the modified elements.
 - **Resizing the Container**: Resizing operations may cause reallocation, leading to the invalidation of all iterators.
 - **Clearing the Container**: Clearing the container invalidates all iterators pointing to its elements.

For more cases, please refer to this [article](http://kera.name/articles/2011/06/iterator-invalidation-rules-c0x/).

[Iterator traits](https://en.cppreference.com/w/cpp/iterator/iterator_traits) are used to obtain information about the iterator type. For example, the iterator traits can be used to determine the iterator category, the value type, and the difference type of an iterator.

`std::iterator_traits` provide uniform interface to the properties of `LegacyIterator` types, which makes it possible to implement algorithms only in terms of iterators.

The range-based for loop is a new feature introduced in C++11. It provides a concise way to iterate over a container using iterators. The range-based for loop is supported by all standard containers, as well as arrays and initializer lists. The syntax of the range-based for loop is as follows:
```cpp
for (range_declaration : range_expression) loop_statement
```

So, for example, the following code:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    
    std::cout << '\n';
    
    for (auto &i : v) {
        std::cout << i << ' ';
    }
}
```
will print the same line both times:
```
0 1 2 3 4 5
0 1 2 3 4 5
```

Consider using range-based for loops whenever possible, as they are more concise and less error-prone.

Your task is to create a custom bidirectional iterator for vector of integers that supports the following operations:
- Dereferencing
- Increment and decrement operations
- Comparison

Class declaration can be found in `/include/iterator.h` and you need to implement all methods listed there.