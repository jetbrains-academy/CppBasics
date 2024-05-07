Recall that memory is just a sequence of addressable memory cells.
Does this mean that given the address of a memory cell, 
we can "step further" in this sequence and look into the "next" memory cell?
Can we make a jump and look into a memory cell located at a distance of, say, 5 steps?
Or, given two memory addresses, can we compute how far apart they are?

The answer is YES, but there are some nuances.

Let us consider an array of type `char`.

```c++
const int SIZE = 8;
char a[SIZE] = "abcdefgh";
```

<div class="hint">

Recall that `char` is a type used to encode ASCII characters.
It is guaranteed that this type has a size of 1 byte, that 
is, the size of the minimal addressable memory cell. 
Thus, it is often convenient to use the type `char*` to store the addresses of memory cells.

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

It is not necessary to save the derived pointer into a variable; 
we can also dereference it directly. 

```c++
std::cout << *(p0 + 1) << "\n";
// also prints b
```

You can also appply increments and decrements to pointers.

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

BUT we can only jump within the memory chunk occupied by the array `a`!
Access to memory cells outside the memory chunk occupied by 
the array leads to undefined behavior!
For example, the following code snippet is erroneous.

```c++
std::cout << *(p0 + 20) << "\n";
```

This might not immediately cause the program to crash.
However – and this could be even worse – the program's behavior is undefined: 
it could print any value, or not print anything at all, 
or do something entirely different. 

<div class="hint">

This is not the first time we've encountered the term *undefined behavior*. 
We promise that eventually, we will give a more detailed explanation of what it means 
and its practical consequences. 
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
that is, to compute the distance between them in terms of the number of memory cells.

```c++
char* p8 = p0 + 8;
int diff = p8 - p0;
std::cout << diff << "\n";
// prints 8
```

The behavior of arithmetic operations on pointers actually depends on the type of the pointer.
Namely, it depends on the size of the pointed-to type.

For example, let us consider an array of type `int` instead of `char`.

```c++
int b[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7 };
```

If we take a pointer to the beginning of the array and then advance it by `1`,
we get a pointer pointing to the second element of the array, 
not the second memory cell. 

```c++
int* r = &b[0];
++r;
std::cout << *r << "\n";
// prints 1
```

Recall that `int` typically takes `4` bytes.
Under this assumption, the variable `r` points to the `4`th memory cell.   

In general, given a pointer of type `T*`, the expression `p + n`
is equivalent to `p + n * sizeof(T)` if we "measure" `p` in terms of memory cells.
That is, you can view a pointer as a scale with the size of 
the pointed-to type acting as its unit of measurement.

To sum up, all the operations on pointers we mentioned above are known as **pointer arithmetic**.
This includes:

* Adding an integer offset to a pointer: `p + n`;
* Subtracting an integer offset from a pointer: `p - n`;
* Incrementing and decrementing pointers: `p++`, `--p`, etc;
* Computing the distance between pointers: `p - q`.

Above, `p` and `q` are pointers and `n` is an integer.

Remember that pointer arithmetic operators are only applicable 
to pointers to the same array, that is, to the memory region
within the range `p` .. `p + size` (inclusive), where:
* `p` is the pointer to the array's beginning, and
* `size` is the size of the array.

Besides these arithmetic operations, comparison operators are also applicable to pointers:

* Checking pointers for (in)equality: `p == q`, `p != q`;
* Comparing pointers: `p <= q`, `p > q`, etc.

Note that any two pointers can be checked for (in)equality, 
but only pointers pointing to the same memory chunk
(i.e., occupied by the same array)
can be compared using the less-than-or-equal-to `<=` and similar operators. 
