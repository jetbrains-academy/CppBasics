Previously, you have implemented a function that can move an object horizontally. 
Now, we go into the two-dimensional space, and your job is 
to make the object also move vertically. 

Recall the formula for updating an object's x-coordinate:

```
x` = x + d * v
```

To move an object vertically, you can use the same formula! 

```
y` = y + d * v
```

Now, if we want to move an object in 2 dimensions simultaneously, 
one way to do that would be to implement two functions 
`moveX` and `moveY`. Each one of them will update corresponding
coordinate independently of the other.

Can we do better though? Yes, we can.
Instead of going the way described above, we will go the harder way. 
As you will quickly see, this harder way will pay off.

Programming is all about modelling a world.
And to model a 2D scene, we will need suitable concepts. 
One of such concepts is the concept of a 2-dimensional point. 
Such point consists of two numbers – the x and y coordinates of the point.

We have seen C++ types that can be used to model one number: 
for example, the `float` type. But how can we model a 2D point?
Luckily, C++ allows us to build new types out of the existing ones. 
We can declare our own type of 2D points.

```c++

struct Point2D {
    float x;
    float y;
};

``` 
   
The code snippet above declares a new type
called `Point2D`, which consists of two _fields_
of type `float` named `x` and `y`.
In C++ new types constructed this way as an aggregate of 
other types are also called 
[_structures_](https://en.cppreference.com/w/c/language/struct), 
hence the keyword `struct`.
Fields of a structure are also called _members_.

After the new type is defined, 
we can declare variables of this new type. 

```c++ 
Point2D p;
```

The code above will define an uninitialized variable of `Point2D` type.
As you might remember, leaving variables uninitialized is a bad practice.
To initialize a variable of `struct` type, one can use the following syntax:   

```c++ 
Point2D p = { 0.0, 0.0 };
```

That is, you can list initialization values for all members of a `struct` in curly brackets.
Note that members are initialized in the same order as they are specified in the definition of the `struct`.

To access the members of the structure, one can use the _dot_ syntax.

```c++
float x = p.x; // accessing the x coordinate
float y = p.y; // accessing the y coordinate
```

Points can be summed up just like numbers. 
To sum up two points `u` and `v`, we need to sum their coordinates. 
  
```
c.x = a.x + b.x
c.y = a.y + b.y
```

As a part of this task, you need to implement the function
that will sum up two points:

```c++
Point2D add(Point2D a, Point2D b)
```

Also, points can be multiplied by a number. 
To multiply point `a` by the number `s`, 
we need to multiply each coordinate by that number.

```
b.x = s * a.x
b.y = s * a.y
```
 
You will also need to implement this function.

```c++
Point2D mul(float s, Point2D a)
```

Now we can rethink our movement formula in terms of 2D points.
Let us notice that this formula involves the following ingredients:

* The previous __position__ of the object. It can be modelled as a 2D point `p`.
* The __velocity__ of the object. Since the object can move both in horizontal 
  and vertical directions, we can also model it as a 2D point `v`. 
  The `x` coordinate of this point gives us the horizontal direction 
  of the object, and the `y` coordinate of the point gives us its vertical direction.
* A __time delta__, the number of milliseconds elapsed since the last 
  update of the object's position. This is just a single number `d`.

Now the formula looks as follows:

```
p` = p + d * v
```

Notice how this new formula is in fact just a "clever" way
to write the two formulas for updating each coordinate independently.
You may think that this trick does not buy as much:
instead of two lines of code, we can use just one line.
However, as your tasks will be becoming more challenging, 
you will notice that working with each coordinate 
of an object independently is very frustrating and 
requires a lot of copying and pasting the same code.
The purpose of good programming languages is to save you 
from this burden by giving you a way to build your own _abstractions_
(such as 2-dimensional points) suitable for modelling your problem.  

As the final step of this task, you need to implement a 
new function to move an object in two dimensions
using the functions of adding points and multiplying a point by a number.

```c++
Point2D move(Point2D position, Point2D velocity, float delta);
```

If you implement it correctly, you should see the object 
moving diagonally into the bottom-right corner of the window.
