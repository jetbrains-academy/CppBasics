#ifndef CPPBASICS_GAME_HPP
#define CPPBASICS_GAME_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "circle.hpp"
#include "direction.hpp"
#include "utils.hpp"
#include "constants.hpp"

float move(float position, float velocity, float delta);

Point2D adjustToBorders(Point2D position);

bool collision(Circle circle1, Circle circle2);
void collisionLoop(Circle player, Circle consumable[], bool consumed[], int size);
void approachingLoop(Circle player, Circle consumable[], bool warned[], int size);

float generateCoordinate(float min, float max);
Circle generateCircle(float radius);

struct Consumable {
    Circle circle;
    bool concerned;
    bool destroyed;
};

/******************************************************************************/

inline int initWindow(sf::RenderWindow& window) {
    window.create(sf::VideoMode(SCENE_WIDTH, SCENE_HEIGHT), "Space Game");
    window.setFramerateLimit(60);
    return 0;
}

inline int initBackrground(sf::Sprite& sprite, sf::Texture& texture) {
    if (!texture.loadFromFile("resources/space.png")) {
        return 1;
    }
    texture.setRepeated(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT));
    return 0;
}


inline int initPlayer(sf::CircleShape& shape, sf::Texture& texture) {
    shape.setRadius(RADIUS);
    shape.setOrigin(RADIUS, RADIUS);
    shape.setPosition(PLAYER_START_X, PLAYER_START_Y);
    if (!texture.loadFromFile("resources/planet.png")) {
        return 1;
    }
    shape.setTexture(&texture);
    return 0;
}

inline int initConsumableTexture(sf::Texture& texture) {
    std::string filename = "resources/star.png";
    if (!texture.loadFromFile(filename)) {
        return 1;
    }
    texture.setSmooth(true);
    return 0;
}

inline int initConsumable(sf::CircleShape& shape, const Circle& circle, const sf::Texture& texture) {
    shape.setRadius(circle.radius);
    shape.setOrigin(circle.radius, circle.radius);
    shape.setPosition(circle.center.x, circle.center.y);
    shape.setTexture(&texture);
    return 0;
}

inline int initConsumable(sf::CircleShape& shape, const sf::Texture& texture) {
    Circle circle = { { CONSUMABLE_START_X, CONSUMABLE_START_Y }, CONSUMABLE_RADIUS };
    return initConsumable(shape, circle, texture);
}

inline int initConsumableRandom(sf::CircleShape& shape, const sf::Texture& texture, Circle playerCircle) {
    Circle consumableCircle;
    while (true) {
        consumableCircle = generateCircle(CONSUMABLE_RADIUS);
        if (collision(consumableCircle, playerCircle))
            continue;
        break;
    }
    return initConsumable(shape, consumableCircle, texture);
}

inline int initConsumablesRandom(sf::CircleShape* shapes, int count, const sf::Texture& texture, Circle playerCircle) {
    std::vector<Circle> circles(count);
    for (int i = 0; i < count; ++i) {
        while (true) {
            circles[i] = generateCircle(CONSUMABLE_RADIUS);
            bool collides = collision(circles[i], playerCircle);
            for (int j = 0; (j < i) && !collides; ++j) {
                collides = collision(circles[i], circles[j]);
            }
            if (collides) continue;
            break;
        }
        int status = initConsumable(shapes[i], circles[i], texture);
        if (status != 0) {
            return status;
        }
    }
    return 0;
}


#endif // CPPBASICS_GAME_HPP
