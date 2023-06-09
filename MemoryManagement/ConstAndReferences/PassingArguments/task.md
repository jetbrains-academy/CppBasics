In C++ arguments are by default passed to the function _by value_.
Whenever a program makes a function call with arguments, 
these arguments are copied and passed to the function.
Thus, if the arguments are modified during the execution of the function body,
the calling site will not be aware of these modifications, 
since it only has the originals.

For example, consider a variant of the `swap` function with the following signature:

```c++
void swap(int a, int b) {
    int c = a;
    a = b;
    b = c;
}
```

This function will not actually swap the content of the variables, 
as one might expect.

```c++
int a = 5;
int b = 7;
swap(a, b);
// prints 5
std::cout << a << "\n";
// prints 7
std::cout << b << "\n";
```

This is because arguments are passed by value and thus copied. 

<div class="hint">

At this point, you should already know that the correct way 
to implement `swap` functions is by using pointers or references.
We will get back to this in a moment.

</div>

The copying of arguments might be also undesired if
a function needs to take as an argument a structure occupying a
large amount of memory.

Consider the following structure:

```c++
// rectangle defined by its top-left 
// and bottom-right corner points
struct Rectangle {
    Point2D topLeft;
    Point2D botRight;
};
```

Assuming that `float` occupies 4 bytes, 
the `Rectangle` structure occupies 4 * 4 = 16 bytes.  

```c++
// prints 16
std::cout << sizeof(Rectangle) << "\n";
```

Thus, any function taking the `Rectangle` structure by value 
would end up copying 16 bytes upon each call!

Moreover, if the function needs to modify the rectangle in-place,
it will not not be able to do so because only the copy would change!

To overcome these limitations, C++ allows passing arguments _by reference_.
Since a reference is just the address of a variable in memory, 
it only occupies 4 or 8 bytes, no matter what size the variable's type is.
Besides that, if an argument is passed by reference, 
the function can actually modify it.

For example, we can define a function to scale up a rectangle:

```c++
void scale(Rectangle& rect, float factor) {
    float width = rect.botRight.x - rect.topLeft.x;
    float height = rect.topLeft.y - rect.botRight.y;
    rect.botRight.x = rect.topLeft.x + width * factor;
    rect.botRight.y = rect.topLeft.y - height * factor;
}
```

You can check that the function indeed modifies the rectangle passed as an argument.

```c++
Rectangle rect = { {1, 5}, {6, 3} };
scale(rect, 2);
// prints { {1, 5}, {11, 1} } 
print(rect);
```

Quite often, the function actually does not need to modify the passed arguments – 
references are only needed to avoid excessive copying.
In such cases, the `const` references are used. 
The function `print` mentioned in the code snippet above is a good example of that scenario:

```c++
void print(const Rectangle& rect) {
    std::cout << "{ " 
              << "{ " << rect.topLeft.x  << ", " << rect.topLeft.y  << "}, "
              << "{ " << rect.botRight.x << ", " << rect.botRight.y << "}" 
              << " }";
}
```

In fact, if your function takes an argument by reference but does not need to modify it, 
you should always use the `const` reference. This convention helps to prevent 
a common mistake when a function accidentally modifies the passed argument.

Functions taking arguments by the `const` reference  
are a very common pattern, which you will often see in a C++ codebase.  

Besides, as we have already seen, in C++ functions can also take arguments _by pointers_.
As an example, consider the `scalePtr` function, which takes a pointer to the rectangle instead of a reference:

```c++
void scalePtr(Rectangle* rect, float factor) {
    float width = rect->botRight.x - rect->topLeft.x;
    float height = rect->topLeft.y - rect->botRight.y;
    rect->botRight.x = rect->topLeft.x + width * factor;
    rect->botRight.y = rect->topLeft.y - height * factor;
}
```

As you can see, passing arguments by pointers shares a lot of similarities with passing them by references.
In C++ under most circumstances, the latter approach is preferred.
However, here are few cases where passing by pointers is favored:

- if the function implementation involves pointer arithmetic;
- if the structure passed by the pointer is a part of some dynamic data structure 
  (an example of this is a node of a linked list we saw previously);
- if the function needs to take ownership of the pointed-to memory 
  (for example, to deallocate it).

We will discuss the concept of ownership in more detail later in this course.
