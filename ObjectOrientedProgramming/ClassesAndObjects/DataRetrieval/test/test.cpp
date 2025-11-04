#include <gtest/gtest.h>
#include <fstream>
#include "testscene.hpp"

class LeaderboardTest : public ::testing::Test {
protected:
    TestLeaderboard leaderboard;
    std::string originalFileContent;

    void SetUp() override {
        // Read the original content of the file
        std::ifstream file(leaderboard.testFilepath);
        originalFileContent = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
    }

    void TearDown() override {
        // Restore the original content of the file
        std::ofstream file(leaderboard.testFilepath);
        file << originalFileContent;
        file.close();
    }
};

TEST_F(LeaderboardTest, RetrieveScores) {
    TestLeaderboard leaderboard;

    leaderboard.loadScores();
    auto scores = leaderboard.getScores();
    ASSERT_EQ(scores.size(), 2);
    ASSERT_EQ(scores.begin()->first, 200); // Expect the highest score first
    ASSERT_EQ(scores.begin()->second, "Alice");
    ASSERT_EQ(scores.rbegin()->first, 100); // Expect the lowest score last
    ASSERT_EQ(scores.rbegin()->second, "Bob");
}

TEST_F(LeaderboardTest, AddScore) {
    TestLeaderboard leaderboard;

    auto scores = leaderboard.getScores();
    scores.insert({300, "Charlie"});
    leaderboard.addScore(300, "Charlie");
    ASSERT_EQ(scores.size(), leaderboard.getScores().size());
    ASSERT_EQ(scores.begin()->first, leaderboard.getScores().begin()->first);
    ASSERT_EQ(scores.begin()->second, leaderboard.getScores().begin()->second);
}

TEST_F(LeaderboardTest, SaveScoresLast) {
    TestLeaderboard leaderboard;
    leaderboard.loadScores();
    leaderboard.addScore(50, "Charlie");
    leaderboard.saveScores();

    std::ifstream file(leaderboard.testFilepath);
    std::string line;
    std::getline(file, line); // Skip first line
    std::getline(file, line); // Skip second line
    std::getline(file, line); // Get third line
    ASSERT_EQ(line, "Charlie,50");
    file.close();
}

TEST_F(LeaderboardTest, SaveScoresFirst) {
    TestLeaderboard leaderboard;
    leaderboard.addScore(500, "Tester");
    leaderboard.saveScores();

    std::ifstream file(leaderboard.testFilepath);
    std::string line;
    std::getline(file, line);
    ASSERT_EQ(line, "Tester,500");
    file.close();
}

TEST_F(LeaderboardTest, SaveScoresMultiple) {
    TestLeaderboard leaderboard;
    leaderboard.loadScores();
    leaderboard.addScore(500, "Tester");
    leaderboard.addScore(150, "Charlie");
    leaderboard.addScore(50, "Dave");
    leaderboard.saveScores();

    std::ifstream file(leaderboard.testFilepath);
    std::string line;
    std::getline(file, line);
    ASSERT_EQ(line, "Tester,500");
    std::getline(file, line);
    ASSERT_EQ(line, "Alice,200");
    std::getline(file, line);
    ASSERT_EQ(line, "Charlie,150");
    std::getline(file, line);
    ASSERT_EQ(line, "Bob,100");
    std::getline(file, line);
    ASSERT_EQ(line, "Dave,50");
    file.close();
}

TEST_F(LeaderboardTest, UpdateScore) {
    TestLeaderboard leaderboard;
    leaderboard.performUpdateScore(500);

    auto scores = leaderboard.getScores();
    ASSERT_EQ(scores.size(), 3);
    ASSERT_EQ(scores.begin()->first, 500);
    ASSERT_EQ(scores.begin()->second, "Tester");

    std::ifstream file(leaderboard.testFilepath);
    std::string line;
    std::getline(file, line);
    ASSERT_EQ(line, "Tester,500");
    std::getline(file, line);
    ASSERT_EQ(line, "Alice,200");
    std::getline(file, line);
    ASSERT_EQ(line, "Bob,100");
    file.close();
}