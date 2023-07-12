#ifndef CPPBASICS_SCENE_HPP
#define CPPBASICS_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "gobject.hpp"

class Scene {
public:

    virtual void processEvent(const sf::Event& event) = 0;

    virtual void update(sf::Time delta) = 0;

    virtual void render() = 0;

    virtual ~Scene() {}

    static Scene* create();

protected:
    void move(GameObject& object, Point2D vector);

private:
    void fitInto(GameObject& object);

    float width;
    float height;

    sf::RenderWindow window;
};

#endif // CPPBASICS_SCENE_HPP
