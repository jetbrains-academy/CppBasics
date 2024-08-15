First, we need to implement score counting in the game. The player should earn points for collecting stars, and the score should be visible on the screen throughout the game.

We already have an `onCollision` function that is called whenever a collision is detected. It currently handles collisions with consumable objects, but at the moment, it has no effect.
We can extend this function to increase the score whenever the player collides with a star.

We've added a new field, `score`, to the `Player` class, which will store the player's current score. Additionally, we've introduced a new method, `getScore`, that returns the player's current score.

Your task is to extend the `onCollision` function in the `player.cpp` file and add the necessary behavior.
We suggest awarding 1000 points for each consumed star, as it is both a fair reward and visually appealing.
You will also need to implement the `updateScore` function in `dynscene.cpp`. You can access the `player` field from the `GameplayDynamicScene` class to retrieve the player object and store its score in the `score` field.
