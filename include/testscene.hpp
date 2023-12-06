#ifndef CPPBASICS_TESTSCENE_HPP
#define CPPBASICS_TESTSCENE_HPP

#include "gobject.hpp"
#include "scene.hpp"

class TestGameObject : public GameObject {
public:

    inline TestGameObject()
        : position(Point2D { 0.0f, 0.0f })
        , velocity(Point2D { 0.0f, 0.0f })
        , status(GameObjectStatus::NORMAL)
        , kind(GameObjectKind::CONSUMABLE)
    {}

    inline TestGameObject(Point2D position, Point2D velocity, GameObjectStatus status, GameObjectKind kind)
        : position(position)
        , velocity(velocity)
        , status(status)
        , kind(kind)
    {}

    TestGameObject(const TestGameObject& other) = default;
    TestGameObject& operator=(const TestGameObject& other) = default;

    inline Point2D getPosition() const override {
        return position;
    }

    inline void setPosition(Point2D position) override {
        this->position = position;
    }

    inline GameObjectStatus getStatus() const override {
        return status;
    }

    inline GameObjectKind getKind() const override {
        return kind;
    }

    inline Point2D getVelocity() const override {
        return velocity;
    }

    inline Rectangle getBoundingBox() const override {
        return Rectangle { position, position };
    }

    inline void update(sf::Time delta) override {
        return;
    }

    inline void onCollision(const GameObject& object, const CollisionInfo& info) override {
        return;
    }

    inline void draw(sf::RenderWindow& window, TextureManager& textureManager) const override {
        return;
    }

    inline const sf::Texture* getTexture(TextureManager& textureManager) const override {
        return nullptr;
    }

    void performMove(Point2D vector) {
        move(vector);
    }

private:
    Point2D position;
    Point2D velocity;
    GameObjectStatus status;
    GameObjectKind kind;
};

#endif //CPPBASICS_TESTSCENE_HPP
