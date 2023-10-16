#ifndef CPPBASICS_PLAYER_HPP
#define CPPBASICS_PLAYER_HPP

#include "cgobject.hpp"


/**
 * The PlayerObject class represents a player in the game.
 * It provides additional behavior and properties specific to players.
 */
class PlayerObject : public CircleGameObject {
public:

    /**
     * Constructor that initializes player's shape and position.
     */
    PlayerObject();

    /**
     * Returns the `PLAYER` kind.
     */
    GameObjectKind getKind() const override;

    /**
     * Returns the current velocity of the object.
     * The object's velocity depends on the control keys pressed by the player at the moment.
     */
    Point2D getVelocity() const override;

    /**
     * Idle for the player object.
     */
    void update(sf::Time delta) override;

    /**
     * Handler a potential collision of player object with another object.
     * In particular, if player collided with an enemy object, sets its status to `DESTROYED`.
     */
    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;

    /**
     * Retrieves the texture associated with the player object based on its current status.
     */
    const sf::Texture* getTexture(TextureManager& textureManager) const override;

};

#endif // CPPBASICS_PLAYER_HPP
