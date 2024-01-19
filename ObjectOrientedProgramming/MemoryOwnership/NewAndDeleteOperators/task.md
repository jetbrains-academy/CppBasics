Recall that in the `Memory Management` module of this course,
we studied the `malloc` and `free` functions, which are used 
to allocate and deallocate memory.
As we mentioned, these functions implement C-style memory management,
and C++ has its own tools to manage memory.
It is finally time to meet these tools.

The `new` operator allocates memory on the heap for an object or an array of objects:

```cpp
// allocates memory for one `int` 
int* ptr = new int;
```

The `delete` operator releases the memory back to the heap:

```cpp
delete ptr;
```

To allocate an array of a certain type, the `new[]` operator is used:

```cpp
int* array = new int[10];
```

As always, this operator returns a pointer to the first element of the array.

To deallocate an array, the `delete[]` operator should be used:

```cpp
delete[] array;
```

What is the difference between `malloc/free` and `new/delete`?

The most important difference is that the `new` and `delete` operators 
call the constructor and destructor, respectively.
The `malloc` and `free` functions do not call constructors or destructors;
they are used merely to allocate raw memory blocks.

To highlight the difference between the two, we ask you to complete the following task.
Given the `Book` class defined in the `book.hpp` file, 
create an object of this class using `new`/`delete` syntax in the `newAndDeleteBook` function, 
and then try to allocate memory for an object using `malloc`/`free` syntax in the `mallocAndFreeBook` function.