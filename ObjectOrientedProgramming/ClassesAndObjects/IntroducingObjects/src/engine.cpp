#include "engine.hpp"

GameEngine *GameEngine::create() {
    static GameEngine engine;
    return &engine;
}

GameEngine::GameEngine()
    : scene(nullptr)
    , active(true)
{
    active &= sceneManager.initialize();
    active &= textureManager.initialize();
    if (!active) {
        return;
    }
    scene = sceneManager.getCurrentScene();
    Rectangle sceneBox = scene->getBoundingBox();
    window.create(sf::VideoMode(width(sceneBox), height(sceneBox)), "Space Game");
    window.setFramerateLimit(60);
}

void GameEngine::run() {
    sf::Clock clock;
    while (active && window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput();
        update(delta);
        render();
        sceneTransition();
    }
}

void GameEngine::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        processEvent(event);
    }
}

void GameEngine::processEvent(const sf::Event &event) {
    switch (event.type) {
        case sf::Event::Closed:
            close();
            break;
        default:
            scene->processEvent(event);
            break;
    }
}

void GameEngine::update(sf::Time delta) {
    scene->update(delta);
}

void GameEngine::render() {
    window.clear(sf::Color::White);
    scene->draw(window, textureManager);
    window.display();
}

void GameEngine::sceneTransition() {
    if (scene->getNextSceneID() != scene->getID()) {
        sceneManager.transitionScene(scene->getNextSceneID());
        scene = sceneManager.getCurrentScene();
        resizeWindow();
    }
}

void GameEngine::resizeWindow() {
    Rectangle sceneBox = scene->getBoundingBox();
    sf::Vector2u sceneSize = sf::Vector2u(width(sceneBox), height(sceneBox));
    window.setSize(sceneSize);
}

void GameEngine::close() {
    active = false;
    window.close();
}