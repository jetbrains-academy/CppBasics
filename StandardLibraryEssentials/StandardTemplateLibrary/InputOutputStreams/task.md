In C++, input/output (I/O) operations are performed using streams. A stream is a sequence of bytes that flow from a source (like a keyboard, a file, or a network connection) to a destination (like a screen, a file, or a network connection). The C++ Standard Library provides several classes for performing I/O operations. Their hierarchy is shown [here](https://en.cppreference.com/w/cpp/io#Hierarchy). 

The most basic stream types are the input stream type `istream` and the output stream type `ostream`. These two types create a `iostream` type, which is the type of the standard input stream `std::cin` and the standard output stream `std::cout`. The `istream` type provides the `>>` operator for input and the `ostream` type provides the `<<` operator for output.

```cpp
#include <iostream>

int main() {
    // Standard output (console)
    std::cout << "Hello, World!" << std::endl;

    // Standard input (console)
    int inputNumber;
    std::cout << "Enter a number: ";
    std::cin >> inputNumber;
    std::cout << "You entered: " << inputNumber << std::endl;

    return 0;
}
```

Insert file io3 here