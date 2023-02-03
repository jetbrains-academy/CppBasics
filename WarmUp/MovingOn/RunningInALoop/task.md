Let us add more consumable objects to the scene!

We can store several variables of the same type in an 
[_array_](https://en.cppreference.com/w/cpp/language/array). 

```c++
const int SIZE = 4;
Circle circles[SIZE];
```

The code snippet above defines an array containing 4 structures of type `Circle`.
To access the `i`-th element of the array, use the square bracket syntax.
Note that indexing starts from `0`, that is, the first element of the array has the index `0`.

```c++
// reassigns the radius of the first circle in the array 
circles[0].radius = 2.0f;
```

When working with arrays, one of recurring tasks is to 
iterate over all the elements of an array and 
perform some computations with each of them.
Here the `for` [statement](https://en.cppreference.com/w/cpp/language/for) 
comes to the rescue. 

```c++
// prints radii of all circles in the array
for (int i = 0; i < SIZE; ++i) {
    std::cout << circles[i] << " ";
}
```

The `for` loop consists of the following:
* initialization statement: `int i = 0`,
* condition expression: `i < SIZE`,
* iteration expression: `++i`,
* body of the loop: `std::cout << circles[i] << " ";`.

The execution of the `for` loop proceeds as follows:
* when the execution reaches the `for` loop, the initialization statement is executed;
* next, on each iteration, the condition expression is evaluated:
  * if it evaluates to `true`, then the execution proceeds to the loop body, 
  * if it evaluates to `false`, then the execution quits the loop;
* on each iteration, after the execution of the loop's body finishes, 
  the iteration expression is executed and the execution proceeds to the next iteration. 

Note that above we used an 
[increment operator](https://en.cppreference.com/w/cpp/language/operator_incdec) `++i`.
This expression increments the value of the variable by `1` 
and returns the new value.

```c++
int x = 0;
int y = ++x;
// prints "1, 1"
std::cout << x << ", " << y;
```

Similarly, there exists a decrement expression: `--i`.

```c++
int x = 0;
int y = --x;
// prints "-1, -1"
std::cout << x << ", " << y;
```

Both increment and decrement expressions can be used in a pre- or post-form. 
Above, we have seen pre-increment (and pre-decrement): it first increments 
the variable and then returns the new value.
Post-increment (and post-decrement) is written as `x++` (or `x--` correspondingly):
it also increments the variable but returns its value prior to the modification.

In the `for` loop, the condition and iteration expression can be arbitrarily complex.
It gives great flexibility when working with `for` loops. 
For example, to iterate over the elements with an even index in the array, 
one can use the following code:

```c++
// prints radii of all circles with an even index in the array
for (int i = 0; i < SIZE; i += 2) {
    std::cout << circles[i] << " ";
}
```

With all the theory given above, 
your next task is to check for collisions 
of the player object with all the 
consumable objects on the screen. 
To do so, implement the following function:

```c++
void collisionLoop(Circle player, Circle consumable[], bool consumed[], int size);
```

It takes the circle shape of the playable object and
an array of shapes of consumable objects 
together with the boolean array of their state:
* `consumed[i] == true` means that the `i`-th object is consumed;
* `consumed[i] == false` means that the `i`-th object is not yet consumed.

Both arrays have the same size equal to the total number
of consumable objects on the scene given as the last argument.

The function should check whether the playable object 
collides with any of the consumable objects 
and if so, set the state of the corresponding object to "consumed".
Note that once an object is consumed, it cannot change its 
state back to "non-consumed".
To detect collisions, use the `collision` function from the previous steps.