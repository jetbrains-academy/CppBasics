## On types of variables in C++

Before moving forward, we need to make a few 
theoretical remarks about the C++ language.

C++ is a [statically-typed language](https://en.wikipedia.org/wiki/Type_system). 
It means that each variable in this language 
has a fixed type, which should be known statically, 
that is, before the program is run.
The type of the variable determines the set of values it can take
and the set of operations that can be performed on this variable.

In C++, all the variables should be 
[*declared*](https://en.cppreference.com/w/cpp/language/declarations#Simple_declaration) before they can be used.
The declaration of a variable should specify its *type* and *name*.
For example, the following code snippet declares a variable
of type `std::string` with the name `x`. 

```c++
std::string x;
``` 

Upon declaration, each variable can be 
[*initialized*](https://en.cppreference.com/w/cpp/language/initialization) 
with some value of a suitable type. For example, the following code snippet 
initializes a variable of type int with the value `42`.

```c++
int x = 42;
``` 
 
If the variable is uninitialized, then its value before 
the point of its first assignment is *undefined*.
Uninitialized variables are unpleasant errors
(also known as *bugs*) in programs.
Thus, it is very **important** to **always** activate variables
(there might be some rare exceptions to this rule, 
which we are not going to discuss now).

```c++
// x is initialized, good practice!
int x = 0;
// y is uninitialized, bad practice!
int y;
// because the value of y is undefined, 
// z can be anything: 0, -1000, 745912, ...
int z = y;
``` 

You can try running the program attached to this task 
in the [release configuration](https://www.jetbrains.com/clion/features/run-and-debug.html)
multiple times to see that the value of the variable `z` 
can change between invocations.

With that being said, we should also note that variables 
of some types are actually initialized by default to some predefined value. 
An example of such type is `std::string`. 
Variables of this type are initialized with an empty string `""`
automatically upon declaration, and thus they do not require 
manual initialization, except if you want to activate them 
with some other value.

We will learn more about types in C++ later in this course.  
For now, you will need to remember a few basic types 
that we will work with in the following lessons.

| Type          | Description                                                | Example of values       | Initialized |
|---------------|------------------------------------------------------------|-------------------------|-------------|
| `int`         | integer numbers                                            | `0`, `1`, `123`, `-20`  | No          |
| `float`       | floating-point numbers                                     | `0.1`, `3.14`, `1.7e10` | No          |
| `bool`        | boolean values                                             | `true`, `false`         | No          |
| `char`        | characters in [ASCII](https://en.wikipedia.org/wiki/ASCII) | `'a'`, `'b'`, `'1'`     | No          |
| `std::string` | strings                                                    | `"hello"`, `"C++"`      | Yes: `""`   |

