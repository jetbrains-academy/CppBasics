#ifndef CPPBASICS_ENUMS_HPP
#define CPPBASICS_ENUMS_HPP

enum class GameObjectStatus {
    NORMAL, CONCERNED, DESTROYED,
};

enum class GameObjectKind {
    PLAYER, CONSUMABLE, ENEMY
};

#endif // CPPBASICS_ENUMS_HPP
