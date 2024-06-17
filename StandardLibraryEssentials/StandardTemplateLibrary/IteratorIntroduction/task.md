During container exploration, you will encounter iterators many times, which is not surprising, since they are closely linked with each other. 

In C++, [iterators](https://en.cppreference.com/w/cpp/iterator) are objects that allow us to traverse the container and access its elements. Basically, they provide a view of a container's elements and offer a unified interface to them.

Iterators behave much like pointers, and in the case of certain container types, they are indeed pointers. An iterator is a means to access the elements of an array or any other container sequentially without exposing the underlying representation.

An iterator must be initialized before use. You can initialize an iterator to the beginning of a container using the `begin()` function or to one position past the end of the container using the `end()` function.

You can move an iterator to the next element in the container using the `++` operator or the `std::next` function. To move an iterator to the previous element, use the `--` operator or the `std::prev` function. You can also move an iterator by a specified number of elements using the `+=` and `-=` operators or by using the `std::advance` function.

Usually, the type of an iterator is a long and complicated expression. The common practise is to use the `auto` keyword when declaring an iterator.

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
std::vector<int>::iterator it = numbers.begin(); // long and complicated type
auto it = numbers.begin(); // using auto
```

The comparison of two iterators is made by the `==` and `!=` operators, which might be useful when checking whether you've reached the end of a container.

You can access the element an iterator points to using the `*` operator. However, dereferencing the `end()` iterator leads to undefined behavior.

```cpp
std::vector<char> characters = {'i', 'a', 'm', 's', 'h', 'o', 'u', 't', 'i', 'n', 'g'};

// Using iterators to modify elements
for (auto it = characters.begin(); it != characters.end(); ++it) {
    *it = std::toupper(*it);
}

// Using iterators to access elements
auto it = characters.begin();
while (it != characters.end()) {
    std::cout << *it++;
}
```

The range-based for loop is a new feature introduced in C++11. It provides a concise way to iterate over a container using iterators. The range-based for loop is supported by all standard containers, as well as arrays and initializer lists. The syntax of the range-based for loop is as follows:
```cpp
for (range_declaration : range_expression) loop_statement
```

So, for example, the following code:
```cpp
std::vector<int> v = {0, 1, 2, 3, 4, 5};

for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << ' ';
}

std::cout << '\n';

for (auto &i : v) {
    std::cout << i << ' ';
}
```
will print the same line both times:
```
0 1 2 3 4 5
0 1 2 3 4 5
```

Consider using range-based for loops whenever possible, as they are more concise and less error-prone.

Given a vector of integers, you need to implement the `find_maximum` function, which returns the message about the maximum element in the vector. The function should use iterators to traverse the vector and find the maximum element.

The format of the message should be: `"Maximum element is <max_element>"`.
If the vector is empty, return `"Vector is empty"`.
