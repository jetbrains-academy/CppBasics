Write a function that copies an array of integers.

```c++
int* copy(int* p, size_t size);
```

This function should take as arguments the pointer to the array's beginning
and the size of the array, allocate a sufficient amount of memory
for the array's copy, and then initialize this memory 
by copying the array's content.
If the size of the array is zero, the function should return a null pointer.