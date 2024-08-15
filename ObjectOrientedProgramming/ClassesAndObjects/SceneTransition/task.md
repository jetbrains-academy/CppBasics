We've completed all the preparatory steps for displaying the leaderboard,
but the final task is to identify the correct moment to switch scenes.

The `GameEngine::run()` function processes the game loop, and we need to use the `sceneTransition()` function at the right moment to transition from the dynamic scene to the leaderboard scene.

Take a look at `sceneTransition()` to understand how it works. You will need to implement two functions that are used within it:
 - `scene->getNextSceneID()`: Since we are currently focusing on switching from the dynamic scene to the leaderboard scene, this function in `GameplayDynamicScene` should return the ID of the dynamic scene if the player has not lost yet, and the ID of the leaderboard scene otherwise.
 - `sceneManager.transitionScene`: You need to correctly handle the scene transition, ensuring the appropriate scene is activated and passing any necessary data, such as the score, to the new scene.

Also, ensure that in the `scenes.cpp` file, both the `initialize()` and `getCurrentScene()` functions are working with the `dynamicScene` instance (and not the `staticScene`, which can sometimes happen due to incorrect code transfers). This ensures the game can be played properly. 

Once you've finished, you can run the game, see the score displayed in the top-right corner of the screen,
and try to beat the results that our team has achieved!
