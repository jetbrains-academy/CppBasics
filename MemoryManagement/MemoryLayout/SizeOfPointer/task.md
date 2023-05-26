Recall that every variable occupies some space in the program's memory,
including pointer variables. The size of pointers depends on
the system on which the program is run. 
Typically, on machines with a 32-bit processor, the pointer size is equal to 4 bytes,
meaning that these systems can address up to 4 gigabytes of memory.
On machines with a 64-bit processor, the pointer size is equal to 8 bytes,
which means that at least in theory, there are 16 exabytes of addressable memory.

Because the size of pointers may vary on different systems,
C++ provides two specific types that allow us to work with
pointer arithmetic in a portable manner.

The `size_t` type is designed to store the size of other types in bytes –
the result of the `sizeof` operator is actually of type `size_t`.
It is an __unsigned__ integer type, meaning that its value range spans 
from `0` to the maximum number of addressable memory cells on the given machine.

The `ptrdiff_t` type can be used to store the difference between two pointers – 
the result of the pointer subtraction `p - q` expression has type `ptrdiff_t`.
Unlike `size_t`, it is a __signed__ integer type, 
meaning that its value range includes negative values.
This is expected, since one can subtract a "bigger" pointer `q` from a "smaller" pointer `p`
and get a negative number as the result.

The program attached to this step prints the sizes of the `char*`, `size_t`, and `ptrdiff_t` types to the terminal.


| Type        | Description                               | Platform Dependent? | Size*            | Signed/Unsigned |
|-------------|-------------------------------------------|---------------------|------------------|-----------------|
| `char*`     | pointer type                              | Yes                 | 4 (x32), 8 (x64) | -               |
| `size_t`    | type to store size of types               | Yes                 | 4 (x32), 8 (x64) | Unsigned        |
| `ptrdiff_t` | type to store difference between pointers | Yes                 | 4 (x32), 8 (x64) | Signed          |


*Size is given in bytes, for platform-independent types the exact size is given,
for platform-dependent types the typical size is given. 
