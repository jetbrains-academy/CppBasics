In contrast to `std::unique_ptr`, [`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr) introduces shared ownership semantics, allowing multiple smart pointers to share control over the same dynamically allocated object. While both smart pointers share some common characteristics, they also differ in several ways. In this section, we will explore the shared ownership model and compare it to the exclusive ownership model of `std::unique_ptr`.

#### Shared Ownership Model and differences between `std::unique_ptr` and `std::shared_ptr`
- Multiple Ownership. `std::shared_ptr` facilitates shared ownership, enabling several smart pointers to collectively manage the lifetime of a dynamically allocated object. This is especially useful when passing pointers to functions or storing them in containers.
- Reference Counting. Under the hood, `std::shared_ptr` implements a reference count to track the number of shared pointers pointing to the same object. The reference count is dynamically adjusted as shared pointers are created or destroyed. When the reference count reaches zero, the managed object is automatically destroyed.
- Ability to copy. While `std::unique_ptr` is movable but not copyable, `std::shared_ptr` is both movable and copyable. Copying a `std::shared_ptr` results in shared ownership and incrementation of reference counter, and the underlying object is only deallocated when the last shared pointer releases its ownership. 
- Automatic Deallocation. Memory associated with the dynamically allocated object is automatically deallocated when the last `std::shared_ptr pointing` to it is destroyed or reset. This ensures proper cleanup without explicit management. 

#### Example of usage of `std::shared_ptr`
```c++
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor\n";
    }

    ~MyClass() {
        std::cout << "MyClass Destructor\n";
    }

    void Display() {
        std::cout << "Hello from MyClass!\n";
    }
};

int main() {
    // Creating a shared pointer
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

    // Using the pointer
    if (sharedPtr) {
        sharedPtr->Display();
    }

    // Creating another shared pointer sharing ownership
    std::shared_ptr<MyClass> anotherSharedPtr = sharedPtr;

    // Both sharedPtr and anotherSharedPtr share ownership of the same object
    std::cout << "sharedPtr.use_count() = " << sharedPtr.use_count() << '\n';

    return 0; // MyClass Destructor will be called here (shared ownership)
}
```

As an exercise, let's develop a system for controlling the number of users in the chat. The user can create a chat (which he automatically enters after creation), join the chat through an invitation from another user, and also exit the chat. We would like to ask you to complete the implementation of the `user` class, as well as the implementation of the `user_count` function, so that the code in the `main` function is executed correctly.