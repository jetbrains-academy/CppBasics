#include "scene.hpp"

#include "constants.hpp"
#include "simplscene.hpp"

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
    static SimpleScene scene;
    return &scene;
}

void Scene::run() {
    sf::Clock clock;
    while (active && window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput();
        update(delta);
        render();
        window.display();
    }
}

void Scene::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        processEvent(event);
    }
}

void Scene::close() {
    active = false;
    window.close();
}

Rectangle Scene::boundingBox() const {
    Rectangle box;
    box.topLeft = { 0.0f, 0.0f };
    box.botRight = { width, height };
    return box;
}

void Scene::move(GameObject &object, Point2D vector) {
    object.move(vector);
    fitInto(object);
}

void Scene::fitInto(GameObject &object) {
    Rectangle rect = ::fitInto(object.boundingBox(), boundingBox());
    object.setPosition(center(rect));
}

void Scene::detectCollision(GameObject& object1, GameObject& object2) {
    CollisionInfo info = collision(object1, object2);
    object1.onCollision(object2, info);
    object2.onCollision(object1, info);
}

void Scene::draw(const GameObject &object) {
    object.draw(window, textureManager);
}
