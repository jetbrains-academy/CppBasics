#ifndef CPPBASICS_SCENE_HPP
#define CPPBASICS_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "gobject.hpp"
#include "textures.hpp"

class Scene {
public:

    Scene();

    virtual ~Scene() = default;

    void run();

    static Scene* create();

protected:

    virtual void initialize() = 0;

    void close();

    void processInput();

    virtual void processEvent(const sf::Event& event) = 0;

    void setObjectPosition(GameObject& object, Point2D position);

    void move(GameObject& object, Point2D vector);

    void move(GameObject& object, sf::Time delta);

    void fitInto(GameObject& object);

    Rectangle getBoundingBox() const;

    void detectCollision(GameObject& object1, GameObject& object2);

    virtual void update(sf::Time delta) = 0;

    void render();

    void draw(const GameObject& object);

    virtual void draw() = 0;

    sf::Sprite background() const;

private:
    sf::RenderWindow window;
    TextureManager textureManager;
    float width;
    float height;
    bool active;
};

#endif // CPPBASICS_SCENE_HPP
