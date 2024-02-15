#include "scene.hpp"

#include "operators.hpp"

Scene::Scene(float width, float height)
    : width(width)
    , height(height)
{}

Rectangle Scene::getBoundingBox() const {
    Rectangle box;
    box.topLeft = { 0.0f, 0.0f };
    box.botRight = { width, height };
    return box;
}

void Scene::setObjectPosition(GameObject& object, Point2D position) {
    // TODO: write your solution here
}

void Scene::move(GameObject &object, Point2D vector) {
    // TODO: write your solution here
}

void Scene::move(GameObject& object, sf::Time delta) {
    move(object, 0.001f * delta.asMilliseconds() * object.getVelocity());
}

void Scene::fitInto(GameObject &object) {
    Rectangle rect = ::fitInto(object.getBoundingBox(), getBoundingBox());
    object.setPosition(center(rect));
}

void Scene::detectCollision(GameObject& object1, GameObject& object2) {
    CollisionInfo info = collisionInfo(object1, object2);
    object1.onCollision(object2, info);
    object2.onCollision(object1, info);
}

void Scene::drawBackground(sf::RenderWindow &window, const sf::Texture* texture) const {
    sf::Sprite background;
    background.setTexture(*texture);
    background.setTextureRect(sf::IntRect(0, 0, width, height));
    window.draw(background);
}