#include "dynscene.hpp"

#include "player.hpp"
#include "consumable.hpp"
#include "enemy.hpp"
#include "utils.hpp"

const int MAX_DYNAMIC_OBJECTS_ON_SCENE = 10;
const int MAX_ENEMY_OBJECTS_ON_SCENE = 4;

const int NEW_DYNAMIC_OBJECT_PROB = 1;
const int NEW_ENEMY_OBJECT_PROB = 10;

void DynamicScene::initialize() {
    addNewGameObject(GameObjectKind::PLAYER);
}

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
            if (&object != &other) {
                detectCollision(object, other);
            }
        });
    });
    updateObjectsList();
}

void DynamicScene::updateObjectsList() {
    objects.remove([] (const GameObject& object) {
        return (object.getState() == GameObjectState::DEAD)
            && (object.getKind() != GameObjectKind::PLAYER);
    });
    int consumableCount = 0;
    int enemyCount = 0;
    objects.foreach([&] (const GameObject& object) {
        switch (object.getKind()) {
            case GameObjectKind::CONSUMABLE:
                ++consumableCount;
                break;
            case GameObjectKind::ENEMY:
                ++enemyCount;
                break;
            default:
                break;
        }
    });
    int dynamicObjectsCount = consumableCount + enemyCount;
    if (dynamicObjectsCount < MAX_DYNAMIC_OBJECTS_ON_SCENE) {
        int r = rand() % 100;
        int k = rand() % 100;
        if (r < NEW_DYNAMIC_OBJECT_PROB) {
            if (k < NEW_ENEMY_OBJECT_PROB && enemyCount < MAX_ENEMY_OBJECTS_ON_SCENE) {
                addNewGameObject(GameObjectKind::ENEMY);
            } else if (k > NEW_ENEMY_OBJECT_PROB) {
                addNewGameObject(GameObjectKind::CONSUMABLE);
            }
        }
    }
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
        } else {
            fitInto(*object);
        }
        // check that object does not collide with existing objects
        bool collide = false;
        objects.foreach([&collide, &object](GameObject& other) {
            collide |= collision(*object, other).collide;
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

