#ifndef CPPBASICS_GOBJECT_HPP
#define CPPBASICS_GOBJECT_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "rectangle.hpp"
#include "collision.hpp"
#include "textures.hpp"

// TODO: use enum class (?)
enum class GameObjectState {
    NORMAL, CONCERNED, DEAD,
};

enum class GameObjectKind {
    PLAYER, CONSUMABLE, ENEMY
};

class GameObject {
public:

    void move(Point2D vector);

    virtual Point2D getPosition() const = 0;

    virtual void setPosition(Point2D position) = 0;

    virtual Point2D getVelocity() const = 0;

    virtual Rectangle boundingBox() const = 0;

    virtual GameObjectState getState() const = 0;

    virtual void setState(GameObjectState newState) = 0;

    virtual GameObjectKind getKind() const = 0;

    virtual const sf::Texture* getTexture(TextureManager& textureManager) const = 0;

    virtual void update(sf::Time delta) = 0;

    virtual void draw(sf::RenderWindow& window, TextureManager& textureManager) const = 0;

    virtual void onCollision(const GameObject& object, const CollisionInfo& collisionData) = 0;

    virtual ~GameObject() {}

};

CollisionInfo collision(const GameObject& object1, const GameObject& object2);

#endif // CPPBASICS_GOBJECT_HPP
