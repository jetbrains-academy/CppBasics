#include <iostream>

#include <SFML/Graphics.hpp>

#include "game.hpp"

void processEvent(sf::RenderWindow& window, const sf::Event& event) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
    }
}

void processInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        processEvent(window, event);
    }
}

void update(sf::Time delta, sf::Shape& player) {
    float x = player.getPosition().x;
    float y = player.getPosition().y;
    x = move(x, SPEED, 0.001f * delta.asMilliseconds());
    player.setPosition(x, y);
}

void render(sf::RenderWindow& window, const sf::Sprite& background, const sf::Shape& player) {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    window.display();
}

int main() {
    int status = 0;

    sf::RenderWindow window;
    status = initWindow(window);
    if (status != 0) {
        return status;
    }

    sf::Sprite background;
    sf::Texture backgroundTexture;
    status = initBackrground(background, backgroundTexture);
    if (status != 0) {
        return status;
    }

    sf::CircleShape player;
    sf::Texture playerTexture;
    status = initPlayer(player, playerTexture);
    if (status != 0) {
        return status;
    }

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput(window);
        update(delta, player);
        render(window, background, player);
    }
}