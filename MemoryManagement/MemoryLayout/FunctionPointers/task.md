Functions can also be pointed to!
However, the declaration of the function pointer type is a bit more complicated.

```c++
int (*fptr)(int, int) = nullptr;
```

In the example above, the function pointer `fptr` is declared and initialized to `nullptr`.
The `fptr` pointer can only point to a function of a specified type:
that is, a function taking two arguments of type `int` as arguments
and returning `int` as a result.

We can make `fptr` to point to some actual function:

```c++
int plus(int a, int b) {
    return a + b;
}
// ...
fptr = plus;
```

Now, the function `plus` can be called through the pointer `fptr`:

```c++
// should print 3
std::cout << fptr(1, 2) << "\n";
```

To complete this task, please implement the function `fold`
that should compute the result of some binary operation 
applied consequently to all the elements of an array.

```c++
int fold(int* array, size_t size, int init, int (*f)(int, int));
```

The function `fold` takes as arguments:
- `array` – a pointer to the beginning of the array,
- `size` – the size of the array,
- `init` – the initial value,
- `f` – a pointer to the function, that is, the applied binary operation.

In your implementation, you may assume that neither `array` nor `f` are null pointers.

Here is an example of `fold` usage:

```c++
const int size = 4;
int array[4] = { 1, 2, 3, 4 };
int res = fold(array, size, 0, plus);
// should print 10
std::cout << res << "\n";
```