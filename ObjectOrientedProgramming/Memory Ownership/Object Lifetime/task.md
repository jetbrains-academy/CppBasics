As we remember from the 'Classes and Objects' block, the constructor and destructor are mandatory elements of any class, and they are responsible for creating and destroying an object.

In this module, we will look at different topics, including memory ownership, the lifetime of an object and such a useful tool as smart pointers. 

### Lifetime of the object 

Each reference and object has a lifetime during the execution time of the program, it depends on the time of creation and destruction of this object. The lifetime of an object begins when the program allocates the required amount of memory to the object and initializes it, including default initialization. The lifetime ends at the moment when the object is manually deleted (for example, when calling the destructor), when exiting the scope of a code block (when we meet the `}` closing curly bracket), or when the place given to the object is occupied by another object or is cleared.

### Storage duration
Any variable created in the program has one of the following storage durations:
- Automatic storage duration – memory allocation occurs at the beginning of code block `{`, and deallocation occurs at the end of `}`. This type of storage duration has almost all variables that you have worked with before. They are stored in memory region called [stack](https://en.wikipedia.org/wiki/Stack-based_memory_allocation).
- Static storage duration – allocation occurs at the beginning of the program, deallocation – at the end. All global variables (variables outside functions and classes) have this type of storage duration, as well as variables marked with the keyword `extern` or `static`. Such a variable can exist in a single instance (in the case when one of the fields of the class is a static variable, it will be common to all instances of the class).
- Dynamic storage duration – allocation and deallocation occur manually, and you need to monitor this very carefully, otherwise you may forget to delete the variable, and a [memory leak](https://en.wikipedia.org/wiki/Memory_leak) will occur. This type of storage duration has all the variables created using the `new` operator. We will talk about this in more detail in the next step. They are stored in memory region called [heap](https://en.wikipedia.org/wiki/Memory_management#HEAP).
- Thread storage duration is a special kind of storage duration that appears when writing multithreading programs. We will not consider it at the moment.

#### Example of different types of storage duration
```c++
#include <iostream>

int global_variable; // static storage duration

int main() {
    int automatic_variable; // automatic storage duration
    static int static_variable; // static storage duration
    int* dynamic_variable = new int; // dynamic storage duration
    delete dynamic_variable;
}
```

### Object lifetime and storage duration
The concepts of object lifetime and storage duration are related to each other, but they mean different things. Object lifetime refers to the object itself, while storage duration refers to the memory that is allocated for it. Object lifetime is equal to or less than lifetime of its storage. Two objects with the same storage duration can have different lifetime (especially for objects with dynamic storage duration).

### Useful links
- [Storage duration](https://en.cppreference.com/w/cpp/language/storage_duration)
- [Object lifetime](https://en.cppreference.com/w/cpp/language/lifetime)