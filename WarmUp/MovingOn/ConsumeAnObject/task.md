Let us add to the scene another consumable object in the form of the small star.
When the playable object touches this consumable object, the latter should disappear. 

To do that, you will need to implement 
a simple [collision detector](https://en.wikipedia.org/wiki/Collision_detection).
Its job is to signal when two objects collide on the scene.
We will utilize the fact that both our objects have circle shapes; 
this assumption will simplify the task significantly. 

Let us create yet another type to represent circle shapes.

```c++
struct Circle {
    Point2D center;
    float radius;
};
```

Now you need to implement the following function.

```c++
bool collision(Circle circle1, Circle circle2);
```
 
It takes two circles and
* returns `true` if they collide,
* returns `false` otherwise. 

To detect when two circles collide, it is sufficient 
to check that the distance between their centers is less 
than the sum of their radii. 
To calculate the distance between two points, 
implement the corresponding function:

```c++
float distance(Point2D a, Point2D b);
```

Recall that the distance between two points 
in a two-dimensional space can be calculated as follows:

```
dx = x1 - x2
dy = y1 - y2
d = sqrt(dx * dx + dy * dy)
``` 

Here, 
* `x1`, `y1`, `x2`, `y2` are the coordinates of the two points,
* `d` is the resulting distance,
* `dx` and `dy` are differences between the points along the `x` and `y` axes,
* `sqrt` is square root.   

Luckily, the C++ language already has the `sqrt` 
[function](https://en.cppreference.com/w/cpp/numeric/math/sqrt), 
so you won't have to implement your own:

```c++
float sqrt(float x);
```