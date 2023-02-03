#include <SFML/Graphics.hpp>

#include "scene.hpp"

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

void update(sf::Time delta, sf::Shape &player, sf::Shape &consumable, bool &consumed)
{
    Point2D playerPosition = { player.getPosition().x, player.getPosition().y };
    Point2D playerVelocity = calculateVelocity();
    Point2D newPlayerPosition = move(playerPosition, playerVelocity, 0.001f * delta.asMilliseconds());
    Point2D adjustedPlayerPosition = adjustToBorders(newPlayerPosition);
    player.setPosition(adjustedPlayerPosition.x, adjustedPlayerPosition.y);

    Circle playerCircle = { playerPosition, RADIUS };
    Point2D consumablePosition = {consumable.getPosition().x, consumable.getPosition().y };
    Circle consumableCircle = { consumablePosition, CONSUMABLE_RADIUS };

    if (consumed) {
        return;
    }
    consumed = collision(playerCircle, consumableCircle);
}

void render(sf::RenderWindow& window, const sf::Sprite& background, const sf::Shape& player, const sf::Shape& consumable, bool consumed) {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    if (!consumed) {
        window.draw(consumable);
    }
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

    sf::CircleShape consumable;
    sf::Texture consumableTexture;
    status = initConsumable(consumable, consumableTexture);
    if (status != 0) {
        return status;
    }
    bool consumed = false;

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput(window);
        update(delta, player, consumable, consumed);
        render(window, background, player, consumable, consumed);
    }
}