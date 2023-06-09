Recall that memory is just a sequence of addressable memory cells.
Does it mean that given the address of a memory cell, 
we can make a "step further" in this sequence and look into the "next" memory cell?
Can we make a jump and look into a memory cell located at a distance of, say, 5 steps?
Or, given two memory addresses, can we compute how far they are from each other?

The answer is YES, but there are some nuances.

Let us have an array of type `char`.

```c++
const int SIZE = 8;
char a[SIZE] = "abcdefgh";
```

<div class="hint">

Recall that `char` is a type used to encode ASCII character letters.
It is guaranteed that this type has the size of 1 byte, that 
is, the size of the minimal addressable memory cell. 
Thus, it is often convenient to use type `char*` to store the addresses of memory cells.

</div>

Let us define a pointer pointing to the first element of this array.

```c++
char* p0 = &a[0];
```

Now, `p0` points to the first element of the array.

```c++
std::cout << *p0 << "\n";
// prints a
```

In order to make one more step and look into the next element, 
we can add an integer value `1` to the pointer `p0`.

```c++
char* p1 = p0 + 1;
```

Now, `p1` points to the second element of the array. 

```c++
std::cout << *p1 << "\n";
// prints b
```

It is not necessary to save the derived pointer into a variable, 
we can also dereference it directly. 

```c++
std::cout << *(p0 + 1) << "\n";
// also prints b
```

You can also use increments and decrements on pointers.

```c++
char* p = p0;
++p;
std::cout << *p << "\n";
// also prints b
```

Similarly, it is possible to obtain a pointer to any element of an array.

```c++
std::cout << *(p0 + 5) << "\n";
// prints f
```

BUT we can jump only within the memory chunk occupied by the array `a`!
Access to memory cells outside the memory chunk occupied by 
the array leads to undefined behavior!
For example, the following code snippet is erroneous.

```c++
std::cout << *(p0 + 20) << "\n";
```

It might not lead to an immediate program crash.
However – and it might be even worse – the program's behavior is undefined: 
it can print any value, or not print anything at all, 
or do something entirely different. 

<div class="hint">

This is not the first time we encounter the term *undefined behavior*. 
We promise that eventually, we will give a more detailed explanation of what it means 
and what practical consequences it has. 
For now, just remember that you should avoid *undefined behavior* in your programs.

</div>

Subtracting an integer value from a pointer is also a valid operation:
just remember that the pointer should remain within the memory chunk of the array.

```c++
char* q = p1 - 1;
std::cout << *q << "\n";
// prints a
```

Besides, it is possible to get the difference between two pointers, 
that is, to compute the distance between them as the number of memory cells.

```c++
char* p8 = p0 + 8;
int diff = p8 - p0;
std::cout << diff << "\n";
// prints 8
```

The behavior of arithmetic operations on pointers actually depends on the type of the pointer.
Namely, it depends on the size of the pointed-to type.

For example, let us have an array of type `int` instead of `char`.

```c++
int b[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7 };
```

Taking a pointer to the beginning of the array and then advancing it by `1`
would give us a pointer pointing to the second element of the array, 
not the second memory cell. 

```c++
int* r = &b[0];
++r;
std::cout << *r << "\n";
// prints 1
```

Recall that `int` typically takes `4` bytes.
Under this assumption, the variable `r` points to the `4`-th memory cell.   

In general, given a pointer of type `T*`, the expression `p + n`
is equivalent to `p + n * sizeof(T)` if we "measure" `p` in terms of memory cells.
That is, you can view a pointer as a scale with the size of 
the pointed-to type being its unit of measure.

To sum up, all the operations on pointers we mentioned above are known as **pointer arithmetic**.
It includes:

* adding an integer offset to a pointer: `p + n`;
* subtracting an integer offset from a pointer: `p - n`;
* incrementing and decrementing pointers: `p++`, `--p`, etc;
* computing the distance between pointers: `p - q`.

Above, `p` and `q` are pointers and `n` is an integer.

Remember that pointer arithmetic operators are only applicable 
to pointers to the same array, that is, to the memory region
within the range `p` .. `p + size` (inclusive), where:
* `p` is the pointer to the array's beginning, and
* `size` is the size of the array.

Besides these arithmetic operations, comparison operators are also applicable to pointers:

* checking pointers for (in)equality: `p == q`, `p != q`;
* comparing pointers: `p <= q`, `p > q`, etc.

Note that any two pointers can be checked for (in)equality, 
but only the pointers pointing to the same memory chunk
(i.e., occupied by the same array)
can be compared using the less-than-or-equal-to `<=` and similar operators. 