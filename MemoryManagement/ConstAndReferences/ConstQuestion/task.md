Consider the declaration of several variables below:

```c++
int a = 0;
const int b = 0;
int* p = &a;
const int* q = &b;
const int* const r = &b; 
```

Choose valid assignment statements, 
which can be successfully compiled without errors:

```c++
// (1)
a = 1;

// (2)
b = 2;

// (3)
p = q;

// (4)
q = p;

// (5)
*q = 5;

// (6)
r = q;
```

