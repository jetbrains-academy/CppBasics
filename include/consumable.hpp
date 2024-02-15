#ifndef CPPBASICS_CONSUMABLE_HPP
#define CPPBASICS_CONSUMABLE_HPP

#include "cgobject.hpp"

/**
 * A class representing a consumable object in the game.
 */
class ConsumableObject : public CircleGameObject {
public:

    /**
     * Constructor that initializes consumable's shape and position.
     */
    ConsumableObject();

    /**
     * Returns the `CONSUMABLE` kind.
     */
    GameObjectKind getKind() const override;

    /**
     * Returns the current velocity of the object.
     * Consumable objects are static and thus their velocity is always zero.
     */
    Point2D getVelocity() const override;

    /**
     * Updates the state of an object based on the elapsed time.
     * Always resets consumable status back to `NORMAL`, unless it was `DESTROYED`.
     */
    void update(sf::Time delta) override;

    /**
     * Handles the potential collision of consumable object with another object.
     * Sets the status to `CONCERNED` if some other object is approaching the consumable.
     * Sets the status to `DESTROYED` in case of an actual collision.
     */
    void onCollision(const GameObject &object, const CollisionInfo &info) override;

    /**
     * Retrieves the texture associated with the consumable object based on its current status.
     */
    const sf::Texture* getTexture(TextureManager& textureManager) const override;

};

#endif // CPPBASICS_CONSUMABLE_HPP
