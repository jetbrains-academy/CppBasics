#ifndef CPPBASICS_ENGINE_HPP
#define CPPBASICS_ENGINE_HPP

#include <SFML/Graphics.hpp>

#include "scenes.hpp"
#include "textures.hpp"

class GameEngine {
public:

    /**
     * Returns the game engine instance.
     *
     * @return A pointer to the game engine instance.
     *
     * @note This function does not transfer ownership of the game engine to the caller.
     *  The lifetime of the game engine is the entire duration of the program, and thus there is no need
     *  to manually delete the returned pointer.
     */
    static GameEngine* create();

    /**
     * The run function implements the main loop of the game.
     *
     * While game is active, on each iteration of the loop, it processes any possible input,
     * updates the scene according to the delta time, renders the scene,
     * and, finally, performs a transition to a new scene if required.
     */
    void run();

    /**
     * Checks if the game engine is active and the application window is open.
     *
     * @return true if engine is active, false otherwise.
     */
    bool isActive() const;

    /**
     * Closes the game engine, forcing it to exit its running loop and close the application window.
     */
    void close();

private:

    /**
     * Constructs the game engine.
     */
    GameEngine();

    /**
     * Processes all the input events accumulated in the event queue by passing them
     * to the GameEngine::processEvent method.
     */
    void processInput();

    /**
     * Processes single input event.
     *
     * Window-related events, such as user resizing or closing a window, are processed by
     * the engine itself, while all other kinds of events are delegated to the scene.
     *
     * @param event the processing event.
     */
    void processEvent(const sf::Event& event);

    /**
     * Updates the state of the current scene.
     *
     * @param delta The time elapsed since the last update.
     */
    void update(sf::Time delta);

    /**
     * Renders the current scene on the window.
     */
    void render();

    /**
     * Performs a scene transition in the game.
     */
    void sceneTransition();

    /**
     * Resizes the game window to fit the current scene into it.
     */
    void resizeWindow();

    sf::RenderWindow window;
    SceneManager sceneManager;
    TextureManager textureManager;
    Scene* scene;
    bool active;
};

#endif //CPPBASICS_ENGINE_HPP
