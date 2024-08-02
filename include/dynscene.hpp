#ifndef CPPBASICS_DYNSCENE_HPP
#define CPPBASICS_DYNSCENE_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "gobjectlist.hpp"
#include "player.hpp"

/**
 * DynamicScene is a scene capable of managing and updating the list of game objects in the scene:
 * objects might be added to or removed from the scene dynamically.
 */
class GameplayDynamicScene : public Scene {
public:

    /**
     * Constructs the scene.
     */
    GameplayDynamicScene();

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
     * Process the given event.
     */
    void processEvent(const sf::Event &event) override;

    /**
     * Updates the object's state based on the elapsed time since the last update.
     */
    void update(sf::Time delta) override;

    /**
     * Draws the scene with all its game objects.
     */
    void draw(sf::RenderWindow &window, TextureManager& textureManager) override;

    /**
     * Returns the score of the player.
     *
     * @return The score of the player.
     */
    unsigned int getScore() const;



protected:
    GameObjectList objects;

    /**
     * Update the list of objects present on the scene. In particular:
     *   - removes all destroyed objects;
     *   - creates new objects if there is enough room for them.
     */
    void updateObjectsList();

    /**
     * Adds to the scene new object of the given kind.
     */
    std::shared_ptr<GameObject> addNewGameObject(GameObjectKind kind);

    /**
     * Returns the status (alive/dead) of the player.
     *
     * @return true if player is alive, false otherwise.
     */
    bool isPlayerAlive() const;

private:
    /**
     * Draws score on the window.
     *
     * @param window the window to draw on.
     * @param value the score value to draw.
     */
    void drawScore(sf::RenderWindow &window, unsigned int value) const;

    /**
     * Updates the score of the player.
     */
    void updateScore();

    /**
     * Updates the status of the player.
     */
    void updatePlayerStatus();

    /**
     * Updates the score of the player.
     *
     * @param value the new score value.
     *
     * @note this method should be called by the updateScore() of derived class.
     */
    void updateScore(unsigned int value);

    unsigned int score = 0;
    bool playerAlive = true;
};

#endif // CPPBASICS_DYNSCENE_HPP
