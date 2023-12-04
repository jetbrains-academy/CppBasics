#include "engine.hpp"

#include "constants.hpp"

GameEngine *GameEngine::create() {
    // TODO: write your solution here
    return nullptr;
}

GameEngine::GameEngine()
    : scene(nullptr)
    , active(true)
{
    // initialize random number generator
    srand(time(nullptr));
    // initialize resource managers
    active &= sceneManager.initialize();
    active &= textureManager.initialize();
    if (!active) {
        return;
    }
    // set the current scene
    scene = sceneManager.getCurrentScene();
    // initialize the application window
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Game");
    window.setFramerateLimit(60);
}

void GameEngine::run() {
    sf::Clock clock;
    while (isActive()) {
        sf::Time delta = clock.restart();
        processInput();
        update(delta);
        render();
        sceneTransition();
    }
}

bool GameEngine::isActive() const {
    return active && window.isOpen();
}

void GameEngine::close() {
    active = false;
    window.close();
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