It is a bit unfortunate that currently the planet can fly outside the visible area. 
Let us fix that!

We need to detect when the object approaches the borders of the window 
and adjust its position so that it does not go beyond the visible area.
Your job is to implement the function 

```c++
Point2D adjustToBorders(Point2D position)
```

Given the position of an object, it adjusts the position to fit into the borders. 

To do that, you need to learn another piece of C++ syntax: 
the `if` [statement](https://en.cppreference.com/w/cpp/language/if).
It allows you to test some condition and 
to branch the execution depending on the result of this test.

```c++
if (a <= b) {
    std::cout << "a <= b";
} else {
    std::cout << "a > b";
}
```

In the code above, we test if the number stored in the variable `a` 
is less than or equal to the one stored in `b`:
* if this is true, then the string `a <= b` is printed;
* if this is false, then the string `a > b` is printed.

You can omit the `else` branch. 

```c++
if (a <= b) {
    std::cout << "a <= b";
}
```

You can also stack up several consecutive tests using the `else if` syntax:

```c++
if (a < b) {
    std::cout << "a < b";
} else if (a == b) {
    std::cout << "a == b";
} else {
    std::cout << "a > b";
}
```

Note here that to compare two numbers for equality, 
we use the operator `==`.  
Do not confuse it with the assignment operator `=`.
For example, the following code also compiles, 
but what it will actually do is not exactly what you might expect:

```c++
if (a = b) {
    std::cout << "a = b";
} 
```

Instead of comparing `a` and `b`, it assigns the 
value of `b` to `a` and then tests if `a` is not equal to zero.

Going back to your task, you will need to compare the current position 
of the object with the border, and if it exceeds the border, 
you need to reassign it back to fit into the border. 

We have already defined the borders for you:

```c++
const float NORTH_BORDER = 0.0f;
const float SOUTH_BORDER = 600.0f;
const float WEST_BORDER  = 0.0f;
const float EAST_BORDER  = 800.0f;
```

Notice the new `const` keyword. 
It allows you to define an immutable variable whose value cannot be reassigned.

Also, note that to compare the object's position with the border,
you also need to take into account the radius of the circle!

```c++
const float RADIUS = 40.0f;
``` 

If you struggle to complete the task, please use the hint below!

<div class="hint">

For example, the check and adjustment against the west border should look like this:

```c++
if (result.x - RADIUS < WEST_BORDER) {
  result.x = WEST_BORDER + RADIUS;
}
```    

</div>



