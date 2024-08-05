#include "leaderboard.hpp"
#include "constants.hpp"

void Leaderboard::loadScores() {
    // TODO: write your solution here
}

void Leaderboard::addScore(unsigned int score, std::string & name) {
    // TODO: write your solution here
}

void Leaderboard::saveScores() {
    // TODO: write your solution here
}

void Leaderboard::updateScore(unsigned int score, std::string & name) {
    // TODO: write your solution here
}

sf::Text createText(const std::string &str, const sf::Font &font, const unsigned int size, const float x, const float y) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setString(str);
    text.setPosition(x, y);
    return text;
}
