One can consider a program's memory as a sequence of memory cells.
Each variable occupies one or several memory cells. 
In modern computers, the size of an individual memory cell is 1 [byte](https://en.wikipedia.org/wiki/Byte).
Thus, for example, a variable of type `std::int32_t` will take 4 memory cells (4 bytes). 

Each memory cell is associated with a unique number – its *address*.

The address of a variable is just the address of the first memory cell 
occupied by this variable. In particular:
* The address of an array variable is the address of the first 
  memory cell of the first element of the array.
* The address of a custom structure variable is the address of the first
  memory cell of the first field of the structure.

In C++, it is possible to ask for the address of a variable – 
for example, to print it to the terminal. 
This can be done by putting the *address-of* operator `&`
in front of the variable's name. 

```c++
int a;
std::cout << &a << "\n";
```

The small program attached to this task prints 
the address of an `int` variable. Run the program to see the address. 
Note that memory addresses are traditionally displayed 
in the [hexadecimal format](https://en.wikipedia.org/wiki/Hexadecimal).