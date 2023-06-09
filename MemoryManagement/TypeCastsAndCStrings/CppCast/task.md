In order to mitigate potential risks associated with C-style casts,
C++ introduces a number of different primitives for type casting
that implement additional safety checks.
Unlike the C-style type cast operator, each of C++ cast operator 
has its own use-case scenario, and their usage helps 
to explicitly communicate the programmer's intention in the code.

There are four different type cast operators in C++:

- `static_cast`
- `reinterpret_cast`
- `const_cast`
- `dynamic_cast`

In this lesson, we are going to explain the first two of them, 
and the latter two operators will be discussed later in this course.

The `static_cast` [operator](https://en.cppreference.com/w/cpp/language/static_cast) 
can perform a sequence of _implicit and user-defined type conversions_, 
checking the safety of performed conversion and reporting errors at compile time.
For example, `static_cast` can be used to convert `double` to `int`.

```c++
double pi = 3.14;
int a = static_cast<int>(pi);
// prints 3
std::cout << a << "\n";
```

In C++, it is generally recommended to use `static_cast` even
in the case when the type conversion might be performed implicitly
(like in the code snippet above).
The explicitness of `static_cast` helps to easily search for
all type conversions through the codebase
and to mark potentially error-prone pieces of code
(and type conversions are always tricky and error-prone).

An example of _user-defined_ conversion is the conversion 
of a user-defined `enum` to `int` and vice versa.

```c++
enum Color { RED, GREEN, BLUE };
int red_code    = static_cast<int>(RED);
int green_code  = static_cast<int>(GREEN);
int blue_code   = static_cast<int>(BLUE);
// prints 0, 1, 2
std::cout << red_code << ", " << green_code << ", " << blue_code << "\n";
```

We will discover more examples of user-defined conversion through the course. 

Not all type conversions are allowed by `static_cast`.
For example, it cannot be used to convert a pointed-to type 
of pointer types as the following example demonstrates:

```c++
void*  q = malloc(2 * sizeof(int));
// casting from void* to int* is allowed
int*  qi = static_cast<int*> (q);
// casting between non-void pointer types is forbidden,
// the following line produces compilation error
char* qc = static_cast<char*>(qi);
```

Another operator, the `reinterpret_cast` 
[type cast operator](https://en.cppreference.com/w/cpp/language/reinterpret_cast)
is designed precisely for such scenarios. 

```c++
// casting between non-void pointer types 
// with reinterpret_cast is allowed
char* qr = reinterpret_cast<char*>(qi);
```

The `reinterpret_cast` does not change the pointed-to values 
but rather provides a "different view" on some memory region.
Basically, it allows to reinterpret the type of the pointed-to memory region.  

Keep in mind that, like C-style casts, `reinterpret_cast` does not 
implement any safety checks. 
Thus, it is easy to step into the undefined behavior land.

```c++
void* r = malloc(2);
int* ri = reinterpret_cast<int*>(r);
// undefined behavior, again !!!
ri[0] = 42;
```

Like in the case of `static_cast`, the usage of `reinterpret_cast` provides 
a way to explicitly mark all potentially dangerous type casts
and clearly communicate the intentions of the code's author.