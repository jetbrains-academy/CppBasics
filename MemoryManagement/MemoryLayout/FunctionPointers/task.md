You can also create pointers to functions!
However, the declaration of a function pointer type is a bit more complicated.

```c++
int (*fptr)(int, int) = nullptr;
```

In the example above, the function pointer `fptr` is declared and initialized to `nullptr`.
The `fptr` pointer can only point to a function of a specified type:
that is, a function taking two arguments of type `int`
and returning an `int` as a result.

We can assign `fptr` to point to some actual function:

```c++
int plus(int a, int b) {
    return a + b;
}
// ...
fptr = plus;
```

Now, the `plus` function can be called using the `fptr` pointer:

```c++
// should print 3
std::cout << fptr(1, 2) << "\n";
```

To complete this task, please implement the `fold` function,
which should compute the result of applying a certain binary operation 
sequentially to all the elements of an array.

```c++
int fold(int* array, size_t size, int init, int (*f)(int, int));
```

The `fold` function takes the following arguments:
- `array` – a pointer to the beginning of the array,
- `size` – the size of the array,
- `init` – the initial value,
- `f` – a pointer to the function implementing the binary operation to be applied.

In your implementation, you can assume that neither `array` nor `f` are null pointers.

Here is an example usage of `fold`:

```c++
const int size = 4;
int array[4] = { 1, 2, 3, 4 };
int res = fold(array, size, 0, plus);
// should print 10
std::cout << res << "\n";
```
