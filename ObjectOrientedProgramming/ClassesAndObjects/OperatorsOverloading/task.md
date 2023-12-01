Before we dive into object-oriented programming, 
we will learn about another useful feature of the C++ language  
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

As you may notice, just by looking at the code, 
it is much harder to grasp what is happening in the second code fragment.
Fortunately, with operator overloading, it is possible to make 
the two versions of the `move` function look identical!

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

The C++ language allows overloading a [large number of operators](https://en.cppreference.com/w/cpp/language/operators).
Please remember, just like any other feature, it is possible to abuse the operator overloading feature.
It is recommended to overload the operators only if the corresponding notation
has a natural interpretation for your custom data type!

Your next task is to implement several overloaded operators for the data types used in our game. 

Let us start with the familiar operations on `Point2D` data type.
Please overload the arithmetic operators `+`, `-`, `*` for this data type 
(their signatures are already given in the task template).
It is allowed to use `add` and `mul` functions implemented on previous steps. 
Note the difference between subtraction operator and unary minus operator — 
the former subtracts the coordinates of one point from another, 
while the latter just changes the sign of both coordinates of a single point.

Arithmetic operators also do have natural interpretation for shape data types, such as `Circle` and `Rectangle`.

<div class="hint">

Please note that the rectangle is defined by two points — its top-left and bottom-right corners:

```c++
struct Rectangle {
    Point2D topLeft;
    Point2D botRight;
};
```

</div>

If we are adding a point to a shape, then the point is interpreted as a vector and 
the shape should be moved in the direction of this vector.
* For `Circle` shape it is sufficient to add the point to the center of the circle.
* For `Rectangle`, it is required to add the point to both corners of the rectangle. 

Multiplying a shape by a scalar should perform the scaling operation.
* For `Circle`, it is sufficient to multiply the radius to the scalar.
* For `Rectangle` the implementation is a bit trickier. 
  It is required to scale the width and height of the rectangle and then recompute its bottom-right corner.
  You might use the pre-defined functions `width` and `height` to get 
  the corresponding properties of the rectangle (defined in the file `rectangle.hpp`).

```c++
float width(const Rectangle& rect) {
    return rect.botRight.x - rect.topLeft.x;
}

float height(const Rectangle& rect) {
    return rect.botRight.y - rect.topLeft.y;
}
```

Finally, it would be convenient to overload equality comparison operators for all the data types mentioned above.  

<div class="hint">

In the C++ language, it is also possible to overload the input/output operators 
for reading from or writing to the terminal.
Here is an example of corresponding overloads for the `Point2D` data type:

```c++
// output operator overload
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

// input operator overload
std::istream& operator>>(std::istream& is, Point2D& p) {
    return is >> p.x >> p.y;
}
```

Notice the arguments of type `std::ostream` and `std::istream` — those are 
output and input streams respectively.
We have not yet covered them in this course, that would be a topic of the next lessons.
For now, however, it is sufficient to know that `std::cout` and `std::cin`
(which we have seen in previous lessons!) are particular objects of these classes.

Therefore, with the help of the overloads given above, it becomes possible to write the following code:
```c++
Point2D point;
std::cout << "Please enter coordinates of point (x, y)" << std::endl;
std::cin >> point;
std::cout << "Your point is " << point << std::endl;
```

You might find the overloads of the input/output operators 
for the other data types used in our game in the file `operators.hpp`.

</div>
