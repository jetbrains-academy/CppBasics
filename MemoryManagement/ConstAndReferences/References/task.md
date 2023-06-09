We have already seen that C++ allows programmers 
to manipulate addresses of variables through pointers.
The language also offers another primitive 
to indirectly manipulate variables – that is, _references_. 

References are similar to constant pointers: 
they store the address of a variable and cannot be reassigned.

```c++
int x = 1;
// r is a reference to x
int& r = x;
```

As you can see, references are defined with the help of the operator `&` 
added to the referenced type.

You do not need to use the dereference syntax (operator `*`)
to change the referenced variable, as it can be done with the help of the
regular assignment operator. 

```c++
r = 2;
// prints 2
std::cout << r << "\n";
// also prints 2
std::cout << x << "\n";
```

It is also possible to define a read-only (immutable) reference using the `const` modifier:

```c++
const int& cr = x;
// prints 2
std::cout << cr << "\n";
// the next line will not compile
cr = 3;
```

There are some important differences between pointers and references.  

First, unlike pointer variables, references cannot be left uninitialized:
you have to initialize the reference to point to some variable when you define it.

```c++
// the following code will not compile
int& s;
```

Second, references cannot be initialized with the `nullptr` value.

```c++
// this code also will not compile
int& t = nullptr;
```

Last but not least, you cannot obtain the memory address of a references variable itself.
If you try to apply the address-of operator to a reference variable, it will instead 
return the address of the referenced variable.

```c++
// the following two statements will always print the same address 
std::cout << &x << "\n";
std::cout << &r << "\n";
```

As a byproduct of the last rule, you cannot have nested references
(for example, `int&&`), nor can you define arrays of references.

In other words, a reference to a variable can be seen simply as an alias to this variable.
That gives the compiler some freedom in its treatment of references. For example, the compiler 
is not obliged to allocate memory to store references. If possible, it can simply fold the 
operations on a reference to simple accesses to the referenced variable.

Because of the previously mentioned constraints, the use of references prevents a whole class
of bugs related to pointers: for example, the null pointer dereference error.
You might be asking yourself: if references provide a safer mechanism 
to manipulate the addresses of variables, why not use them always instead of pointers?
Why keep both references and pointers in the languages?

It turns out that both have their use cases. For example, you can only 
apply pointer arithmetic (which is quite useful for implementing many algorithms) 
to pointers but not to a reference.
You will learn how to choose whether to apply pointers or references for you task 
as you will practice programming in C++.

In the following theory step, we will mention one particularly important use case of references in C++ – 
passing arguments to functions by reference.



