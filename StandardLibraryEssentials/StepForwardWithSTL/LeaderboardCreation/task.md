We've done all steps for a leaderboard to appear on the screen,
but the last one is to create a way to identify, when the game should end.
When enemy reaches our planet, the game should end and the leaderboard should appear on the screen.
You can explore new look of a `GameEngine::run()` function,
which will now check the player's state and end the execution of `while` loop when the player is dead.
```cpp
void GameEngine::run() {
    sf::Clock clock;
    bool isPlayerAlive = true;
    while (isActive() && isPlayerAlive) {
        sf::Time delta = clock.restart();
        processInput();
        update(delta);
        isPlayerAlive = scene->isPlayerAlive();
        render();
        sceneTransition();
    }
    sleep(1);
    leaderboard.updateScore(scene->getScore());
    while (isActive()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                close();
            }
        }
        window.clear();
        Leaderboard::drawLeaderboard(window, textureManager, leaderboard.getScores());
        window.display();
    }
}
```

To make `isPlayerAlive` work, you need to write an `updatePlayerStatus()` function in the `GameplayDynamicScene` class.
This function should check if the player `GameObjectStatus` property has changed to `GameObjectStatus::DESTROYED`,
and if so – call `updatePlayerStatus()` of a parent class.

When you finish, you can run the game, see the score in the top right corner of the screen,
and try to beat the results that our team has achieved!
