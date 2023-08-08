#ifndef CPPBASICS_TEXTURES_HPP
#define CPPBASICS_TEXTURES_HPP

#include <SFML/Graphics/Texture.hpp>

enum GameTexture {
    BACKGROUND_T
};

class TextureManager {
public:
    sf::Texture* getTexture();
};

#endif // CPPBASICS_TEXTURES_HPP
