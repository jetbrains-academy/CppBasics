In C++, memory ownership refers to the responsibility of managing the allocation and deallocation of memory for objects. Understanding memory ownership is crucial to preventing memory leaks, avoiding double-deletions, and ensuring proper resource management. The ownership model in C++ can be broadly categorized into two types: ownership of sub-objects stored in object fields and ownership of dynamically allocated objects using pointers.

### Ownership of Sub-objects Stored in Object Fields

In C++, classes often contain member variables that represent sub-objects. These sub-objects are typically owned by the parent object, and their memory is automatically managed by the parent's lifecycle. When a class instance is created, its member variables are initialized, and when the instance is destroyed, the destructors of its member variables are automatically called. Note that constructors and destructors are called in the reverse order of initialization, so for the sub-object, the destructor is called before the destructor of the parent object.

For example, consider the following class:
```c++
class Processor {
    // Processor implementation
};

class Laptop {
private:
    Processor laptopProcessor;  // Ownership is automatically managed by Laptop

public:
    // Other methods
};
```

In the example above, the Laptop class owns the Processor object as a sub-object. The Processor object's memory is automatically allocated and deallocated along with the Laptop object.

### Ownership of dynamically allocated objects using pointers

Objects stored in pointer-typed fields are, by default, considered non-owned. When a class contains a pointer to an object, the responsibility for memory management lies outside the class. This is crucial to prevent memory leaks and undefined behaviour, as ownership is not automatically transferred with the assignment of pointers.

```c++
class Student {
private:
    std::string* name;  // Non-owned by default

public:
    Student(std::string n) : name(new std::string(std::move(n))) {}
    ~Student() {
        delete name;  // Responsibility for cleanup is within the class
    }
};

```

In the example above, the Student class contains a pointer to a dynamically allocated `std::string`. The ownership responsibility for the memory allocated for the name lies with the Student class, and it needs to explicitly manage the memory by deleting the name in the destructor.

### Why objects in pointer-typed fields are non-owned by default

C++ follows a philosophy of "you only pay for what you use", which means that C++ provides flexibility and efficiency, and ownership is not automatically assumed to be transferred with a pointer assignment. Objects in pointer-typed fields are considered non-owned by default to allow for more explicit control over memory management. This approach encourages developers to know their responsibilities regarding memory allocation and deallocation, promoting a safer and more predictable memory management model.

In scenarios where ownership needs to be transferred, smart pointers such as `std::unique_ptr` and `std::shared_ptr` can be used to express ownership semantics more explicitly, providing automated memory management with reduced risks of memory-related issues. We will discuss smart pointers in more detail in the next lesson.