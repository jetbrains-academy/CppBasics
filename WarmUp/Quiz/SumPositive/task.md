Implement a function calculating the sum of non-negative integers in an array.

```c++
int sumPositive(int array[], int size);
```

This function takes as arguments an array of integers and its size.
You can assume that the absolute value of all integers in the array does not 
exceed `1000` and that the size of the array is not greater than `100`.

If the array is empty or contains only negative integers, 
then the function should return `0`.

To implement the required function, you might find useful
the arithmetic assignment operator described below.

<div class="hint">

In addition to the regular assignment operator `=`, C++ provides 
[_arithmetic assignment operators_](https://en.cppreference.com/w/cpp/language/operator_assignment): 
`+=`, `-=`, `*=`, `/=`. 
They work as you might expect – for example, the
expression `x += 2` is equivalent to `x = x + 2`.

</div>
