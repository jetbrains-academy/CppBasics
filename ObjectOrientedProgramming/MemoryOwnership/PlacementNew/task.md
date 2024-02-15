The placement `new` operator is a special version of the `new` operator. 
It allows for the construction of an object in a pre-allocated memory region. 
This can be useful in various scenarios, 
such as reducing memory fragmentation and improving performance.

To use the placement `new` operator, 
one first has to allocate a memory region of appropriate size. 
Then, this memory region needs to be passed into the placement `new` operator. 
The operator will then construct an object of the specified type within the given memory region.

When an object created with the help of the placement `new` operator is no longer needed, 
it must be destroyed by explicitly calling the destructor. 
When working with arrays, the destructor should be called for each object in the array.

Here is an example of how to use the placement `new` operator to construct 
an integer object within a pre-allocated memory region:

```cpp
#include <new>

class Cat {
public:
    explicit Cat(const std::string& name) { /* ... */ }
    ~Cat() { ... }
    std::string getName() { /* ... */ } 
    /* ... */
};

int main() {
  // Allocate a memory region of the appropriate size.
  char buffer[sizeof(Cat)];

  // Construct a Cat object in the given memory region.
  Cat* cat = new (buffer) Cat("Garfield");

  // Access the object.
  std::cout << cat->getName(); << std::endl;

  // Destruct the object.
  cat->~Cat();

  return 0;
}
```

With the help of the placement `new` operator, it is possible to  
fit the lifetimes of several objects within the same storage duration. 
For example, when you reuse a memory region to construct a new object, 
the lifetime of the previous object ends, and the lifetime of the new object begins. 
However, the storage duration of the memory region remains the same.

In order to complete this task, please implement the following functions.

The `createCat` function should create a `Cat` object with the name `"Tom"` in the given memory block:

```c++
Cat* createCat(char* memory);
```

The `destroyCat` function should destroy the `Cat` object residing in the given memory block:

```c++
void destroyCat(char* memory);
```

The `createMouse` function should create a `Mouse` object with the name `"Jerry"` in the given memory block:

```c++
Mouse* createMouse(char* memory);
```

The `destroyMouse` function should destroy the `Cat` object residing in the given memory block:

```c++
void destroyMouse(char* memory);
```