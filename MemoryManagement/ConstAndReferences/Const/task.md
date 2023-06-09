In this course, we have already encountered the `const` keyword.
Recall that it allows defining an immutable variable (or simply a _constant_): 
a value can be assigned to such a variable only once when it is defined,
and it cannot be reassigned later. 

As with ordinary mutable variables, it is possible to take the address of 
a constant variable and store it in a pointer variable.
However, the constantness of the pointed-to memory should be reflected 
in the type of the pointer:

```c++
const int x = 5;
const int* p = &x;
```

This way, we tell the compiler that `p` points to immutable memory.
It can then report us a compilation error if we try to
bypass the constantness constraint using a pointer:

```c++
// the following code will cause compilation error
*p = 6;
```

Similarly, it prevents us from storing the address of a constant
in an ordinary pointer:

```c++
// this code also causes compilation error
int* q = &x;
```

Note that the type `const int*` is a type of pointers to a constant integer variable.
The pointer variable itself, however, is non-constant and can be reassigned:

```c++
const int y = 11;
p = &y;
```

On the contrary, it is possible to create a constant pointer to a mutable variable.
Such a pointer itself is constant and cannot be reassigned; 
however, the variable it points to can be reassigned through such a pointer:

```c++
int z = 17;
int* const r = &z;
*r = 21;
// prints 21
std::cout << z << "\n";
// the following code causes compilation error
int w = 32;
r = &w;
```

Therefore, the semantics of the pointer type depends on the  
position of the `const` keyword relative to `*`:
- if `const` is put before `*`, then it signifies the constantness of the pointed-to memory;
- if it is put after `*`, then it signifies the constantness of the pointer itself. 

Of course, it is possible to combine both and define a constant pointer to a constant variable:

```c++
const int* const s = &x;
// this line causes compilation error
*s = 0;
// as well as this one
s = &y;
```

The following table summarizes the semantics of the `const` modifier applied to types:


| Type                  | Description                                              |
|-----------------------|----------------------------------------------------------|
| `const int`           | constant integer numbers                                 |
| `const int*`          | pointers to constant integer numbers                     |
| `int* const`          | constant pointer to (mutable) integer numbers            |
| `const int* const`    | constant pointer to constant (immutable) integer numbers |

