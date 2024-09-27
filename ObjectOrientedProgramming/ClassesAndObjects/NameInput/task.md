When player collides with an enemy, the game should end and new scene should appear. On this scene you will be able to enter your name and see the leaderboard. Name should be entered using keyboard, it allows only english letters and numbers. Maximum length of the nickname is 16 characters.   

LeaderboardScene class has two states: `INSERTNAME` and `SHOWLEADERBOARD`. When the game ends, the state automatically sets to `INSERTNAME`. When the player enters the name, the state should change to `SHOWLEADERBOARD`.
This logic would be processed in `processEvent` function. All input you'll need to process would be during `INSERTNAME` state. You should handle three cases:
 - If text is entered (`event.type == sf::Event::TextEntered`), you should check this character for being valid for our rules, and add it to the name if it's length is less than 16 characters.
 - If backspace is pressed (`event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace`), you should remove the last character from the name.
 - If enter is pressed (`event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter`), you should change the state to `SHOWLEADERBOARD`, and call `updateScore(score, name)` function from the `Leaderboard` class. We will implement it in the next task.

`processEvent` function is already implemented for you, and it calls `processText`, `processBackspace` and `processEnter` functions. You should implement these functions.