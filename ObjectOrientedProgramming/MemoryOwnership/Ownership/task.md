In C++, ownership refers to the responsibility of managing 
the lifecycle of certain resources, 
such as memory, files, network connections, objects, _etc_. 
The ownership model in C++ can be broadly categorized into two kinds: 
ownership of sub-objects stored in object fields 
and ownership of dynamically created objects using pointers.

In C++, classes often contain member fields that represent sub-objects. 
These sub-objects are typically owned by the parent object.
The parent object is responsible for calling their constructors and destructors,
and the memory they occupy is automatically managed by the parent object's lifecycle. 

<div class="hint">

Note that constructors and destructors are called in a specific order,
and, moreover, the order of destruction is the reverse order of initialization.
For example, consider the following class hierarchy:

```c++
class Motherboard { /* ... */ };
class Processor { /* ... */ };
class RandomAccessMemory { /* ... */ };

class Device { /* ... */ };

class Laptop : public Device {
private:
    // Ownership of objects stored in the fields 
    // is managed automatically
    Motherboard motherboard;
    Processor processor;  
    RandomAccessMemory ram;
public:
    /* ... */
};
```

The order of construction of a `Laptop` object would be as follows:
1. the base class `Device` constructor would be called first;
2. then the sub-objects' constructors would be called:
   * the `Motherboard` constructor for the field `motherboard`;
   * the `Processor` constructor for the field `processor`;
   * the `RandomAccessMemory` constructor for the field `ram`;
3. finally, the `Laptop` constructor would be called.

The order of destruction is the opposite:
1. first, the derived class destructor `Laptop` would be called;
2. then the sub-objects' destructors would be called:
   * the `RandomAccessMemory` destructor;
   * the `Processor` destructor;
   * the `Motherboard` destructor;
3. finally, the base class `Device` destructor is called.

</div>

Objects stored in pointer-typed fields are, by default, considered to be non-owned. 
When a class contains a pointer to an object, 
the responsibility for its lifetime and storage duration management lies outside the class. 
It is crucial to understand this fact in order to prevent memory leaks and undefined behavior, 
as ownership is not automatically transferred with the assignment of pointers.

```c++
class Student {
private:
    // Non-owned by default
    Laptop* laptop;
public:
    explicit Student(Laptop* laptop) 
        : laptop(laptop) {}
        
    // the destructor does not destroy the object 
    // pointed to by the laptop field by default        
    ~Student() = default;
};
```

In the example above, the Student class contains 
a pointer to a dynamically allocated `Laptop` object. 
The ownership responsibility for the `Laptop` object
may or may not be assigned to the `Student` class depending on the desired semantics.
If the desired semantics is that the `Student` takes 
ownership of the `laptop` object passed to it in the constructor,
then the developer of this class must ensure that
the object is destroyed manually in the destructor
(for example, by using the `delete` operator).

Objects in pointer-typed fields are considered non-owned by default 
to allow for more explicit control over memory management,
providing more flexibility and efficiency. 

In the scenarios where ownership needs to be transferred, 
[_smart pointers_](https://en.wikipedia.org/wiki/Smart_pointer) 
such as `std::unique_ptr` and `std::shared_ptr` can be used, 
providing automated memory management with reduced risks of memory-related issues.
These smart pointers are specialized classes defined in the standard library of C++.
They behave like plain pointers, in a sense that they support the 
same set of operations, like the dereferencing,
but in addition, they provide specific ownership semantics.
We will discuss smart pointers in more detail in the next few lessons.