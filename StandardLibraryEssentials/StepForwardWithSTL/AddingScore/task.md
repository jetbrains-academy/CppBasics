Now we can rewrite the `update` function in `dynscene.cpp` to use the `findNext` function
and avoid double collision detection,
preparing it for further score counting.

But how do we count the score?
Well, we already have an `onCollision` function that is called whenever a collision is detected.
We can extend it to increase the score whenever a player collides with a consumable object on the screen.

So go to the `player.cpp` file and add a new behavior to the `onCollision` function.
We think that adding 1000 points for each consumed star is a fair reward (plus it's just looks great!).

After that,
get back to the `update` function in `dynscene.cpp` and add a call to the `onCollision` function inside `while` loop,
that uses the `findNext` function.
This way, the score will be updated exactly one time when a collision is detected.