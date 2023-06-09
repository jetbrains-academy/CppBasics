Every variable occupies some space in the program's memory. 
The exact amount of space it occupies depends on the 
**size** of the type of the said variable. 

In C++, one can know the size of the type in 
[bytes](https://en.wikipedia.org/wiki/Byte) 
using the `sizeof` operator.

```c++
std::cout << sizeof(int) << "\n";
```

Note that the size of some predefined types, such as `int`, depends 
on the system on which the program is run.

The more memory space the type occupies, 
the more distinct values the variables of this type can represent.
For example, the type `int` commonly occupies 4 bytes on
most machines, and thus, the range of possible values for this type 
is from `-2,147,483,648` (equal to `-2^31`) to `2,147,483,647` (equal to `2^31-1`).
The type `long` is another integer-valued type, which usually takes 8 bytes.
Because of that, it covers a wider range of possible values:
from `-9,223,372,036,854,775,808` (equal to `-2^63`) to `9,223,372,036,854,775,807` (equal to `2^63-1`).

Integer-valued types can also be declared `unsigned`.
This modifier does not change the size of the type 
but affects its value range – `unsigned` integer types
can only have non-negative values.
For example, `unsigned int` has a value range 
from `0` to `4,294,967,295` (equal to `2^32-1`).

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

The type `char`, which is used to represent single character 
in ASCII encoding, occupies exactly 1 byte.
Internally, values of `char` type are represented simply 
as unsigned 8 bit (1 byte) integers.

Finally, `bool` type is used to represent boolean `true` or `false` values.
Although, in theory, it is sufficient to use just one bit to represent 
values of this type, in practice, they occupy 1 byte.
This is because 1 byte is the size of minimal memory cell representable 
in modern computer architectures.

Below, you can find a table containing the information about common predefined types:
whether their size is platform dependent, what their exact or typical size is,
and what value range they encode. 
You can also run the program attached to this step to print 
the sizes of these types to the terminal. 
Therefore, you can check whether the sizes of these types on your system 
match the numbers given in the table.

| Type            | Description                                                | Platform Dependent? | Size* | Value Range        |
|-----------------|------------------------------------------------------------|---------------------|-------|--------------------|
| `int`           | signed integer numbers                                     | Yes                 | 4     | -2^31 ... 2^31 - 1 |
| `long`          | long signed integer numbers                                | Yes                 | 8     | -2^63 ... 2^63 - 1 |
| `unsigned int`  | unsigned integer numbers                                   | Yes                 | 4     | 0 ... 2^32 - 1     |
| `unsigned long` | long unsigned integer numbers                              | Yes                 | 8     | 0 ... 2^32 - 1     |
| `std::int8_t`   | 8-bit signed integer number                                | No                  | 1     | -128 ... 127       |
| `std::int16_t`  | 16-bit signed integer number                               | No                  | 2     | -32768 ... 32767   |
| `std::int32_t`  | 32-bit signed integer number                               | No                  | 4     | -2^31 ... 2^31 - 1 |
| `std::int64_t`  | 64-bit signed integer number                               | No                  | 8     | -2^63 ... 2^63 - 1 |
| `std::uint8_t`  | 8-bit unsigned integer number                              | No                  | 1     | 0 ... 255          |
| `std::uint16_t` | 16-bit unsigned integer number                             | No                  | 2     | 0 ... 65535        |
| `std::uint32_t` | 32-bit unsigned integer number                             | No                  | 4     | 0 ... 2^32 - 1     |
| `std::uint64_t` | 64-bit unsigned integer number                             | No                  | 8     | 0 ... 2^64 - 1     |
| `float`         | floating-point numbers                                     | Yes                 | 4     | ±3.4+38F           |
| `double`        | double-precision floating-point numbers                    | Yes                 | 8     | ±1.8E+308          |
| `char`          | characters in [ASCII](https://en.wikipedia.org/wiki/ASCII) | No                  | 1     | -128 ... 127       |
| `unsigned char` | unsigned characters                                        | No                  | 1     | 0 ... 255          |
| `bool`          | boolean values                                             | Yes                 | 1     | false, true        |


*Size is given in bytes, for platform-independent types the exact size is given, 
for platform-dependent types the typical size is given. 






