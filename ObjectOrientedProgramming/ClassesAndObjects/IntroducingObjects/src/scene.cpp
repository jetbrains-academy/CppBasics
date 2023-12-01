#include "scene.hpp"

#include "constants.hpp"
#include "operators.hpp"
#include "statscene.hpp"
#include "dynscene.hpp"

Scene::Scene()
    : width(SCENE_WIDTH)
    , height(SCENE_HEIGHT)
    , active(true)
{
    window.create(sf::VideoMode(width, height), "Space Game");
    window.setFramerateLimit(60);
    active &= textureManager.initialize();
}

Scene* Scene::create() {
    // static StaticScene scene;
    static DynamicScene scene;
    return &scene;
}

void Scene::run() {
    initialize();
    sf::Clock clock;
    while (active && window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput();
        update(delta);
        render();
    }
}

void Scene::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        processEvent(event);
    }
}

void Scene::render() {
    window.clear(sf::Color::White);
    window.draw(background());
    draw();
    window.display();
}

void Scene::close() {
    active = false;
    window.close();
}

void Scene::setObjectPosition(GameObject& object, Point2D position) {
    object.setPosition(position);
    fitInto(object);
}

void Scene::move(GameObject &object, Point2D vector) {
    object.move(vector);
    fitInto(object);
}

void Scene::move(GameObject& object, sf::Time delta) {
    move(object, 0.001f * delta.asMilliseconds() * object.getVelocity());
}

void Scene::fitInto(GameObject &object) {
    Rectangle rect = ::fitInto(object.getBoundingBox(), getBoundingBox());
    object.setPosition(center(rect));
}

Rectangle Scene::getBoundingBox() const {
    Rectangle box;
    box.topLeft = { 0.0f, 0.0f };
    box.botRight = { width, height };
    return box;
}

void Scene::detectCollision(GameObject& object1, GameObject& object2) {
    CollisionInfo info = collisionInfo(object1, object2);
    object1.onCollision(object2, info);
    object2.onCollision(object1, info);
}

sf::Sprite Scene::background() const {
    sf::Sprite background;
    background.setTexture(*textureManager.getTexture(GameTextureID::SPACE));
    background.setTextureRect(sf::IntRect(0, 0, width, height));
    return background;
}

void Scene::draw(const GameObject &object) {
    object.draw(window, textureManager);
}
