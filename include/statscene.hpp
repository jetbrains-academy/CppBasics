#ifndef CPPBASICS_STATSCENE_HPP
#define CPPBASICS_STATSCENE_HPP

#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "player.hpp"
#include "consumable.hpp"
#include "enemy.hpp"


/**
 * StaticScene is a scene operating a static fixed collection of game objects,
 * namely single player, single consumable, and single enemy objects.
 */
class StaticScene : public Scene {
public:

    /**
     * Initializes the scene.
     */
    void initialize() override;

    /**
     * Process the given event.
     */
    void processEvent(const sf::Event &event) override;

    /**
     * Updates the object's state based on the elapsed time since the last update.
     */
    void update(sf::Time delta) override;

    /**
     * Draws the scene with all its game objects.
     */
    void draw() override;

private:
    PlayerObject player;
    ConsumableObject consumable;
    EnemyObject enemy;
};

#endif // CPPBASICS_STATSCENE_HPP
