Before we dive into object-oriented programming, 
we will learn about another useful feature of C++ language 
that can help to make your code easier to read and understand.
This feature is __operator overloading,__ and it allows you to define various operators, 
like arithmetic operators `+`, `-`, `*`,
for your custom data type.

Recall the function `move` you implemented before. 
At first, your task was to implement it to move an object along `x` axis.
Your code, probably, looked like this:

```c++
float move(float position, float velocity, float delta) {
    return position + delta * velocity;
}
```

At the next stage, your task was to re-implement `move`, 
this time to move an object along both `x` and `y` axis, 
using our custom data type `Point2D` and two functions 
`add` and `mul` defined for it:

```c++
Point2D move(Point2D position, Point2D velocity, float delta) {
    return add(position, mul(delta, velocity));
}
```

As you may notice, the meaning of the latter code fragment is less evident 
and harder to grasp at the first sight.
Fortunately, with operator overloading, it is possible to make 
the two versions of the function look identical!

```c++
Point2D move(Point2D position, Point2D velocity, float delta) {
    return position + delta * velocity;
}
```

To enable this syntax, it is sufficient to define 
a special function with `operator` prefix in its name:

```c++
Point2D operator+(Point2D a, Point2D b) {
    // your code here
}
```

We have already prepared for you a template for several operator functions, 
that would make our work with `Point2D` data type much more pleasant.
Your job is to provide an implementation for these functions.
It is allowed to use `add` and `mul` functions implemented on previous steps. 

[//]: # (TODO: hint about IO streams overloads)