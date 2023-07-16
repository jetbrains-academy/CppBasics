#include "scene.hpp"

#include "player.hpp"
#include "consumable.hpp"
#include "enemy.hpp"

class SimpleScene : public Scene {
public:

    void processEvent(const sf::Event &event) override {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }

    void update(sf::Time delta) override {
        Point2D playerVelocity = calculateVelocity();
        move(player, playerVelocity);
    }

    void render() override {
        draw(player);
        draw(consumable);
        draw(enemy);
        window.display();
    }

private:
    PlayerObject player;
    ConsumableObject consumable;
    EnemyObject enemy;
};