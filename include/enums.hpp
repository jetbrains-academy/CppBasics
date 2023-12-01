#ifndef CPPBASICS_ENUMS_HPP
#define CPPBASICS_ENUMS_HPP


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
 *   - CONCERNED - represents a status of an alive object when it is in some dangerous situation,
 *      the exact meaning of which depends on the particular kind of the object.
 *   - DESTROYED - represents a status of a destroyed object.
 */
 enum class GameObjectStatus {
    NORMAL, CONCERNED, DESTROYED,
};

#endif // CPPBASICS_ENUMS_HPP
