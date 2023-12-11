One of the most common requirements your code should meet is that it should work fast. To measure time needed for computer to execute your program or some parts of it, C++ provides you [`<chrono>`](https://en.cppreference.com/w/cpp/header/chrono) library for dealing with durations, time points, and clocks.

The `std::chrono` library provides three main types:
- `std::chrono::duration`: Represents a time span.
- `std::chrono::time_point`: Represents a point in time.
- `std::chrono::system_clock`: Represents a system-wide real-time clock.

By integrating `std::chrono` into your C++ programs, you can precisely measure execution times and gain insights into performance bottlenecks, facilitating effective optimization strategies.

#### Measuring Execution Time

To measure the execution time of a function or a program, we can get the current time before and after the execution, and then calculate the difference. Here's an example:

```c++
#include <iostream>
#include <chrono>

void functionToTime() {
    long long n = 0;
    for (long long i = 0; i < 1'000'000'000; ++i) {
        n += i;
    }
}

int main() {
    // Get the starting time
    auto start = std::chrono::high_resolution_clock::now();

    // Call the function
    functionToTime();

    // Get the ending time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate and print the difference
    std::chrono::duration<double> diff = end - start;
    std::cout << "Execution time: " << diff.count() << " s\n";

    return 0;
}
```

You can run this code multiple times, changing the number of iterations of `for` loop, to see the difference in execution time.