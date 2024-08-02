#include "../include/leaderboard.hpp"
#include "../include/constants.hpp"

void Leaderboard::loadScores() {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Unable to open file: " << this->filepath << std::endl;
        return;
    }
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        unsigned int score;
        getline(ss, name, ',');
        ss >> score;
        this->scores.insert({score, name});
    }
    file.close();
}

void Leaderboard::addScore(unsigned int score, std::string & name) {
    scores.insert({score, name});
    if (scores.size() > MAX_LINES) {
        scores.erase(std::prev(scores.end()));
    }
}

void Leaderboard::saveScores() {
    std::ofstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Unable to open file: " << this->filepath << std::endl;
        return;
    }
    for (const auto &[score, name]: scores) {
        file << name << "," << score << std::endl;
    }
    file.close();
}

void Leaderboard::updateScore(unsigned int score, std::string & name) {
    loadScores();
    addScore(score, name);
    saveScores();
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
