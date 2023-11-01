New and delete operators are used for dynamic memory allocation in C++. The new operator allocates memory on the heap for an object or an array of objects. The delete operator releases the memory back to the heap.

### new/delete syntax
The syntax for the new operator is

```cpp
int *ptr = new int;
```

After creating a new object, the pointer `ptr` points to the address of the newly created object. 
The syntax for the delete operator is

```cpp
delete ptr;
```

The delete operator releases the memory allocated for the object pointed to by `ptr`.

### new[]/delete[] syntax
The syntax for the new[] operator is

```cpp
int *ptr = new int[10];
```

The new[] operator allocates memory for an array of 10 integers and returns a pointer to the first element of the array.

The syntax for the delete[] operator is

```cpp
delete[] ptr;
```

The delete[] operator releases the memory allocated for the array of objects.

### Difference between new/delete and malloc/free

The new and delete operators are similar to the malloc() and free() functions in C, but there are some key differences:

- The `new` and `delete` operators are overloaded, so they can be used to allocate and deallocate memory for different types of objects, including user-defined types. The `malloc()` and `free()` functions can only be used to allocate and deallocate memory for raw memory blocks.
- The `new` operator calls the constructor of the object it allocates. The `malloc()` function does not call any constructors. The same applies to the `delete` operator and the `free()` function.

Your task is to create a `Book` object using `new`/`delete` syntax in `createAndDeleteBook` function, and then create a `Book` object using `malloc`/`free` syntax in `allocateAndFreeBook` function. The `Book` class is already defined in `main.cpp`.