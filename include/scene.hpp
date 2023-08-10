#ifndef CPPBASICS_SCENE_HPP
#define CPPBASICS_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "gobject.hpp"
#include "textures.hpp"

class Scene {
public:

    Scene();

    virtual ~Scene() {}

    virtual void processEvent(const sf::Event& event) = 0;

    virtual void update(sf::Time delta) = 0;

    virtual void render() = 0;

    static Scene* create();

protected:
    Rectangle boundingBox() const;

    void move(GameObject& object, Point2D vector);

    void detectCollision(GameObject& object1, GameObject& object2);

    void draw(const GameObject& object);

    void fitInto(GameObject& object);

protected:
    sf::RenderWindow window;
    TextureManager textureManager;
private:
    float width;
    float height;
};

#endif // CPPBASICS_SCENE_HPP
