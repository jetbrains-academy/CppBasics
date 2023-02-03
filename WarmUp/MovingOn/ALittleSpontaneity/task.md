It is a bit boring that the consumable object always appears in the same place. 
Let us add a little randomness to its position.

In this step, your task is to implement the following function:

```c++
Circle generateCircle(float radius);
```

This function should generate a random circle with 
the given radius within the borders of the scene. 
In essence, it should generate the center point of this circle.
In other words, this task can be reduced to the task 
of generating a floating-point number within a certain range.

```c++
float generateCoordinate(float min, float max);
```

When generating a random 2D point using `generateCoordinate`, remember that
the following constants define the borders of the scene:
* `NORTH_BORDER`
* `SOUTH_BORDER`
* `WEST_BORDER`
* `EAST_BORDER`

Also, make sure that the resulting circle fits into the borders.

To implement `generateCoordinate` itself, you can use the `rand` 
[function](https://en.cppreference.com/w/c/numeric/random/rand) 
provided by C++.

```c++
// generates a random integer number between 0 and RAND_MAX 
int i = rand();
```

`RAND_MAX` is a special 
[constant](https://en.cppreference.com/w/cpp/numeric/random/RAND_MAX) 
also defined in C++.

Note that in your programs, you should initialize 
C++'s random number generator before the first use of the `rand` function. 

```c++
// initializes random number generator 
// passing current time as a source of randomness.
srand(time(NULL));
```

In the current task, we already did it in the `main` function,
so you don't have to. You can just call `rand`.

However, `rand` generates a random integer number, 
while we need a random floating-point number within a certain range. 
To achieve the latter, use the following formula:

```
x = min + r / (R / (max - min)) 
```

where 
* `x` is the resulting random floating-point number,
* `min` and `max` are range bounds,
* `r` is a random integer number,
* `R` is the maximum integer number `RAND_MAX`.
