#include <gtest/gtest.h>
#include "testscene.hpp"

TEST(LeaderboardSceneTest, ProcessEventSimple) {
    TestLeaderboardScene scene;
    sf::Event event{};
    event.type = sf::Event::TextEntered;
    event.text.unicode = 'A';
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "A");
}

TEST(LeaderboardSceneTest, ProcessEventBackspace) {
    TestLeaderboardScene scene;
    sf::Event event{};
    event.type = sf::Event::TextEntered;
    event.text.unicode = 'A';
    scene.processEvent(event);
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::BackSpace;
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "");
}

TEST(LeaderboardSceneTest, ProcessEventEnter) {
    TestLeaderboardScene scene;
    sf::Event event{};
    event.type = sf::Event::TextEntered;
    event.text.unicode = 'A';
    scene.processEvent(event);
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::Enter;
    scene.processEvent(event);
    ASSERT_EQ(scene.getState(), LeaderboardState::SHOW_LEADERBOARD);
}

TEST(LeaderboardSceneTest, ProcessEventInvalidCharacter) {
    TestLeaderboardScene scene;
    sf::Event event{};
    event.type = sf::Event::TextEntered;
    event.text.unicode = '!';
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "");
}

TEST(LeaderboardSceneTest, ProcessEventMultipleCharacters) {
    TestLeaderboardScene scene;
    sf::Event event{};
    event.type = sf::Event::TextEntered;
    event.text.unicode = 'A';
    scene.processEvent(event);
    event.text.unicode = 'B';
    scene.processEvent(event);
    event.text.unicode = 'C';
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "ABC");
}

TEST(LeaderboardSceneTest, ProcessEventMultipleCharacterBackspace) {
    TestLeaderboardScene scene;
    sf::Event event{};
    event.type = sf::Event::TextEntered;
    event.text.unicode = 'A';
    scene.processEvent(event);
    event.text.unicode = 'B';
    scene.processEvent(event);
    event.text.unicode = 'C';
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "ABC");
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::BackSpace;
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "AB");
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "A");
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName(), "");
}

TEST(LeaderboardSceneTest, ProcessEventMaxLengthReached) {
    TestLeaderboardScene scene;
    sf::Event event{};
    event.type = sf::Event::TextEntered;
    event.text.unicode = 'A';
    scene.processEvent(event);
    event.text.unicode = 'B';
    scene.processEvent(event);
    event.text.unicode = 'C';
    scene.processEvent(event);
    event.text.unicode = 'D';
    scene.processEvent(event);
    event.text.unicode = 'E';
    scene.processEvent(event);
    event.text.unicode = 'F';
    scene.processEvent(event);
    event.text.unicode = 'G';
    scene.processEvent(event);
    event.text.unicode = 'H';
    scene.processEvent(event);
    event.text.unicode = 'I';
    scene.processEvent(event);
    event.text.unicode = 'J';
    scene.processEvent(event);
    event.text.unicode = 'K';
    scene.processEvent(event);
    event.text.unicode = 'L';
    scene.processEvent(event);
    event.text.unicode = 'M';
    scene.processEvent(event);
    event.text.unicode = 'N';
    scene.processEvent(event);
    event.text.unicode = 'O';
    scene.processEvent(event);
    event.text.unicode = 'P';
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName() == "ABCDEFGHIJKLMNOP", true);
    event.text.unicode = 'Q';
    scene.processEvent(event);
    ASSERT_EQ(scene.getPlayerName() == "ABCDEFGHIJKLMNOP", true);
}