In the previous tasks we have added to the scene 
a fixed pre-defined number of consumable objects. 
But what if we want to create a random number of consumable objects between 1 and 10?
Can we do that in the same vein as we have generated random positions of consumable objects?

Let us try. First, have a look at the line of code in 
[main.cpp](course://WarmUp/MovingOn/LimitsOfPossible/src/main.cpp)
that defines the [array](psi_element://main::consumable) of consumable objects.

```c++
const int COUNT = 4;
sf::CircleShape consumable[COUNT];
```

The following line of code generates a random integer value 
in the range from 1 to 10.

```c++
int count = 1 + rand() % 10;
```

Here `%` is the division remainder operator.

Try to replace the `COUNT` constant with the randomly generated number `count`
and then run the program. Once you finish your attempt, read the hint below.

<div class="hint">

You should see that the build of the program fails
with the following (or similar) message:

```
error: variable length array ‘consumable’ is used
```

As you can guess, the problem is due to the definition of an array with the size equal to `count`. 

`COUNT` is a constant, its value is **static**, and it is known
before the program is run, that is, at **compile-time**.
It means that when we define an array of size equal to `COUNT`,
the size of this array can already be calculated and the 
required amount of memory can be allocated. 

Contrary to the above, `count` is a variable and its value is **dynamic** – 
it is not known before the program is run, that is, it is known only at **run-time**.
Thus, the amount of memory needed to be allocated cannot be 
calculated apriori, and the program build fails.

Does all of the above mean that we cannot create an array of dynamic size?
Of course not. However, in order to do so, you first need to learn about 
different kinds of memory regions available to your program and other memory management nuances. 
That is exactly what we are going to study in the next lessons!

</div>
