## Memory-Related Bugs and How to Avoid Them

Manual memory management in C/C++ gives programmers great power, 
but with this power comes great responsibility!
Mistakes in memory management can lead to various issues, 
such as crashes, data corruption, or security vulnerabilities.
In this step, we will give examples of some common memory-related bugs, 
and then we will show how the CLion IDE, with the help of great third-party tools,
can help you discover and fix these nasty bugs!

### Address Escape

You are already familiar with the _address escape_ memory error.
It occurs when a pointer to a memory location within 
the local scope of a function "escapes" the function and 
is used outside of it after the function has returned.
Recall an example from one of the previous steps:

```c++
int* escape() {
    int a = 42;
    return &a;
}

void escapeCaller() {
    int* p = escape();
    std::cout << (void*) p << "\n";
}
```

### Out-of-Bounds Access

Another memory-related bug we have already mentioned is _out-of-bounds access_.
Put simply, this involves accessing memory outside the allocated range.

```c++
char* a = (char*) malloc(8);
// this is valid access
*(a + 2) = 1;
// this is out-of-bounds access
*(a + 9) = 2;
// this is out-of-bounds access too
*(a - 1) = 3;
```

### Memory Leak

In order to deallocate a dynamically allocated memory chunk, 
you need to have a pointer to it.
If you somehow lose this pointer, you will not be able to deallocate the memory.
This programming error is known as a _memory leak_.

To see an example of a memory leak, consider the following function.

```c++
void leak() {
    char* p = (char*) malloc(8);
    std::cout << (void*) p << "\n";
}
```

This function allocates an 8-byte memory chunk and then terminates.
However, the pointer to the allocated memory is neither returned
to the caller nor stored in a global variable.
In fact, it is lost once the function completes,
leading to a memory leak. This means the allocated memory chunk can never be reclaimed.

### Use After Free

Once a memory chunk has been deallocated, 
an attempt to dereference the pointer that was referring to this memory chunk,
or an attempt to access the deallocated memory in any other way, 
would result in undefined behavior. In practice, this could cause your program to crash or data corruption to occur.

```c++
char* p = (char*) malloc(8);
free(p);
// undefined behavior
*p = 7;
```

### Double Free

Similarly, an attempt to deallocate memory a second time 
after it has already been freed can also cause troubles:

```c++
char* q = (char*) malloc(8);
free(q);
// undefined behavior
free(q);
```

### Detecting Memory Bugs

Of course, programmers have already invented some great tools that can help 
detect memory errors in your programs, and the CLion IDE offers convenient 
integrations with such tools. 

The tools for detecting memory-related bugs perform _runtime monitoring_ of your program. 
They inject additional checks into your program to ensure that it does not 
violate any rules of memory management. These checks are performed during the program's execution.
Therefore, the use of memory error checkers may come with some performance penalties. 
For this reason, they are usually not enabled by default, but only during debugging or program testing.

There are two particularly popular tools that help to detect memory errors:
- [AddressSanitizer](https://www.jetbrains.com/help/clion/google-sanitizers.html#AsanChapter)
- [Valgrind Memcheck](https://www.jetbrains.com/help/clion/memory-profiling-with-valgrind.html)

Try to set up one (or both) of these tools in your IDE using the CLion documentation (click the links above).
Then, run the memory error checker on the program attached to this step, 
which contains all the types of memory-related bugs mentioned here. 
The memory error detector should spot them all!
