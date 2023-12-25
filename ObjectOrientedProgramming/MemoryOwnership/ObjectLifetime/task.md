As we remember from the 'Classes and Objects' block, the constructor and destructor are mandatory elements of any class, and they are responsible for creating and destroying an object.

In this module, we will look at different topics, including memory ownership, the lifetime of an object, and such useful tools as smart pointers.

### Lifetime of the object

Each reference and object has a [lifetime](https://en.cppreference.com/w/cpp/language/lifetime) during the execution time of the program, it depends on the time of creation and destruction of this object. The lifetime of an object begins when the program allocates the required amount of memory to the object and initializes it, including default initialization. The lifetime ends at the moment when the object is manually deleted (for example, when calling the destructor), when exiting the scope of a code block (when we meet the `}` closing curly bracket), or when the place given to the object is occupied by another object or is cleared.

### Object lifetime and storage duration
The concepts of object lifetime and [storage duration](https://en.cppreference.com/w/cpp/language/storage_duration) are related, but they mean different things. Object lifetime refers to the object itself, while storage duration refers to the memory that is allocated for it. The storage duration is the time between the memory allocation of a region and its deallocation, while the lifetime is the time between the construction of an object and its destruction. Object lifetime is equal to or less than the lifetime of its storage. Two objects with the same storage duration can have different lifetimes (especially for objects with dynamic storage duration).