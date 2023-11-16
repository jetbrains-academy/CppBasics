C++ contains a tool that provides exclusive ownership semantics. [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr) is a "smart" pointer that is designed to manage the lifetime of dynamically allocated objects. The unique ownership model ensures that at any given time, only one `std::unique_ptr` instance owns a particular dynamically allocated object. When the owning `std::unique_ptr` is destroyed or explicitly reset, it ensures the deallocation of the associated memory.

#### Main features about std::unique_ptr ownership model
- Exclusive ownership. When a dynamically allocated object comes into the possession of `std::unique_ptr`, no `std::unique_ptr` or other smart pointer (which we will cover further) can share ownership of this object.
- The transfer of ownership occurs through move semantics (they will be discussed in the next step). When a `std::unique_ptr` is moved, the ownership is transferred, and the source `std::unique_ptr` becomes empty (`nullptr`).
- Automatic Deallocation. When a `std::unique_ptr` goes out of scope or is explicitly reset, it automatically releases the memory it owns.
- Support the correct state. `std::unique_ptr` is movable but not copyable. This aligns well with the ownership model, as copying would violate the exclusive ownership semantics.
- Nullability. `std::unique_ptr` can be in a null state (pointing to no object) by default or after a move operation. This feature allows for representing the absence of an object safely and clearly.

`std::unique_ptr` prevents memory leaks and double deletion. These two problems often happen when a programmer deals with the allocation of memory himself. `std::unique_ptr` ensures that an object will be deleted when it is no longer needed, even if an exception is thrown, and prevents an object from being deleted more than once. In addition, it slightly improves code readability: `std::unique_ptr` makes it clear which pointer owns an object and which is responsible for deleting it.

#### Example of usage of `std::unique_ptr`

```c++
#include <iostream>
#include <memory>

class Cat {
public:
    Cat() {
        std::cout << "Cat appeared\n";
    }

    ~Cat() {
        std::cout << "Cat disappeared\n";
    }

    void Meow() {
        std::cout << "Meow!\n";
    }
};

int main() {
    // Creating a unique pointer
    std::unique_ptr<Cat> catPtr = std::make_unique<Cat>();

    // Using the pointer
    if (catPtr) {
        catPtr->Meow();
    }
    
    // Deleting the object manually
    // anotherCatPtr.reset();

    return 0; // MyClass Destructor will be called here
}
```

Your task is to finish the implementation of `create_unique_ptr_array` function. It should create a `std::unique_ptr` with an array of `int` of size `size` and return it.