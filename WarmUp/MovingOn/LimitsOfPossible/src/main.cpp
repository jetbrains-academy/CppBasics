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

void update(sf::Time delta, sf::CircleShape& player,
            sf::CircleShape* consumable, Circle* consumableCircle, bool consumed[], int size) {
    Point2D playerPosition = { player.getPosition().x, player.getPosition().y };
    Point2D playerVelocity = calculateVelocity();
    Point2D newPlayerPosition = move(playerPosition, playerVelocity, 0.001f * delta.asMilliseconds());
    Point2D adjustedPlayerPosition = adjustToBorders(newPlayerPosition);
    player.setPosition(adjustedPlayerPosition.x, adjustedPlayerPosition.y);

    Circle playerCircle = { playerPosition, RADIUS };
    for (int i = 0; i < size; ++i) {
        Point2D consumablePosition = { consumable[i].getPosition().x, consumable[i].getPosition().y };
        consumableCircle[i] = { consumablePosition, CONSUMABLE_RADIUS };
    }
    collisionLoop(playerCircle, consumableCircle, consumed, size);
}

void render(sf::RenderWindow& window, sf::Sprite& background,
            const sf::CircleShape& player, const sf::CircleShape* consumable, bool consumed[], int size)
{
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    for (int i = 0; i < size; ++i) {
        if (!consumed[i]) {
            window.draw(consumable[i]);
        }
    }
    window.display();
}

int main() {
    int status = 0;

    srand(time(NULL));

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
    Circle playerCircle = { {player.getPosition().x, player.getPosition().y}, player.getRadius() };

    sf::Texture consumableTexture;
    status = initConsumableTexture(consumableTexture);
    if (status != 0) {
        return status;
    }

    const int COUNT = 4;
    sf::CircleShape consumable[COUNT];
    Circle consumableCircles[COUNT];
    status = initConsumablesRandom(consumable, COUNT, consumableTexture, playerCircle);
    if (status != 0) {
        return status;
    }

    bool consumed[COUNT];
    for (int i = 0; i < COUNT; ++i) {
        consumed[i] = false;
    }

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput(window);
        update(delta, player, consumable, consumableCircles, consumed, COUNT);
        render(window, background, player, consumable, consumed, COUNT);
    }
}