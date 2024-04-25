We have already seen the C++ type used to represent textual data — the `std::string` type.
As you might guess, C has its own way to work with text data.
In C, a string is represented as a pointer to the `char` type:

```c++
const char* greetings = "Hello World!";
std::cout << greetings << "\n";
```

Note that a `char*` type variable does not store any information
about the string's length. According to a rule in the C language,
strings should terminate with a special character, `\0`,
signifying the end of the string.
Therefore, a string's length can be computed 
by iterating over its characters until the `\0` character is found.
The C standard library provides a function for this exact purpose:

```c++
// prints 12
std::cout << strlen(greetings) << "\n";
```

Since C-style strings do not explicitly store the length, 
it is the programmer's responsibility to keep track of that
in order to avoid buffer overflow errors. 
For example, when reading a C-style string from input, 
it is important to use a special function `getline`, 
which considers the string's length 
and prevents memory from being overwritten beyond the string's end:

```c++
const size_t size = 20;
char name[size];
std::cin.getline(name, size);
std::cout << name << "\n";
```

<div class="hint">

Recall that internally, an array of chars `char[]` is represented in 
memory the same way as the pointer `char*`. Thus, in the code snippet above, 
the variable `name` is also considered a C-style string.

<\div>

It is possible to convert C-style strings to C++ style strings, and vice versa:

```c++
std::string cppString = std::string(greetings);
const char* cString = cppString.c_str();  
```

<div class="hint">

In both C and C++ languages, strings defined within the program text
(like the phrase "Hello World!" above) are also called 
[_string literals_](https://en.cppreference.com/w/cpp/language/string_literal)
(or _static strings_).

String literals are stored in a read-only immutable region of static memory. 
Despite that, the C language allows storing string literal values
in pointers to non-const memory:

```c++
// this is valid C code
char* str = "I am immutable!";
```

An attempt to modify a static string leads to undefined behavior.

```c++
// this code causes undefined behavior!
str[5] = " ";
str[6] = " ";
```

Note that the C++ language requires declaring the pointer to static strings as `const char*`; 
otherwise, the code like the one above is rejected with a compilation error.

The reason C does not require the same is purely historical:
the C language initially did not have a `const` keyword and, therefore, 
did not check constantness rules. 

</div>


