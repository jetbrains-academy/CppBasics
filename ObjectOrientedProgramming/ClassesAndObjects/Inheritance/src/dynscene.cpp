#include "dynscene.hpp"

#include "constants.hpp"
#include "player.hpp"
#include "consumable.hpp"
#include "enemy.hpp"
#include "utils.hpp"

const int MAX_DYNAMIC_OBJECTS_ON_SCENE = 10;
const int MAX_ENEMY_OBJECTS_ON_SCENE = 4;

const int NEW_DYNAMIC_OBJECT_PROB = 1;
const int NEW_ENEMY_OBJECT_PROB = 10;

GameplayDynamicScene::GameplayDynamicScene() : Scene(SCENE_WIDTH, SCENE_HEIGHT) {}

void GameplayDynamicScene::activate() {
    addNewGameObject(GameObjectKind::PLAYER);
}

void GameplayDynamicScene::deactivate() {
    // remove all the objects from the list
    objects.remove([&] (const GameObject& object) {
        return true;
    });
}

SceneID GameplayDynamicScene::getID() const {
    return SceneID::DYNAMIC_GAME_FIELD;
}

SceneID GameplayDynamicScene::getNextSceneID() const {
    return SceneID::DYNAMIC_GAME_FIELD;
}

void GameplayDynamicScene::processEvent(const sf::Event& event) {
    return;
}

void GameplayDynamicScene::update(sf::Time delta) {
    // update the objects' state
    objects.foreach([delta] (GameObject& object) {
        object.update(delta);
    });
    // move objects according to their velocity and elapsed time
    objects.foreach([this, delta] (GameObject& object) {
        move(object, delta);
    });
    // compute collision information for each pair of objects
    objects.foreach([this] (GameObject& object) {
        objects.foreach([this, &object] (GameObject& other) {
            if (&object != &other) {
                detectCollision(object, other);
            }
        });
    });
    // update the list of objects
    updateObjectsList();
}

void GameplayDynamicScene::updateObjectsList() {
    // remove destroyed objects from the list
    objects.remove([] (const GameObject& object) {
        return (object.getStatus() == GameObjectStatus::DESTROYED)
            && (object.getKind() != GameObjectKind::PLAYER);
    });
    // count the number of the different kinds of objects present on the scene
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
    // add new objects of randomly chosen kind if there is enough room for them on the scene
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

std::shared_ptr<GameObject> GameplayDynamicScene::addNewGameObject(GameObjectKind kind) {
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
            setObjectPosition(*object, generatePoint(getBoundingBox()));
        } else {
            fitInto(*object);
        }
        // check that object does not collide with existing objects
        bool collide = false;
        objects.foreach([&collide, &object](GameObject& other) {
            collide |= collisionInfo(*object, other).collide;
        });
        // reset a colliding object
        if (collide) {
            object = nullptr;
        }
    }
    objects.insert(object);
    return object;
}

void GameplayDynamicScene::draw(sf::RenderWindow &window, TextureManager& textureManager) {
    // draw background
    drawBackground(window, textureManager.getTexture(GameTextureID::SPACE));
    // draw all objects on the scene
    objects.foreach([&] (const GameObject& object) {
        object.draw(window, textureManager);
    });
}

