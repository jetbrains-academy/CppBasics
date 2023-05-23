Implement the `swap` function once again, but this time,
let it take its arguments by reference.

```c++
void swap(int& a, int& b);
```

An example of usage:

```c++
int a = 42;
int b = 23;
swap(a, b);
// prints 23
std::cout << a << std::endl;
// prints 42
std::cout << b << std::endl;
```