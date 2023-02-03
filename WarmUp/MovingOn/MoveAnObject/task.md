Your next task is to move the planet on the screen 
with the help of a few lines of C++ code.

The position of an object on the screen is defined by its coordinates. 
In a two-dimensional scene, each object has two coordinates: 
the horizontal x-coordinate and the vertical y-coordinate.
As a first step, you will only need to move the object horizontally.

To move an object, you need to implement the function `move`.
Given the previous position of the object, 
the velocity of the object and the time elapsed since 
the last update of the scene this function should
calculate and return the new position of the object.

To calculate the trajectory of an object, you can use a simple formula:

```
x` = x + d * v
```

Here, 

* `x` is the previous x-coordinate of the object;
* `` x` `` is the new x-coordinate of the object;
* `v` is the velocity of the object;
* `d` is time delta.  
