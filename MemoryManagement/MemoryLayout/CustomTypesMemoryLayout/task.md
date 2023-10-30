Next, let us discuss the memory layout of user-defined custom types: enums and structures.

Enums are represented internally simply as integers.
Given the following declaration of an enum type:

```c++
enum Color {
    RED, GREEN, BLUE
};
```

run the following code to make sure that 
the types `Color` and `int` occupy exactly the same amount of memory:

```c++
std::cout << sizeof(int) << "\n";
std::cout << sizeof(Color) << "\n";
```

Memory layout of structs is more complex, 
as it needs to take into account not only the sizes 
of its components but also their __alignment__.

The [alignment](https://en.cppreference.com/w/cpp/language/object#Alignment) 
of a type is the number of bytes between successive memory addresses 
at which variables of this type can be allocated.
The alignment of a type can be queried using the `alignof` operator,
which returns a value of type `size_t`.
For primitive predefined types, for example, `int` or `double`, 
alignment typically equals the size of the type, 
but it does not have to be true for all types.

```c++
std::cout << alignof(int) << "\n";
// prints 4 on most modern machines
std::cout << alignof(double) << "\n";
// prints 8 on most modern machines
```

<div class="hint">

The motivation for introducing the concept of 
[alignment](https://en.wikipedia.org/wiki/Data_structure_alignment)
in the C++ language stems from the low-level details 
of how processors typically operate on memory.
When writing or reading to/from the memory data of size of, say, 4 bytes,
the processor expects that the accessed memory address 
is a multiplier of 4, that it is _aligned_ to 4 bytes.
Otherwise, such memory access is called _unaligned_.
Depending on the concrete processor architecture,
unaligned memory accesses can be slower or even trigger an error.

</div>

Memory layout of custom structs takes into account the alignment of 
individual fields. If necessary, the compiler inserts _padding_ 
in order to properly align all members of the struct. 
Consider the following structure.

```c++
struct Foo {
    int x;
    char a;
    char b;
    int y;
};
```

Assuming `int` occupies 4 bytes, this struct has the size of 12 bytes and the alignment of 4 bytes.
This is because the compiler inserts 2 additional padding bytes between the fields `b` and `y`.

```c++
std::cout << sizeof(Foo) << "\n";
// prints 12
std::cout << alignof(Foo) << "\n";
// prints 4
```

That is, the internal memory representation of the struct `Foo` is 
equivalent to the memory representation of the following struct:

```c++
struct FooLayout {
    int x;
    char a;
    char b;
    char _padding[2];
    int y;
};
```

You can check it by printing its size and alignment.

```c++
// prints 12
std::cout << sizeof(FooLayout) << "\n";
// prints 4
std::cout << alignof(FooLayout) << "\n";
```

Because of the alignment requirements, two structures 
that have the same set of fields but are declared in a different order
can have different sizes.

For example, the following struct named `Bar`

```c++
struct Bar {
    int x;
    char a;
    int y;
    char b;
};
```

unlike the struct `Foo`, has the size of 16 bytes.

```c++
// prints 16
std::cout << sizeof(Bar) << "\n";
// prints 4
std::cout << alignof(Bar) << "\n";
```

Given a pointer to a structure, you can access its fields using the member access operator `->`.
Assuming `p` is the pointer to `Foo` (i.e., `p` has type `Foo*`),
the following expressions have the same meaning:

| Operator          | Notation |
|-------------------|----------|
| Member of struct  | `(*p).x` |
| Member of pointer | `p->x`   |


In order to access the fields of a struct, 
the compiler computes the offsets of each field. 
For example, in the structure `Bar`, the fields have the following offsets:
* `x` --- 0 bytes,
* `a` --- 4 bytes, 
* `y` --- 8 bytes,
* `b` --- 12 bytes.

You can check that these fields have these offsets by 
printing the corresponding addresses of some allocated structure.

```c++
Bar bar;
std::cout << (void*) &bar << "\n";
std::cout << (void*) &(bar.x) << "\n";
std::cout << (void*) &(bar.a) << "\n";
std::cout << (void*) &(bar.y) << "\n";
std::cout << (void*) &(bar.b) << "\n";
```

Note the `(void*)` part – it is the _C style type case operator_.
We will talk about it later in this course.
Here we need it in order to display variables of type `char*`
not as strings but as memory addresses instead.

To access a field of a structure, it is sufficient to just 
add the offset of the said field to the memory address of the structure.
A reliable and cross-platform way to get an offset of field is by using `offsetof` operator:

```c++
// p points-to a beginning of memory occupied by bar 
char* p = (char*)&bar;
// now p points-to memory occupied by y field of bar 
p += offsetof(struct Bar, y);
// convert it to pointer-to-int
int* pi = (int*) p;
// we can now assign a value into y field
* pi = 42;
// prints 42
std::cout << bar.y << "\n";
```