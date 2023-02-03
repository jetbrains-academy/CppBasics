Every variable occupies some space in the program's memory. 
The exact amount of space it occupies depends on the 
**size** of the type of the said variable. 

In C++, one can know the size of the type in 
[bytes](https://en.wikipedia.org/wiki/Byte) 
using the `sizeof` operator.

```c++
std::cout << sizeof(int) << std::endl;
```

Note that the size of some predefined types, such as `int`, depends 
on the system on which the program is run.

The more memory space the type occupies, 
the more distinct values the variables of this type can represent.
For example, the type `int` commonly occupies 4 bytes on
most machines, and thus, the range of possible values
of this type is from `-2,147,483,648` to `2,147,483,647`.
The type `long` is another integer-valued type, which usually takes 8 bytes.
Because of that, it covers a wider range of possible values:
from `-9,223,372,036,854,775,808` to `9,223,372,036,854,775,807`.

Integer-valued types can also be declared `unsigned`.
This modifier does not change the size of the type 
but affects its value range – `unsigned` integer types
can only have non-negative values.
For example, `unsigned int` has a value range 
from `0` to `4,294,967,295`.

C++ also provides a number of predefined types that 
guarantee to occupy a fixed space on all machines. 
For example, `std::int8_t` takes 8 bits (= 1 byte),
`std::int32_t` takes 32 bits (= 4 bytes), etc. 
For each such type, there exists an `unsigned` counterpart: 
for example, `std::uint8_t`, `std::uint32_t`, etc.

There are also two distinctly sized types to represent
floating point numbers. We have already seen the type `float`,
which typically takes 4 bytes on most modern systems.
The type `double` (stands for double-precision floating-point)
takes twice the space of `float`, usually 8 bytes. 
It is preferred to use the type `double` instead of `float`
whenever possible because it guarantees better precision 
of floating-point arithmetic.
In this course, we use `float` in some tasks 
only because it is also used by the graphical library SFML.

Below, you can find a table containing the information about common predefined types:
whether their size is platform dependent, what their exact or typical size is,
and what value range they encode. 
In order to complete this task, print the sizes of these types to the terminal
(in the same order as they appear in the table, each number on its own line).
Check if the printed numbers match their counterparts in the table.


| Type            | Description                                                | Platform Dependent? | Size in bytes (exact or typical) | Value Range                                             |
|-----------------|------------------------------------------------------------|---------------------|----------------------------------|---------------------------------------------------------|
| `int`           | integer numbers                                            | Yes                 | 4                                | -2,147,483,648 to 2,147,483,647                         |
| `unsigned int`  | positive integer numbers                                   | Yes                 | 4                                | 0 to 4,294,967,295                                      |
| `long`          | long integer numbers                                       | Yes                 | 8                                | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `unsigned long` | unsigned long integer numbers                              | Yes                 | 8                                | 0 to 18,446,744,073,709,551,615                         |
| `float`         | floating-point numbers                                     | Yes                 | 4                                | ±3.40282347E+38F                                        |
| `double`        | double-precision floating-point numbers                    | Yes                 | 8                                | ±1.79769313486231570E+308                               |
| `char`          | characters in [ASCII](https://en.wikipedia.org/wiki/ASCII) | No                  | 1                                | -128 to 127                                             |
| `unsigned char` | unsigned characters                                        | No                  | 1                                | 0 to 255                                                |
| `bool`          | boolean values                                             | Yes                 | 1                                | false, true                                             |
| `std::int8_t`   | 8-bit integer number                                       | No                  | 1                                | -128 to 127                                             |
| `std::int16_t`  | 16-bit integer number                                      | No                  | 2                                | -32768 to 32767                                         |
| `std::int32_t`  | 32-bit integer number                                      | No                  | 4                                | -2,147,483,648 to 2,147,483,647                         |
| `std::int64_t`  | 64-bit integer number                                      | No                  | 8                                | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |






