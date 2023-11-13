Consider the declaration of several variables below:

```c++
int a = 0;
double e = 2.71828;
int* p = (int*) malloc(8 * sizeof(int));
```

Choose valid type cast statements
that can be successfully compiled without errors:

```c++
// (1)
double x = static_cast<double>(a);

// (2)
int b = e;

// (3)
int b = (int) e;

// (4)
char* q = static_cast<char*>(p);

// (5)
char* r = reinterpret_cast<char*>(p);

// (6)
std::intptr_t c = reinterpret_cast<std::intptr_t>(p);
```

<div class="hint">

`std::intptr_t` is a special signed integer type that is 
guaranteed to have the same size as the size of the pointer type.

</div>
