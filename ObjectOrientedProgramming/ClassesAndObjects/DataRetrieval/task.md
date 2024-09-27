At this point, we need to understand how we can store game results,
so that your achievements won't disappear after the program is closed.
The obvious solution is to save the data to a file.
We will use a [`.csv`](https://en.wikipedia.org/wiki/Comma-separated_values) file format,
which is a simple text format for storing tabular data.
Each line of the file represents a row of the table, and the values in the row are separated by commas.

For working with leaderboard data, we will use a `Leaderboard` class, defined in `leaderboard.hpp`.

Let's talk about leaderboard structure in general.
It should be a table, where each result is a pair of player's names and scores.
The table should be sorted by score in descending order.
But we also want to allow players to have different records under their name, so we need to store all of them.
For this scenario, we will use a `std::multimap` container,
where the key is the score and the value is the player's name.
This container will allow us to store multiple records with the same score.

`updateScore` method should be called from `LeaderboardScene::processEvent`, updating the leaderboard with the player's score and name that was inputted. This function will call three other functions:
- `loadScores()` - reads the leaderboard data from the file and saves it to the `scores` field.
- `addScore()` - adds new player's score to the `scores`.
- `saveScores()` - saves the updated leaderboard data to the file.

`loadScores()` should open the file by the `filepath` path and open it using `std::ifstream`. If the attempt to open the file fails, the function should write an error message to standard output "Unable to open file: (filepath)".
Otherwise, the function should read the data from the file and save it to the `scores` field.

`addScore()` should add a new player's score to the `scores` field.
Since our screen is limited in size, we will store only the top 10 scores for each player. Therefore, if after adding a new score the number of records for the player exceeds 10, the function should remove the record with the lowest score.

`saveScores()` should open the file by the `filepath` path and open it using `std::ofstream`. If the attempt to open the file fails, the function should also write an error message (same as the previous one). Remember the file format we are using!