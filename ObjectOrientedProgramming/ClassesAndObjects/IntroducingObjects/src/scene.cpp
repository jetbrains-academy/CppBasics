#include "scene.hpp"

#include "constants.hpp"

Scene::Scene()
    : width(SCENE_WIDTH)
    , height(SCENE_HEIGHT)
{
    window.create(sf::VideoMode(width, height), "Space Game");
    window.setFramerateLimit(60);
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

void Scene::draw(const GameObject &object) {
    if (object.getState() == LIVE) {
        object.draw(window);
    }
}
