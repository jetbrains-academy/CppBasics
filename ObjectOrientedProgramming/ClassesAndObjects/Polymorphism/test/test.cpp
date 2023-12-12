#include <gtest/gtest.h>

#include <iostream>

#include "gobject.hpp"
#include "textures.hpp"

#include "testscene.hpp"
#include "testing.hpp"

testing::Environment* const env =
    testing::AddGlobalTestEnvironment(new TestEnvironment);

const float MIN = -10e3;
const float MAX = 10e3;

const Rectangle generateArea = { { MIN, MIN }, { MAX, MAX } };

TEST(PlayerObjectTest, GetTextureTest) {
    TextureManager textureManager = TextureManager();
    bool init = textureManager.initialize();
    ASSERT_TRUE(init) << "Internal error: failed to initialize texture manager";

    TestPlayerObject object = TestPlayerObject();

    object.performSetStatus(GameObjectStatus::NORMAL);
    const sf::Texture* normalTexture = object.getTexture(textureManager);
    ASSERT_EQ(textureManager.getTexture(GameTextureID::PLANET), normalTexture)
            << "Texture of player object in GameObjectStatus::NORMAL status is not equal to GameTextureID::PLANET";

    object.performSetStatus(GameObjectStatus::WARNED);
    const sf::Texture* warnedTexture = object.getTexture(textureManager);
    ASSERT_EQ(textureManager.getTexture(GameTextureID::PLANET), warnedTexture)
            << "Texture of player object in GameObjectStatus::WARNED status is not equal to GameTextureID::PLANET";

    object.performSetStatus(GameObjectStatus::DESTROYED);
    const sf::Texture* destroyedTexture = object.getTexture(textureManager);
    ASSERT_EQ(textureManager.getTexture(GameTextureID::PLANET_DEAD), destroyedTexture)
            << "Texture of player object in GameObjectStatus::DESTROYED status is not equal to GameTextureID::PLANET_DEAD";
}

TEST(ConsumableObjectTest, GetTextureTest) {
    TextureManager textureManager = TextureManager();
    bool init = textureManager.initialize();
    ASSERT_TRUE(init) << "Internal error: failed to initialize texture manager";

    TestConsumableObject object = TestConsumableObject();

    object.performSetStatus(GameObjectStatus::NORMAL);
    const sf::Texture* normalTexture = object.getTexture(textureManager);
    ASSERT_EQ(textureManager.getTexture(GameTextureID::STAR), normalTexture)
            << "Texture of consumable object in GameObjectStatus::NORMAL status is not equal to GameTextureID::STAR";

    object.performSetStatus(GameObjectStatus::WARNED);
    const sf::Texture* warnedTexture = object.getTexture(textureManager);
    ASSERT_EQ(textureManager.getTexture(GameTextureID::STAR_CONCERNED), warnedTexture)
            << "Texture of consumable object in GameObjectStatus::WARNED status is not equal to GameTextureID::STAR_CONCERNED";

    object.performSetStatus(GameObjectStatus::DESTROYED);
    const sf::Texture* destroyedTexture = object.getTexture(textureManager);
    ASSERT_EQ(nullptr, destroyedTexture)
            << "Texture of consumable object in GameObjectStatus::DESTROYED status is not equal to nullptr";
}