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