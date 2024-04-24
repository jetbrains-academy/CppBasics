There are a lot of situations when a variable of one type should be treated as a variable of another type.
For example, consider the `sqrt` function from the standard library.
This function computes the square root and expects an argument of type `double`.
However, what if we want to compute the square root of an integer, like `4`?
If we try to pass an `int` variable into the `sqrt` function, 
it will be _implicitly converted_ into a `double`.

```c++
int x = 4;
// prints 2.0
std::cout << sqrt(x) << "\n";
```

The C and C++ languages have a large, complex (and slightly different) 
set of [rules](https://en.cppreference.com/w/cpp/language/implicit_conversion) 
on when and how implicit type conversions can be performed.
These rules include conversions between numeric types (such as `int` or `double`).
Importantly, conversions that may result in information loss 
are also allowed. For example, a `double` variable can be converted into an `int`.

```c++
double pi = 3.14;
int a = pi;
// prints 2
std::cout << a << "\n";
```

However, not all reasonable type casts can be performed implicitly.
In such cases, the _C-style type cast operator_ can be used.
We have already seen it while working with `malloc`.
Recall that `malloc` just allocates a contiguous memory region,
which has no type assigned to it. Thus, it returns a pointer of type `void*`.
If the goal is to allocate an array of, say, integers, 
this pointer can then be explicitly cast to `int*`:

```c++
void* q = malloc(2 * sizeof(int));
int* qi = (int*) q;
qi[0] = 42;
```

Note that the C-style type cast operator is very permissive
and does not perform any safety checks. Its misuse can lead to undefined behavior.
For example, consider the following program, 
which accidentally allocates only 2 bytes of memory instead of 
sufficient memory for 2 `int`s.
It then tries to write an `int` value
into the allocated memory (assuming `sizeof(int) == 4`).
This write operation could also affect the memory beyond the allocated range, 
which might lead to unexpected results. 

```c++
void* r = malloc(2);
int* ri = (int*) r;
// undefined behavior !!!
ri[0] = 42;
```

For this reason, C-style type casts should be used with caution. 
The exact set of type conversion rules allowed by C-style casts 
can be found [here](https://en.cppreference.com/w/c/language/cast).






