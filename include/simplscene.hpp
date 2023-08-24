#ifndef CPPBASICS_SIMPLSCENE_HPP
#define CPPBASICS_SIMPLSCENE_HPP

#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "player.hpp"
#include "consumable.hpp"
#include "enemy.hpp"

class SimpleScene : public Scene {
public:

    void initialize() override;

    void processEvent(const sf::Event &event) override;

    void update(sf::Time delta) override;

    void draw() override;

private:
    PlayerObject player;
    ConsumableObject consumable;
    EnemyObject enemy;
};

#endif // CPPBASICS_SIMPLSCENE_HPP
