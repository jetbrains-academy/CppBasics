#include "dynscene.hpp"

#include "player.hpp"
#include "consumable.hpp"
#include "enemy.hpp"
#include "utils.hpp"

void DynamicScene::processEvent(const sf::Event& event) {
    switch (event.type) {
        case sf::Event::Closed:
            close();
            break;
        default:
            break;
    }
}

void DynamicScene::update(sf::Time delta) {
    objects.foreach([delta] (GameObject& object) {
        object.update(delta);
    });
    objects.foreach([this, delta] (GameObject& object) {
        move(object, delta);
    });
    objects.foreach([this] (GameObject& object) {
        objects.foreach([this, &object] (GameObject& other) {
            detectCollision(object, other);
        });
    });
}

std::shared_ptr<GameObject> DynamicScene::addNewGameObject(GameObjectKind kind) {
    std::shared_ptr<GameObject> object;
    while (!object) {
        // create an object with default position
        switch (kind) {
            case GameObjectKind::PLAYER: {
                object = std::make_shared<PlayerObject>();
                break;
            }
            case GameObjectKind::CONSUMABLE: {
                object = std::make_shared<ConsumableObject>();
                break;
            }
            case GameObjectKind::ENEMY: {
                object = std::make_shared<EnemyObject>();
                break;
            }
        }
        // set random position for consumable and enemy objects
        if (kind == GameObjectKind::CONSUMABLE ||
            kind == GameObjectKind::ENEMY) {
            setPosition(*object, generatePoint(boundingBox()));
        }
        // check that object does not collide with existing objects
        bool collide = false;
        objects.foreach([&collide, &object](GameObject& other) {
            collide = collide || collision(*object, other).collide;
        });
        // reset a colliding object
        if (collide) {
            object = nullptr;
        }
    }
    objects.insert(object);
    return object;
}

void DynamicScene::draw() {
    objects.foreach([this] (const GameObject& object) {
        Scene::draw(object);
    });
}

