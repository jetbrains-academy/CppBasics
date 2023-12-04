#ifndef CPPBASICS_SCENES_HPP
#define CPPBASICS_SCENES_HPP

#include "scene.hpp"
#include "statscene.hpp"
#include "dynscene.hpp"

/**
 * The SceneManager class is responsible for loading and managing the different scenes in a game.
 */
class SceneManager {
public:

    /**
     * Initializes the scene manager.
     *
     * @return true if the initialization was successful, false otherwise.
     */
    bool initialize();

    /**
     * Retrieves the current scene of the game.
     *
     * @return The pointer to the current scene.
     *
     * @note This method does not transfer ownership of the scene to the caller.
     *  The lifetime of the scenes is managed by the scene manager itself.
     */
    Scene* getCurrentScene();

    /**
     * This function checks if the transition to a new scene is necessary by querying the current scene
     * and performs this transition if required.
     */
    void transitionScene(SceneID id);

private:
    GameplayStaticScene staticScene;
};


#endif //CPPBASICS_SCENES_HPP
