When the player collides with an enemy, the game should end, and a new scene should appear. In this scene, the player will be able to enter their name and view the leaderboard. Name should be entered using the keyboard, allowing only English letters and numbers. The maximum length of the nickname is 16 characters.   

The `LeaderboardScene` class has two states: `INSERTNAME` and `SHOWLEADERBOARD`. When the game ends, the state is automatically set to `INSERTNAME`. Once the player enters their name, the state should change to `SHOWLEADERBOARD`.
This logic is processed in the `processEvent` function. All input will be handled during the `INSERTNAME` state. You should manage three cases:
 - If text is entered (`event.type == sf::Event::TextEntered`), check the character to ensure it complies with our rules. If valid, add it to the name, provided the name's length is less than 16 characters.
 - If the backspace key is pressed (`event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace`), remove the last character from the name.
 - If the enter key is pressed (`event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter`), change the state to `SHOWLEADERBOARD` and call the `updateScore(score, name)` function from the `Leaderboard` class. We will implement this in the next task.

The `processEvent` function has already been implemented for you, and it calls the `processText`, `processBackspace`, and `processEnter` functions. You need to implement these functions.
