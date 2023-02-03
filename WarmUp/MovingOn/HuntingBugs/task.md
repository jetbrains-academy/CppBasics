Before we move on, there is another important topic 
we need to mention – program debugging.

Everybody makes mistakes. Including programmers.
Mistakes in programs are also known as _bugs_. 

Sometimes finding bugs in the code can be hard.
To make this process easier, programmers have 
invented various tools that help them find bugs in programs. 
One of such tools is the __debugger__.

The debugger allows you to step through your program –
execute it step by step and inspect the state of the variables
during the execution. 
You can learn how to use the debugger in the Clion IDE
by consulting the corresponding 
[tutorial](https://www.jetbrains.com/help/clion/debugging-code.html). 

In order for you to try the debugging experience in the IDE,
we prepared this task. We have implemented a new functionality 
in our game but deliberately put several bugs into its implementation.
Your job is to try to spot them using the debugger.
Please find the description of the intended behavior of the new functionality below.

We have added yet another function:

```c++
void approachingLoop(Circle player, Circle consumable[], bool concerned[], int size);
```

It is similar to `collisionLoop` function, but instead of detecting 
collisions, it detects a situation when a player object approaches consumable objects.
When this happens, it sets the corresponding flag in the `concerned` boolean array.
The flags in the array are later used in the `render` function (see `main.cpp`)
to change the image of the consumable star object to its "concerned" variant.
Whenever the player object moves away from the consumable star object, 
its image should return to normal. 

However, because of the bugs in the `approachingLoop` function,
none of this works properly. You should spot these bugs 
and restore the intended behavior!