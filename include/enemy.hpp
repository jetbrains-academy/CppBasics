#ifndef CPPBASICS_ENEMY_HPP
#define CPPBASICS_ENEMY_HPP

#include "cgobject.hpp"


/**
 * A class representing an enemy object in the game.
 */
class EnemyObject : public CircleGameObject {
public:

    /**
     * Constructor that initializes enemy's shape and position.
     */
    EnemyObject();

    /**
     * Returns the `ENEMY` kind.
     */
    GameObjectKind getKind() const override;

    /**
     * Returns the current velocity of the object.
     * Enemy objects change their velocity randomly on every fixed period of time.
     */
    Point2D getVelocity() const override;

    /**
     * Updates the state of an object based on the elapsed time.
     * Changes the velocity on every fixed period of time.
     */
    void update(sf::Time delta) override;

    /**
     * Handles the potential collision of enemy object with another object.
     */
    void onCollision(const GameObject &object, const CollisionInfo &info) override;

    /**
     * Retrieves the texture associated with the enemy object based on its current status.
     */
    const sf::Texture* getTexture(TextureManager& textureManager) const override;

protected:

    /**
     * Sets the velocity of the enemy object.
     */
    void setVelocity(Point2D velocity);

    /**
     * Updates the velocity of an enemy object.
     */
    void updateVelocity();

private:
    Point2D velocity;
    sf::Time updateTimer;
};

#endif // CPPBASICS_ENEMY_HPP
