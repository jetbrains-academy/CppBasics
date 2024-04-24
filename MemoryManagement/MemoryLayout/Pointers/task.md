In C++, addresses are first-class citizens,
meaning that programmers can manipulate them like any other types of data:
store addresses in variables, pass them as function arguments, print them to the terminal, etc.

A variable that stores the address of a memory cell is called a **pointer**.
In C++, there is no single *pointer* data type; instead, pointers are
additionally typed based on the type of the memory region they point to.
For example, the type `int*` denotes a type of pointers pointing to
a memory region containing a value of type `int`.
As you can see, to create a pointer data type,
you need to add the `*` keyword *after* the pointed-to data type.
Note that you can create pointer types of arbitrary complexity:
for example, `int**` denotes a type of pointers to a pointer to `int`.

As we mentioned, pointers are used to store addresses of variables:

```c++
int a = 42;
// p stores address of variable a
int* p = &a;
// we also say that p points to a
```

The process of obtaining the value to which a pointer points
is also called **dereferencing** the pointer.
This is done with the help of the dereferencing operator `*`.

```c++
int b = *p;
std::cout << b << "\n";
// prints 42
```

Note that there is a difference between reading the value
stored in a pointer (that is, the address of the object)
and dereferencing the pointer and reading the value it points to.

```c++
// prints the value of pointer p - 
// that is, the address of a memory cell,
// for example, 0x7ffee3c260cc; 
// (the actual value is non-deterministic and 
//  may change between different runs of the same program) 
std::cout << p << "\n";
// prints the value that p points to, 
// in this case, 42
std::cout << *p << "\n";
```

Using the dereferencing operator, it is possible to both 
read the data pointed-to and rewrite it.

```c++
*p = 23;
std::cout << *p << "\n";
// prints 23
std::cout << a << "\n";
// also prints 23
std::cout << b << "\n";
// but last line prints 42!
```

You can copy a pointer to another pointer:

```c++
int* q = p;
// both p and q point to a
```

You can also reassign a pointer:

```c++
int c = 23;
p = &c;
// now p points to c
// but q still points to a
```
