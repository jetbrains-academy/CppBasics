In order to mitigate potential risks associated with C-style casts,
C++ introduces several casting primitives
that implement additional safety checks.
Unlike the C-style type cast operator, each C++ cast operator 
has its own use-case scenario, and their use helps 
to explicitly communicate the programmer's intention in the code.

There are four different type cast operators in C++:

- `static_cast`
- `reinterpret_cast`
- `const_cast`
- `dynamic_cast`

In this lesson, we will cover the first two, 
and the last two operators will be discussed later in this course.

The `static_cast` [operator](https://en.cppreference.com/w/cpp/language/static_cast) 
can perform a sequence of _implicit and user-defined type conversions_, 
checking the safety of performed conversion and reporting errors at compile time.
For example, `static_cast` can be used to convert a `double` to an `int`.

```c++
double pi = 3.14;
int a = static_cast<int>(pi);
// prints 3
std::cout << a << "\n";
```

In C++, it is generally recommended to use `static_cast`, even
when the type conversion can be performed implicitly
(like in the code snippet above).
The explicitness of `static_cast` helps to easily search through the codebase for
all type conversions
and to mark potentially error-prone pieces of code
(since type conversions are always tricky and error-prone).

An example of a _user-defined_ conversion is the conversion 
between a user-defined `enum` and `int`.

```c++
enum Color { RED, GREEN, BLUE };
int red_code    = static_cast<int>(RED);
int green_code  = static_cast<int>(GREEN);
int blue_code   = static_cast<int>(BLUE);
// prints 0, 1, 2
std::cout << red_code << ", " << green_code << ", " << blue_code << "\n";
```

We will discover more examples of user-defined conversions through the course. 

Not all type conversions are allowed by `static_cast`.
For example, it cannot be used to convert the pointed-to type 
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
[type cast operator](https://en.cppreference.com/w/cpp/language/reinterpret_cast),
is designed precisely for such scenarios. 

```c++
// casting between non-void pointer types 
// with reinterpret_cast is allowed
char* qr = reinterpret_cast<char*>(qi);
```

The `reinterpret_cast` does not change the pointed-to values 
but rather provides a "different view" of a certain memory region.
Basically, it allows for reinterpreting the type of the pointed-to memory region.  

Keep in mind that, like C-style casts, `reinterpret_cast` does not 
implement any safety checks. 
Thus, it is easy to step into the terrain of undefined behavior.

```c++
void* r = malloc(2);
int* ri = reinterpret_cast<int*>(r);
// undefined behavior, again !!!
ri[0] = 42;
```

Like in the case of `static_cast`, the use of `reinterpret_cast` provides 
a way to explicitly mark all potentially dangerous type casts
and clearly communicate the code author's intentions.
