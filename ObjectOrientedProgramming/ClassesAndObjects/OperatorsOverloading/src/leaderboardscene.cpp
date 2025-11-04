#include "leaderboardscene.hpp"
#include "constants.hpp"
#include "operators.hpp"

LeaderboardScene::LeaderboardScene() : Scene(SCENE_WIDTH, SCENE_HEIGHT) {
    state = LeaderboardState::INSERT_NAME;
    playerName = "";
    playerScore = 0;
    font = TextureManager::getFont();
}

void LeaderboardScene::activate() {
    return;
}

void LeaderboardScene::deactivate() {
    return;
}

SceneID LeaderboardScene::getID() const {
    return SceneID::LEADERBOARD;
}

SceneID LeaderboardScene::getNextSceneID() const {
    return SceneID::LEADERBOARD;
}

void LeaderboardScene::processText(const sf::Event &event) {
    // TODO: Write your solution here
}

void LeaderboardScene::processBackspace() {
    // TODO: Write your solution here
}

void LeaderboardScene::processEnter() {
    // TODO: Write your solution here
}

void LeaderboardScene::processEvent(const sf::Event &event) {
    if (state == LeaderboardState::INSERT_NAME) {
        if (event.type == sf::Event::TextEntered) {
            processText(event);
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::BackSpace) {
                processBackspace();
            } else if (event.key.code == sf::Keyboard::Enter) {
                processEnter();
            }
        }
    }
}

void LeaderboardScene::update(sf::Time delta) {
    return;
}

void LeaderboardScene::draw(sf::RenderWindow &window, TextureManager &textureManager) {
    window.clear(sf::Color::Black);
    if (state == LeaderboardState::INSERT_NAME) {
        drawInsertNameScreen(window);
    } else if (state == LeaderboardState::SHOW_LEADERBOARD) {
        drawLeaderboard(window);
    }
}

void LeaderboardScene::drawInsertNameScreen(sf::RenderWindow &window) {
    sf::RectangleShape inputBox(sf::Vector2f(INPUTBOX_WIDTH, INPUTBOX_HEIGHT));
    inputBox.setSize(sf::Vector2f(INPUTBOX_WIDTH, INPUTBOX_HEIGHT));
    inputBox.setFillColor(sf::Color::Black);
    inputBox.setOutlineColor(sf::Color::White);
    inputBox.setOutlineThickness(2);
    inputBox.setPosition(SCENE_WIDTH / 2 - inputBox.getSize().x / 2, SCENE_HEIGHT / 2 - inputBox.getSize().y / 2);

    sf::Text prompt;
    prompt.setFont(font);
    prompt.setString("Insert Name");
    prompt.setCharacterSize(INPUTNAME_FONT_SIZE);
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(SCENE_WIDTH / 2 - prompt.getGlobalBounds().width / 2, SCENE_HEIGHT / 2 - inputBox.getSize().y / 2 - 100);

    sf::Text nameText;
    nameText.setFont(font);
    nameText.setString(playerName);
    nameText.setCharacterSize(INPUTNAME_FONT_SIZE);
    nameText.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = nameText.getLocalBounds();
    float textHeight = textBounds.height;
    float textYOffset = textBounds.top;
    float inputBoxCenterY = inputBox.getPosition().y + inputBox.getSize().y / 2;
    nameText.setPosition(SCENE_WIDTH / 2 - textBounds.width / 2, inputBoxCenterY - textHeight / 2 - textYOffset);

    window.draw(inputBox);
    window.draw(prompt);
    window.draw(nameText);
}

void LeaderboardScene::drawLeaderboard(sf::RenderWindow &window) {
    sf::Text header = createText("LEADERBOARD", font, HEADER_FONT_SIZE, HEADER_X, HEADER_Y);
    window.draw(header);

    sf::Text posHeader = createText("POS", font, LEADERBOARD_FONT_SIZE, POS_HEADER_X, POS_HEADER_Y);
    window.draw(posHeader);

    sf::Text nameHeader = createText("NAME", font, LEADERBOARD_FONT_SIZE, NAME_HEADER_X, NAME_HEADER_Y);
    window.draw(nameHeader);

    sf::Text scoreHeader = createText("SCORE", font, LEADERBOARD_FONT_SIZE, SCORE_HEADER_X, SCORE_HEADER_Y);
    window.draw(scoreHeader);

    unsigned int NUMBER_OF_ROWS = leaderboard.getScores().size();
    float LEADERBOARD_HEIGHT = ROW_HEIGHT * (NUMBER_OF_ROWS + 1); // One additional row for the header

    // Draw horizontal lines
    sf::RectangleShape line(sf::Vector2f(LEADERBOARD_WIDTH, 2));
    line.setFillColor(sf::Color::White);
    for (unsigned int i = 0; i <= NUMBER_OF_ROWS + 1; ++i) {
        line.setPosition(LEADERBOARD_X, LEADERBOARD_Y + i * ROW_HEIGHT);
        window.draw(line);
    }

    // Draw vertical lines
    sf::RectangleShape line1(sf::Vector2f(2, LEADERBOARD_HEIGHT));
    line1.setPosition(LEADERBOARD_X, LEADERBOARD_Y);
    window.draw(line1);
    sf::RectangleShape line2(sf::Vector2f(2, LEADERBOARD_HEIGHT));
    line2.setPosition(LEADERBOARD_X + 50, LEADERBOARD_Y);
    window.draw(line2);
    sf::RectangleShape line3(sf::Vector2f(2, LEADERBOARD_HEIGHT));
    line3.setPosition(LEADERBOARD_X + 450, LEADERBOARD_Y);
    window.draw(line3);
    sf::RectangleShape line4(sf::Vector2f(2, LEADERBOARD_HEIGHT));
    line4.setPosition(LEADERBOARD_X + 600, LEADERBOARD_Y);
    window.draw(line4);

    // Draw contents of the leaderboard
    auto scores = leaderboard.getScores();
    for (std::size_t i = 0; i < scores.size(); ++i) {
        auto it = std::next(scores.begin(), i);

        sf::Text pos;
        if (i != 9) {
            pos = createText(std::to_string(i + 1), font, LEADERBOARD_FONT_SIZE, LEADERBOARD_X + TWO_DIGIT_POS_OFFSET, LEADERBOARD_Y + ROW_HEIGHT * (i + 1) + BORDER_OFFSET);
        } else {
            pos = createText(std::to_string(i + 1), font, LEADERBOARD_FONT_SIZE, LEADERBOARD_X + ONE_DIGIT_POS_OFFSET, LEADERBOARD_Y + ROW_HEIGHT * (i + 1) + BORDER_OFFSET);
        }
        window.draw(pos);

        sf::Text name = createText(it->second, font, LEADERBOARD_FONT_SIZE, LEADERBOARD_X + NAME_X_OFFSET, LEADERBOARD_Y + ROW_HEIGHT * (i + 1) + BORDER_OFFSET);
        window.draw(name);

        sf::Text score;
        if (std::to_string(it->first).length() == 1) {
            score = createText(std::to_string(it->first), font, LEADERBOARD_FONT_SIZE, LEADERBOARD_X + ONE_DIGIT_SCORE_OFFSET, LEADERBOARD_Y + ROW_HEIGHT * (i + 1) + BORDER_OFFSET);
        } else if (std::to_string(it->first).length() == 4) {
            score = createText(std::to_string(it->first), font, LEADERBOARD_FONT_SIZE, LEADERBOARD_X + FOUR_DIGIT_SCORE_OFFSET, LEADERBOARD_Y + ROW_HEIGHT * (i + 1) + BORDER_OFFSET);
        } else {
            score = createText(std::to_string(it->first), font, LEADERBOARD_FONT_SIZE, LEADERBOARD_X + FIVE_DIGIT_SCORE_OFFSET, LEADERBOARD_Y + ROW_HEIGHT * (i + 1) + BORDER_OFFSET);
        }
        window.draw(score);
    }
}
