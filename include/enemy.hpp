#ifndef CPPBASICS_ENEMY_HPP
#define CPPBASICS_ENEMY_HPP

#include "cgobject.hpp"

class EnemyObject : public CircleGameObject {
public:
    EnemyObject();

    GameObjectKind getKind() const override;

    Point2D getVelocity() const override;

    void update(sf::Time delta) override;

    void onCollision(const GameObject &object, const CollisionInfo &collisionData) override;

    const sf::Texture* getTexture(TextureManager& textureManager) const override;

private:
    Point2D velocity;
    sf::Time updateTimer;
};

#endif // CPPBASICS_ENEMY_HPP
