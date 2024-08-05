We've done all preparation steps for a leaderboard to appear on the screen,
but the last thing is to identify, in which moment we should switch scenes.

`GameEngine::run()` processes the game loop, and we need to use `sceneTransition()` function at the right moment to get from dynamic scene to the leaderboard scene.

Look at `sceneTransition()` and understand how it works. You will need to implement two functions that are used inside of it:
 - `scene->getNextSceneID()`. Since we are now covering only switching from the dynamic scene to the leaderboard scene, this is the instance of the function from GameplayDynamicScene. It should return the ID of the dynamic scene if player has not lost yet, and the ID of the leaderboard otherwise.
 - `sceneManager.transitionScene`. You need to correctly handle the transition between scenes, activating the appropriate scene and passing any necessary data, such as the score, to the new scene.

When you finish, you can run the game, see the score in the top right corner of the screen,
and try to beat the results that our team has achieved!
