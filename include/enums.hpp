#ifndef CPPBASICS_ENUMS_HPP
#define CPPBASICS_ENUMS_HPP

enum class SceneID {
    STATIC_GAME_FIELD,
    DYNAMIC_GAME_FIELD,
};

/**
* The enumeration represents the IDs of textures used in the game.
* These IDs are used to identify specific textures when loading or rendering game graphics.
*/
enum class GameTextureID {
    SPACE,
    PLANET,
    PLANET_DEAD,
    STAR,
    STAR_CONCERNED,
    BLACKHOLE,
    SIZE
};

/**
 * This enumeration is used to categorize different kinds of game objects.
 * Each game object can have one of the following kinds - PLAYER, CONSUMABLE, or ENEMY.
 * The kind of a game object can be used to determine its behavior or interaction with the game.
 */
enum class GameObjectKind {
    PLAYER, CONSUMABLE, ENEMY
};

/**
 * Represents the status of a game object.
 *   - NORMAL - represents a status of an alive object in its normal state.
 *   - WARNED - represents a status of an alive object when it is in some dangerous situation,
 *      the exact meaning of which depends on the particular kind of the object.
 *   - DESTROYED - represents a status of a destroyed object.
 */
 enum class GameObjectStatus {
    NORMAL, WARNED, DESTROYED,
};

#endif // CPPBASICS_ENUMS_HPP
