In C++, there is a special **null pointer** value: `nullptr`.
A null pointer does not point to any actual memory location. 
Dereferencing a null pointer leads to *undefined behavior* 
and will most likely cause a runtime error and crash your program.

<div class="hint">

We will go back to the concept of *undefined behavior* later in this course.
For now, just remember that it is a really **bad** thing that you should avoid.

</div>

```c++
int* p = nullptr;
// prints 0
std::cout << p << "\n";
// program crashes
std::cout << *p << "\n";
```

Despite the fact that a null pointer cannot be dereferenced, 
it is not completely useless. 
For example, it can be used to initialize a pointer 
that will be reassigned to an actual address later.
However, it is important never to attempt 
to dereference such a pointer before it has been 
reassigned to a real address. 

<div class="hint">

`nullptr` is a keyword specific to C++.
In the C language, there is an equivalent constant: `NULL`.

</div>

If you have a function that receives a pointer 
and there is no guarantee that this pointer is not null,
you can validate it before attempting 
to dereference the pointer.

```c++
void f(int* p) {
    if (p != nullptr) {
        int v = *p;
        // do the actual work    
    }
}
```

Note that C++ guarantees that `nullptr` evaluates to the integer value `0`
when put in a context where an integer is expected. 
Thus, the above code snippet is equivalent to the following:

```c++
void f(int* p) {
    if (p) {
        int v = *p;
        // do the actual work    
    }
}
```
