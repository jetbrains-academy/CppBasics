#ifndef CPPBASICS_DYNSCENE_HPP
#define CPPBASICS_DYNSCENE_HPP

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
    std::shared_ptr<PlayerObject> player;

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
        * Updates the score of the player.
        */
    void updateScore();

private:
    /**
     * Draws score on the window.
     *
     * @param window the window to draw on.
     * @param value the score value to draw.
     */
    void drawScore(sf::RenderWindow &window, unsigned int value) const;

    unsigned int score = 0;
};

#endif // CPPBASICS_DYNSCENE_HPP
