At this point, we need to figure out how to store game results
so that your achievements don't disappear when the program is closed.
The obvious solution is to save the data to a file.
We will use the [`.csv`](https://en.wikipedia.org/wiki/Comma-separated_values) file format,
a simple text format for storing tabular data.
Each line in the file represents a row in the table, with the values in each row separated by commas.

To work with the leaderboard data, we will use a `Leaderboard` class, defined in `leaderboard.hpp`.

Now, let's discuss the general structure of the leaderboard.
It should be a table where each result is a pair consisting of the player's name and score.
The table should be sorted by score in descending order.
However, we also want to allow players to have multiple records under the same name, so we need to store all of them.
For this, we will use a `std::multimap` container,
where the key is the score and the value is the player's name.
This container will allow us to store multiple records with the same score.

The `updateScore` method should be called from `LeaderboardScene::processEvent` to update the leaderboard with the player's score and the name they input. This function will call three other functions:
- `loadScores()` - reads the leaderboard data from the file and saves it to the `scores` field.
- `addScore()` - adds the player's new score to `scores`.
- `saveScores()` - saves the updated leaderboard data back to the file.

`loadScores()` should open the file at the path specified by `filepath` using `std::ifstream`. If the attempt to open the file fails, the function should output an error message to the standard output: "Unable to open file: (filepath)".
Otherwise, the function should read the data from the file and store it in the `scores` field.

`addScore()` should add the player's new score to the `scores` field.
Since our screen is limited in size, we will only store the top 10 scores for each player. Therefore, if adding a new score causes the number of records for that player to exceed 10, the function should remove the record with the lowest score.

`saveScores()` should open the file at the path specified by `filepath` using `std::ofstream`. If the file fails to open, the function should output the same error message as before. Be sure to remember the file format we are using!
