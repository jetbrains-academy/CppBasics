#ifndef CPPBASICS_PLAYER_HPP
#define CPPBASICS_PLAYER_HPP

#include "cgobject.hpp"

class PlayerObject : public CircleGameObject {
public:
    PlayerObject();

    Point2D getVelocity() const override;

    GameObjectKind getKind() const override;

    const sf::Texture* getTexture(TextureManager& textureManager) const override;

    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;
};

#endif // CPPBASICS_PLAYER_HPP
