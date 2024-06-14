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

// TEST_F(LeaderboardTest, RetrieveScores) {
//     TestLeaderboard leaderboard;
//
//     leaderboard.retrieveScores();
//     auto scores = leaderboard.getScores();
//     ASSERT_EQ(scores.size(), 2);
//     ASSERT_EQ(scores.begin()->first, 100);
//     ASSERT_EQ(scores.begin()->second, "Alice");
//     ASSERT_EQ(scores.rbegin()->first, 200);
//     ASSERT_EQ(scores.rbegin()->second, "Bob");
// }
//
// TEST_F(LeaderboardTest, AddScore) {
//     TestLeaderboard leaderboard;
//
//     auto scores = leaderboard.getScores();
//     leaderboard.addScore(300, "Charlie");
//     ASSERT_EQ(scores.size(), 3);
//     ASSERT_EQ(scores.begin()->first, 300);
//     ASSERT_EQ(scores.begin()->second, "Charlie");
//
//     leaderboard.getScores().erase(scores.begin());
//     leaderboard.saveScores();
// }
//
// TEST_F(LeaderboardTest, SaveScores) {
//     TestLeaderboard leaderboard;
//     leaderboard.addScore(400, "Dave");
//     leaderboard.saveScores();
//
//     std::ifstream file(leaderboard.testFilepath);
//     std::string line;
//     std::getline(file, line); // Skip first line
//     std::getline(file, line); // Skip second line
//     std::getline(file, line); // Get third line
//     ASSERT_EQ(line, "Dave,400");
//     file.close();
//
//     leaderboard.getScores().erase(std::prev(leaderboard.getScores().end()));
//     leaderboard.saveScores();
// }
//
// TEST_F(LeaderboardTest, UpdateScore) {
//     TestLeaderboard leaderboard;
//     leaderboard.performUpdateScore(500);
//
//     auto scores = leaderboard.getScores();
//     ASSERT_EQ(scores.size(), 3);
//     ASSERT_EQ(scores.begin()->first, 500);
//
//     std::ifstream file(leaderboard.testFilepath);
//     std::string line;
//     std::getline(file, line); // Skip first line
//     std::getline(file, line); // Skip second line
//     std::getline(file, line); // Get third line
//     ASSERT_EQ(line, "Tester,500");
//     file.close();
//
//     leaderboard.getScores().erase(scores.begin());
//     leaderboard.saveScores();
// }