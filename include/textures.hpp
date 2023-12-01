#ifndef CPPBASICS_TEXTURES_HPP
#define CPPBASICS_TEXTURES_HPP

#include <cstddef>

#include <SFML/Graphics/Texture.hpp>

#include "enums.hpp"

/**
 * The TextureManager class manages the loading and retrieval of textures for the game.
 */
class TextureManager {
public:

    /**
     * Initializes the texture manager.
     *
     * @return true if the initialization was successful, false otherwise.
     */
    bool initialize();

    /**
     * Get the texture associated with the specified game texture ID.
     *
     * @param id The ID of the game texture to retrieve.
     * @return The texture associated with the specified game texture ID.
     *
     * @note this method does not transfer the ownership of the texture object,
     *  since the texture manager itself is the owner of all the textures.
     */
    const sf::Texture* getTexture(GameTextureID id) const;

private:
    static const size_t SIZE = static_cast<size_t>(GameTextureID::SIZE);
    sf::Texture textures[SIZE];
};

#endif // CPPBASICS_TEXTURES_HPP
