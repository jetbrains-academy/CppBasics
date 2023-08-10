#ifndef CPPBASICS_TEXTURES_HPP
#define CPPBASICS_TEXTURES_HPP

#include <cstddef>

#include <SFML/Graphics/Texture.hpp>

enum class GameTextureID {
    SPACE,
    PLANET,
    STAR,
    BLACK_HOLE,
    SIZE
};

class TextureManager {
public:
    bool initialize();

    const sf::Texture* getTexture(GameTextureID id);
private:
    static const size_t SIZE = static_cast<size_t>(GameTextureID::SIZE);

    sf::Texture textures[SIZE];

};

#endif // CPPBASICS_TEXTURES_HPP
