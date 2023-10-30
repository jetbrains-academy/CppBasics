In C++, a variable of an array type is internally represented 
as a pointer to the first element of the array.
Thus, for example, given the array variable `int a[]`, 
the following expressions have the same meaning:

| Expression                      | Array Notation   | Pointer Notation    |
|---------------------------------|------------------|---------------------|
| Pointer to array initialization | `int* p = &a[0]` | `int* p = a`        |
| Element access by index         | `a[n]`           | `*(a + n)`          |

Given that, a function expecting an array argument can be encoded as 
a function with two arguments:  
* a pointer to the first element, and
* the size of the array.

```c++
void f(int* p, size_t size);
```

In C++ code, you can also often find alternative encoding. 
Same function can be encoded as a function with two arguments 
of different kind:
* a pointer to the first element, and
* a pointer to the __one past the last element of the array__.

```c++
void g(int* begin, int* end);
```

Given an array `a` defined as follows:

```c++
const size_t SIZE = 10;
int a[SIZE];
```

these functions should be called as shown below:

```c++
f(a, SIZE);
```

and

```c++
g(a, a + SIZE);
```

With the second encoding, the iteration through 
all the elements of the array can be written as follows: 

```c++
for (int* p = begin; p < end; ++p) {
    std::cout << *p << "\n";
}
```

<div class="hint">

Note that the code above does not handle 
cases where one of the pointers is a null pointer. 

</div>

This idiom is ubiquitously common in C++ code. 
Thus, it is very important to understand how it works.
You can check your understanding by implementing two functions:
* `sum_size`, and 
* `sum_ptrs`.

Both of these functions should do the same job: 
calculate the sum of all the elements of an array. 
However, the first function takes as arguments 
the pointer to the array's beginning and the array's size,
while the second function takes as arguments 
the pointers to the array's beginning and end.
You can assume that the pointers 
passed to both functions are valid non-null pointers. 
