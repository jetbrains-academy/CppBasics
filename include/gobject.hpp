#ifndef CPPBASICS_GOBJECT_HPP
#define CPPBASICS_GOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "rectangle.hpp"
#include "collision.hpp"
#include "textures.hpp"
#include "enums.hpp"


/**
 * GameObject is a base class for game objects in a game engine.
 * It defines functions for getting and setting object properties,
 * updating object status, and drawing the object on a screen.
 */
class GameObject {
public:

    /**
     * Returns the current position of the object.
     */
    virtual Point2D getPosition() const = 0;

    /**
     * Returns the current status of the object.
     */
    virtual GameObjectStatus getStatus() const = 0;

    /**
     * Returns the kind of the object.
     */
    virtual GameObjectKind getKind() const = 0;

    /**
     * Returns the current velocity of the object.
     */
    virtual Point2D getVelocity() const = 0;

    /**
     * Returns the bounding box of the object.
     * A bounding box is the smallest rectangle that entirely encompasses an object.
     */
    virtual Rectangle getBoundingBox() const = 0;

    /**
     * Updates the state of an object based on the elapsed time.
     *
     * @param delta The time elapsed since last update.
     */
    virtual void update(sf::Time delta) = 0;

    /**
     * Handler function called when a potential collision occurs between this object and another object.
     *
     * @param object The potentially collided object.
     * @param info The information about the potential collision.
     */
    virtual void onCollision(const GameObject& object, const CollisionInfo& info) = 0;

    /**
     * This function is used to render the object on a SFML window passed as an argument.
     *
     * @param window The window on which the object should be drawn.
     * @param textureManager The texture manager object used to retrieve the required textures for drawing.
     */
    virtual void draw(sf::RenderWindow& window, TextureManager& textureManager) const = 0;

    /**
     * Retrieves the texture associated with the object.
     *
     * @param textureManager The texture manager object used to retrieve the texture.
     * @return A constant pointer to the texture. If the object should not be drawn in the current status,
     *         the pointer should be null.
     */
    virtual const sf::Texture* getTexture(TextureManager& textureManager) const = 0;

    /**
     * Destructor of a game object.
     */
    virtual ~GameObject() = default;

protected:
    friend class Scene;

    /**
     * Changes the current position of the object.
     */
    virtual void setPosition(Point2D position) = 0;

    /**
     * Moves an object in a direction given by the passed vector.
     */
    void move(Point2D vector);
};


/**
 * This function takes in two game objects as parameters and checks whether they are colliding.
 * It returns a CollisionInfo structure that contains information about the collision.
 */
CollisionInfo collisionInfo(const GameObject& object1, const GameObject& object2);

#endif // CPPBASICS_GOBJECT_HPP
