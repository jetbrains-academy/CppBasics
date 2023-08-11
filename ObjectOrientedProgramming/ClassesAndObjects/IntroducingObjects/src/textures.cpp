#include "textures.hpp"

#include <iostream>

const char* getTextureFilename(GameTextureID id) {
    switch (id) {
        case GameTextureID::SPACE:
            return "resources/space.png";
        case GameTextureID::PLANET:
            return "resources/planet.png";
        case GameTextureID::PLANET_DEAD:
            return "resources/planetDead.png";
        case GameTextureID::STAR:
            return "resources/star.png";
        case GameTextureID::STAR_CONCERNED:
            return "resources/starConcerned.png";
        case GameTextureID::BLACKHOLE:
            return "resources/blackhole.png";
        default:
            return "";
    }
}

bool TextureManager::initialize() {
    for (size_t i = 0; i < SIZE; ++i) {
        GameTextureID id = static_cast<GameTextureID>(i);
        const char* filename = getTextureFilename(id);
        sf::Texture* texture = &textures[i];
        if (!texture->loadFromFile(filename)) {
            std::cerr << "Could not open file " << filename << "\n";
            return false;
        }
        if (id == GameTextureID::SPACE) {
            texture->setRepeated(true);
        }
    }
    return true;
}

const sf::Texture* TextureManager::getTexture(GameTextureID id) const {
    return &textures[static_cast<size_t>(id)];
}