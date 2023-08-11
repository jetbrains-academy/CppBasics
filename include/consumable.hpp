#ifndef CPPBASICS_CONSUMABLE_HPP
#define CPPBASICS_CONSUMABLE_HPP

#include "cgobject.hpp"

class ConsumableObject : public CircleGameObject {
public:
    ConsumableObject();

    Point2D getVelocity() const override;

    GameObjectKind getKind() const override;

    const sf::Texture* getTexture(TextureManager& textureManager) const override;

    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;
};

#endif // CPPBASICS_CONSUMABLE_HPP
