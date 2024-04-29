#ifndef PLANETGAME_LEADERBOARD_HPP
#define PLANETGAME_LEADERBOARD_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "textures.hpp"

/**
 * Leaderboard class that manages the scores of the player and displays them on the window.
 */
class Leaderboard {
public:
    using ScoreMap = std::multimap<unsigned int, std::string, std::greater<>>;

    /**
     * Constructs the leaderboard.
     */
    Leaderboard() = default;

    /**
     * Gets scores with corresponding player names from file.
     */
    void retrieveScores();

    /**
     * Adds a new score to the leaderboard.
     *
     * @param score the score to add
     * @param name the name of the player
     */
    void addScore(unsigned int score, std::string name = "Student");

    /**
     * Writes scores back to file.
     */
    void saveScores();

    /**
     * Returns the scores.
     *
     * @return the scores
     */
    [[nodiscard]] ScoreMap getScores() const {
        return scores;
    }

    /**
     * Calls three functions: retrieveScores, addScore, and saveScores.
     *
     * @param score the score to update
     */
    void updateScore(unsigned int score);

    /**
     * Draws the leaderboard on the window.
     *
     * @param window the window to draw the leaderboard on
     * @param textureManager the texture manager
     * @param scores the scores to draw
     */
    static void drawLeaderboard(sf::RenderWindow& window, const TextureManager& textureManager, ScoreMap scores);

private:
    std::string filepath = "../../../../resources/leaderboard.csv";
    ScoreMap scores;
};

sf::Text createText(const std::string &str, const sf::Font &font, unsigned int size, float x, float y);

#endif //PLANETGAME_LEADERBOARD_HPP
