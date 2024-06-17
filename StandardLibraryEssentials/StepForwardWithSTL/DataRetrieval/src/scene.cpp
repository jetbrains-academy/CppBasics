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

void Scene::drawScore(sf::RenderWindow &window, unsigned int value) const {
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("resources/pixelLetters.ttf"))
    {
        std::cerr << "Could not load font\n";
    }
    text.setFont(font);
    text.setString("Score: " + std::to_string(value));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(SCENE_WIDTH - 120, 0); // top right corner
    window.draw(text);
}

unsigned int Scene::getScore() const {
    return score;
}

bool Scene::isPlayerAlive() const {
    return playerAlive;
}

void Scene::updateScore(unsigned int value) {
    score = value;
}

void Scene::updatePlayerStatus(bool alive) {
    playerAlive = alive;
}
