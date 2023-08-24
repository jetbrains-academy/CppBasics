#ifndef CPPBASICS_DYNSCENE_HPP
#define CPPBASICS_DYNSCENE_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "gobjectlist.hpp"
#include "player.hpp"

class DynamicScene : public Scene {
public:

    void initialize() override;

    void processEvent(const sf::Event &event) override;

    void update(sf::Time delta) override;

    void draw() override;

protected:

    void updateObjectsList();

    std::shared_ptr<GameObject> addNewGameObject(GameObjectKind kind);

private:
    GameObjectList objects;
};


#endif // CPPBASICS_DYNSCENE_HPP
