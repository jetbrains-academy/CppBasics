#include "leaderboard.hpp"

void Leaderboard::retrieveScores() {
    // TODO: write your solution here
}

void Leaderboard::addScore(unsigned int score, std::string name) {
    // TODO: write your solution here
}

void Leaderboard::saveScores() {
    // TODO: write your solution here
}

void Leaderboard::updateScore(unsigned int score) {
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

void Leaderboard::drawLeaderboard(sf::RenderWindow &window, const TextureManager &textureManager, ScoreMap scores) {
    // show leaderboard frame
    sf::Sprite frame;
    frame.setTexture(*textureManager.getTexture(GameTextureID::LEADERBOARD));
    frame.setPosition(100, 75);
    window.draw(frame);

    sf::Font font;
    font.loadFromFile("resources/pixelLetters.ttf");

    sf::Text header = createText("LEADERBOARD", font, 40, 300, 80);
    window.draw(header);

    sf::Text posHeader = createText("POS", font, 26, 157, 162);
    window.draw(posHeader);

    sf::Text nameHeader = createText("NAME", font, 26, 357, 162);
    window.draw(nameHeader); // draw the name header

    sf::Text scoreHeader = createText("SCORE", font, 26, 567, 162);
    window.draw(scoreHeader); // draw the score header

    for (std::size_t i = 0; i < static_cast<int>(scores.size()); ++i) {
        sf::Text pos;
        pos.setFont(font);
        pos.setCharacterSize(26);
        pos.setFillColor(sf::Color::White);
        pos.setString(std::to_string(i + 1));
        if (i < 9) {
            pos.setPosition(172, 162 + 30 * (i + 1));
        } else {
            pos.setPosition(167, 162 + 30 * (i + 1));
        }
        window.draw(pos); // draw the position

        auto it = std::next(scores.begin(), i);
        sf::Text name;
        name.setFont(font);
        name.setCharacterSize(26);
        name.setFillColor(sf::Color::White);
        name.setString(it->second);
        name.setPosition(212, 162 + 30 * (i + 1));
        window.draw(name); // draw the name

        sf::Text score;
        score.setFont(font);
        score.setCharacterSize(26);
        score.setFillColor(sf::Color::White);
        score.setString(std::to_string(it->first));
        if (it->first == 0) {
            score.setPosition(595, 162 + 30 * (i + 1));
        } else if (it->first < 10000) {
            score.setPosition(578, 162 + 30 * (i + 1));
        } else {
            score.setPosition(577, 162 + 30 * (i + 1));
        }
        window.draw(score); // draw the score
    }
}
