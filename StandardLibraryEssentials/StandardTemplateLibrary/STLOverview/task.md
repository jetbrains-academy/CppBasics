In this module, we are going to dive into the Standard Template Library, ally of every C++ programmer!
Besides basic language functionality, every C++ compiler provides access to a wide range of pre-written algorithms,
data structures, and other generic classes and functions.  
We will start with an overview of the STL, understanding its purpose and the functionality it provides.
We will then delve into specific components of the STL, such as input-output streams,
`std::string`, `std::vector`, and various other sequential and associative containers.
We will also cover the concept of iterators and STL algorithms.

STL consists of thousands of classes and functions, and it is impossible to cover all of them in a single course.
However, we will give you the most important ones and provide you with the tools to learn the rest on your own.
[Cppreference](https://en.cppreference.com/w/)
is a great resource with detailed information about the STL and the C++ language in general.

"Template" in the name means that each piece of it is universal for many types and classes.
Template as a standalone C++ feature would be covered in the future.
However, everything we need to know about them for now is
that the class or function marked as template would have a single implementation for all types,
keeping the same behavior for all of them.
The great thing is that you can store your own classes in containers and functions,
as long as it satisfies the requirements of a template class.

Sometimes we will refer to the "complexity" of an operation or an algorithm.
Complexity is a measure of how much time and memory an operation or an algorithm takes to complete.
We will use the [Big-O notation](https://en.wikipedia.org/wiki/Big_O_notation)
to describe the complexity of an operation or an algorithm.
For example, if an operation takes `O(n)` time,
it means that the time it takes to complete is proportional to the size of the input.
`O(1)` or "constant time" means that the time it takes to complete is relatively small
and does not depend on the size of the input.

Another important aspect that we need to cover before moving forward is the use of `#include` directives.
In C++, the `#include` directive is used to include the contents of one file in another.
It is essential when you want to use a library or a header file in your program.
For example, to use the STL in your program, you would need to include the appropriate STL headers.
The syntax is `#include <library>`, where `library` is the name of the library.
For instance, to use the `std::vector`, you would need to include the vector library like so:
`#include <vector>`, but this rule mostly applies for big classes like containers.
Small functions and classes like `std::sort` are included in big headers
like `<algorithm>` that keep many features inside.
Usually, CLion will help you to include the required header if you forget to make it by yourself. 