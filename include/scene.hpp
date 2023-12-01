#ifndef CPPBASICS_SCENE_HPP
#define CPPBASICS_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "gobject.hpp"
#include "textures.hpp"

/**
 * The Scene class provides functionalities for managing and rendering game scenes.
 */
class Scene {
public:

    /**
     * Constructs the scene.
     */
    Scene();

    /**
     * Destructs the scene.
     */
    virtual ~Scene() = default;

    /**
     * The run function implements the scene management logic.
     * It initializes the scene, and while scene is active, it continues to run the main loop of the scene.
     * In each iteration of the loop, it processes any possible input,
     * updates the scene according to the delta time, and finally renders the scene.
     */
    void run();

    /**
     * Creates a new scene.
     *
     * @return A pointer to the newly created scene.
     *
     * @note This function does not transfer ownership of the scene to the caller.
     *  The lifetime of the scene is the entire duration of the program, and thus there is no need
     *  to manually delete the returned pointer.
     */
    static Scene* create();

protected:

    /**
     * Initializes the scene.
     *
     * @note This function must be implemented in any derived scene class.
     */
    virtual void initialize() = 0;

    /**
     * Closes the scene, forcing it to exit its running loop.
     */
    void close();

    /**
     * Processes all the input events accumulated in the event queue by passing them to the Scene::processEvent method.
     */
    void processInput();

    /**
     * Processes single input event, such as player pressing some button, resizing the game window, etc.
     *
     * @param event the processing event.
     *
     * @note This function must be implemented in any derived scene class.
     */
    virtual void processEvent(const sf::Event& event) = 0;

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
     * Returns the bounding box of the scene.
     * The bounding box defines the smallest rectangle that completely encloses the scene.
     *
     * @return The bounding box of the scene as a rectangle.
     */
    Rectangle getBoundingBox() const;

    /**
     * Checks for potential collision between two game objects and notifies the objects about the result of the check
     * by calling their GameObject::onCollision methods and provided with the CollisionInfo structure.
     *
     * @param object1 The first game object to check for collision.
     * @param object2 The second game object to check for collision.
     */
    void detectCollision(GameObject& object1, GameObject& object2);

    /**
     * Updates the scene state based on time elapsed since the last update.
     *
     * @param delta The time elapsed since the last update.
     *
     * @note This function must be implemented in any derived scene class.
     */
    virtual void update(sf::Time delta) = 0;

    /**
     * Renders the whole scene on the window: resets the window, draws the background and then
     * delegated to the Scene::draw method to draw all game objects belonging to the scene.
     */
    void render();

    /**
     * Renders the given game object on the window.
     *
     * @param object The game object to be rendered.
     */
    void draw(const GameObject& object);

    /**
     * Draws all the game objects belonging to the scene on the window.
     *
     * @note This function must be implemented in any derived scene class.
     */
    virtual void draw() = 0;

    /**
     * Returns the sprite to draw on the background of the scene.
     *
     * This method returns the background details of the current instance.
     * The background information may vary depending on the implementation and context.
     *
     * @return A constant reference to the background information.
     */

    sf::Sprite background() const;

private:
    sf::RenderWindow window;
    TextureManager textureManager;
    float width;
    float height;
    bool active;
};

#endif // CPPBASICS_SCENE_HPP
