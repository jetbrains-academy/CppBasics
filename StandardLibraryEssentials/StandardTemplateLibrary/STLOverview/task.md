In this module, we are going to dive into the Standard Template Library, an ally of every C++ programmer!
Besides the basic language functionality, every C++ compiler provides access to a wide range of pre-written algorithms,
data structures, and other generic classes and functions.
We will cover the following topics:
- `std::vector` functionality
- `std::string` and its optimizations
- Sequential containers, such as `std::forward_list`, `std::deque`, `std::list`, and `std::array`
- Sequential container adapters, such as `std::stack`, `std::queue`, and `std::priority_queue`
- Associative containers, such as `std::set`, `std::map`
- Unordered associative containers, such as `std::unordered_set`, `std::unordered_map`
- Iterators and their types
- STL algorithms
- Input-output streams

The STL comprises hundreds of classes and functions, making it impossible to cover all of them in a single course.
However, we will introduce the most important ones and provide you with the tools to learn the rest on your own.
[Cppreference](https://en.cppreference.com/w/)
is a great resource offering detailed information about the STL and the C++ language in general.

Sometimes, we will refer to the "complexity" of an operation or algorithm.
Complexity measures how much time and memory an operation or algorithm requires to complete.
We will use [Big-O notation](https://en.wikipedia.org/wiki/Big_O_notation)
to describe this complexity.
For example, if an operation takes `O(n)` time,
it means the time to complete is proportional to the size of the input.
`O(1)` or "constant time" indicates that the operation's time does not depend on the input's size.
