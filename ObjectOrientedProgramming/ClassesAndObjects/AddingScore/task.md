At first, we need to implement score counting in the game. The player should earn points for collecting stars, and it should be visible on the screen throughout the game.

We already have an `onCollision` function that is called whenever a collision is detected. It already handles the collision with consumable objects, but right now there is no effect from it.
We can extend it to increase the score whenever a player collides with a star.

We've added new field `score` to the `Player` class. It will store the current score of the player. We've also added a new method `getScore` that returns the current score of the player.

Your task is to extend `onCollision` function from the `player.cpp` file and add a new behavior to it.
We think that adding 1000 points for each consumed star is a fair reward, plus it's just looks great!
Also, you need to implement `updateScore` function in `dynscene.cpp`. This function should find the player object and save its score to the `score` field of the `GameplayDynamicScene` class.
