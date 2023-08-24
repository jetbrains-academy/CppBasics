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

    void run();

    static Scene* create();

protected:

    virtual void initialize() = 0;

    void processInput();

    virtual void processEvent(const sf::Event& event) = 0;

    virtual void update(sf::Time delta) = 0;

    void render();

    virtual void draw() = 0;

    void close();

    Rectangle boundingBox() const;

    void setPosition(GameObject& object, Point2D position);

    void move(GameObject& object, sf::Time delta);

    void move(GameObject& object, Point2D vector);

    void fitInto(GameObject& object);

    void detectCollision(GameObject& object1, GameObject& object2);

    sf::Sprite background() const;

    void draw(const GameObject& object);

private:
    sf::RenderWindow window;
    TextureManager textureManager;
    float width;
    float height;
    bool active;
};

#endif // CPPBASICS_SCENE_HPP
