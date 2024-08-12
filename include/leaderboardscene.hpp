#ifndef LEADERBOARDSCENE_HPP
#define LEADERBOARDSCENE_HPP

#include "leaderboard.hpp"
#include "scene.hpp"

#include <string>

enum class LeaderboardState {
    INSERT_NAME,
    SHOW_LEADERBOARD
};

class LeaderboardScene : public Scene {
public:
    /**
     * Constructs the scene.
     */
    LeaderboardScene();

    /**
     * Activates the scene.
     */
    void activate() override;

    /**
     * Deactivates the scene.
     */
    void deactivate() override;

    /**
     * Returns the ID of the scene.
     */
    SceneID getID() const override;

    /**
     * Returns the ID of the next scene to transition into.
     */
    SceneID getNextSceneID() const override;


    /**
     * Processes the text input event.
     * This function is called inside @processEvent.
     */
    void processText(const sf::Event& event);

    /**
     * Processes the backspace event.
     * This function is called inside @processEvent.
     */
    void processBackspace();

    /**
     * Processes the enter event.
     * This function is called inside @processEvent.
     */
    void processEnter();

    /**
     * Processes scene-related input event.
     */
    void processEvent(const sf::Event& event) override;

    /**
     * Updates the scene.
     */
    void update(sf::Time delta) override;

    /**
     * Draws the scene on the window.
     * Calls either @drawLeaderboard or @drawInsertNameScreen, depending on the @LeaderboardState.
     */
    void draw(sf::RenderWindow &window, TextureManager& textureManager) override;

    /**
     * Draws the leaderboard on the window.
     */
    void drawLeaderboard(sf::RenderWindow& window);

    /**
     * Draws the screen for inserting the player's name.
     */
    void drawInsertNameScreen(sf::RenderWindow& window);

    /**
     * Acquires the player's score from @GameplayDynamicScene.
     *
     * @param score – player's score to transfer to the leaderboard.
     */
    void recieveScore(unsigned int score) { playerScore = score; }

protected:
    std::string playerName;
    unsigned int playerScore;
    LeaderboardState state;

private:
    Leaderboard leaderboard;
    sf::Font font;
};

#endif //LEADERBOARDSCENE_HPP
