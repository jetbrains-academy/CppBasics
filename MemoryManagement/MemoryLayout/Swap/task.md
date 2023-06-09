Implement the function `swap`, which takes two pointers to integers 
and swaps their content (that is, the values they point to).

```c++
void swap(int* p, int* q);
```

Find below an example of `swap` usage.

```c++
int a = 42;
int b = 23;
swap(&a, &b);
// prints 23
std::cout << a << "\n";
// prints 42
std::cout << b << "\n";
```