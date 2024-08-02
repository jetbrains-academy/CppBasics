#ifndef CPPBASICS_SCENE_HPP
#define CPPBASICS_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "gobject.hpp"
#include "textures.hpp"

/**
 * The Scene class provides functionalities for rendering game scenes.
 */
class Scene {
public:

    /**
     * Constructs the scene.
     */
    Scene(float width, float height);

    /**
     * Destructs the scene.
     */
    virtual ~Scene() = default;

    /**
     * Activates the scene.
     *
     * Scene is activated by the game engine when it sets it as a the current scene.
     * Activation should initialize the state of the scene, including all the game objects belonging to it.
     *
     * @note This method must be implemented in any derived scene class.
     */
    virtual void activate() = 0;

    /**
     * Deactivates the scene.
     *
     * Scene is deactivated by the game engine when it performs a transition to another scene.
     * Deactivation should reset the state of the scene.
     *
     * @note This method must be implemented in any derived scene class.
     */
    virtual void deactivate() = 0;

    /**
     * Returns the ID of the scene.
     */
    virtual SceneID getID() const = 0;

    /**
     * Returns the ID of the next scene to transition into.
     */
    virtual SceneID getNextSceneID() const = 0;

    /**
     * Processes scene-related input event, such as player pressing some button, etc.
     *
     * @param event the processing event.
     *
     * @note This method must be implemented in any derived scene class.
     */
    virtual void processEvent(const sf::Event& event) = 0;

    /**
     * Updates the scene state based on time elapsed since the last update.
     *
     * @param delta The time elapsed since the last update.
     *
     * @note This method must be implemented in any derived scene class.
     */
    virtual void update(sf::Time delta) = 0;

    /**
     * Draws all the game objects belonging to the scene on the window.
     *
     * @param window the window to draw on.
     * @param textureManager the texture manager.
     *
     * @note This method must be implemented in any derived scene class.
     */
    virtual void draw(sf::RenderWindow &window, TextureManager& textureManager) = 0;

    /**
     * Returns the bounding box of the scene.
     * The bounding box defines the smallest rectangle that completely encloses the scene.
     *
     * @return The bounding box of the scene as a rectangle.
     */
    Rectangle getBoundingBox() const;

protected:

    /**
     * Set the position of a game object.
     * Ensures that the object fits within the bounds of the scene.
     *
     * @param object the game object which position to be set.
     * @param position the new position of the object.
     */
    void setObjectPosition(GameObject& object, Point2D position);

    /**
     * Moves a game object on the scene by the given vector.
     * Ensures that the object fits within the bounds of the scene.
     *
     * @param object The game object to be moved.
     * @param vector The vector specifying the movement.
     */
    void move(GameObject& object, Point2D vector);

    /**
     * Moves a game object on the scene based on a given time delta and object's velocity.
     *
     * @param object The game object to be moved.
     * @param delta The time delta.
     */
    void move(GameObject& object, sf::Time delta);

    /**
     * @brief Fits the game object into the bound of the scene.
     * The fitting operation may involve adjusting object's position.
     *
     * @param object the object to be fit into the scene.
     */
    void fitInto(GameObject& object);

    /**
     * Checks for potential collision between two game objects and notifies the objects about the result of the check
     * by calling their GameObject::onCollision methods and provided with the CollisionInfo structure.
     *
     * @param object1 The first game object to check for collision.
     * @param object2 The second game object to check for collision.
     */
    void detectCollision(GameObject& object1, GameObject& object2);

    /**
     * Draws the background, filling it with the provided texture.
     *
     * @param window the window to draw on.
     * @param texture the background texture.
     */
    void drawBackground(sf::RenderWindow &window, const sf::Texture* texture) const;

private:
    float width;
    float height;
};

#endif // CPPBASICS_SCENE_HPP
