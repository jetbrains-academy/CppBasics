The last thing we need to discuss is a few small but fundamental concepts in C++ that will help you work correctly with the objects you create.

**RAII** stands for *Resource Acquisition Is Initialization* and is pronounced as '*ray*'. It is one of the most essential idioms in modern C++ and is the best way to manage resources safely. It consists of two parts:

1. The constructor of the class should allocate all the resources that the object will use during its lifetime. If errors occur during the execution of the constructor, the destructor will automatically be called, releasing all the resources allocated at the time of the error. For example, creating a container that contains `1'000'000` elements of the `int` type is possible when creating the same container for `100'000'000'000` elements will always fill all memory, which will throw an exception (for example, [`std::bad_alloc`](https://en.cppreference.com/w/cpp/memory/new/bad_alloc)). Otherwise, it can be formulated as "The constructor is completed if and only if it was possible to ensure the invariant of the object and capture all the necessary resources".
2. The destructor of the class should release all the resources that the object used during its lifetime. For example, if the constructor manually allocates memory, the destructor should free it. It is considered a main part of the idiom and is usually the only part assumed when talking about RAII.

In this example we will use a [`std::vector`](https://en.cppreference.com/w/cpp/container/vector), which is a dynamic array. We will cover it in the next module, but for now, we will use it as an example of RAII. Let's look at the following code:
```cpp
#include <vector>

int main() {
    {
        std::vector<int> v(1'000'000);
        // Invariant: size of vector is 1'000'000, memory allocation succeeded.
        v[999'999] = 123; // OK
    }

    try {
        std::vector<int> v(100'000'000'000);
        // Memory allocation failed, invariant is broken. 
        v[99'999'999'999] = 123; // won't be executed, because of exception
    } catch (std::bad_alloc &) {
        std::cout << "caught bad_alloc\n";
    }
}
```

**Rule of five** is a rule created for proper work with resources in C++. If you need to write one of the following methods, then you should write all five: 
1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator

It expands the RAII idiom and allows you to work correctly with resources in C++. It was previously called **Rule of three** because before the introduction of move semantics in C++11, there was no need to write move constructor and move assignment operator.

And now, as we covered the first two, let's talk about the **Copy-and-Swap idiom**. It is a technique that utilizes the `std::swap` function to make the copy assignment operator safe. This usually boils down to swapping contents of both operands, then returning an instance of `*this`. It is used to implement the copy assignment operator in the Rule of five.

The simple implementation of RAII with Copy-and-Swap idiom looks like this:
```cpp
class RAIIexample {
public:
    RAIIexample(std::size_t size) : m_size(size) {
        m_data = new int[size];
    }

    // Copy constructor
    RAIIexample(const RAIIexample & other) : RAIIexample(other.m_size) {
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }

    // Move constructor
    RAIIexample(RAIIexample && other) {
        m_data = other.m_data;
        other.m_data = nullptr;
    }

    // Copy assignment operator
    RAIIexample& operator=(const RAIIexample & other) {
        return *this = RAIIexample(other);
    }

    // Move assignment operator
    RAIIexample& operator=(RAIIexample && other)  noexcept {
        std::swap(m_data, other.m_data);
        return *this;
    }

    // Destructor
    ~RAIIexample() {
        delete[] m_data;
    }
private:
    int* m_data;
    std::size_t m_size;
};
```

To consolidate all the knowledge gained in this module, let's write our implementation of an array with a dynamic size. As a reference, you can look at `std::vector`, which we mentioned earlier, unless your implementation should be simpler.
Take a look at the `dynarray.h` file. You need to implement all the methods that are declared there. To write an implementation, use `dynarray::` as a prefix for all methods. Please use **RAII**, **Rule of five** and **Copy-and-Swap idiom** in your implementation. Besides two constructors and all methods that should be by Rule of five, you need to implement the following methods:
1. `std::size_t size() const` – returns the number of elements in the array.
2. `int &operator[](std::size_t i)` – returns a reference to the element at position `i` in the array.
3. `const int &operator[](std::size_t i) const` – returns a const reference to the element at position `i` in the array.
4. `void swap(dynarray &other)` – swaps the contents of the array with the contents of `other`. You'll need to implement it for the Copy-and-Swap idiom.
5. `friend std::ostream &operator<<(std::ostream &os, const dynarray &arr)` – prints the contents of the array to the output stream `os`. Let's print the array without any brackets and commas, like this: `1 2 3 4 5`. And don't forget to print a newline character at the end of the output.
