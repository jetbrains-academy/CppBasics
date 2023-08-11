#ifndef CPPBASICS_ENEMY_HPP
#define CPPBASICS_ENEMY_HPP

#include "cgobject.hpp"

class EnemyObject : public CircleGameObject {
public:
    EnemyObject();

    Point2D getVelocity() const override;

    GameObjectKind getKind() const override;

    const sf::Texture* getTexture(TextureManager& textureManager) const override;

    void update(sf::Time delta) override;

    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;
};

#endif // CPPBASICS_ENEMY_HPP
