#include "game.hpp"

void collisionLoop(Circle player, Circle consumable[], bool consumed[], int size) {
    for (int i = 0; i < size; ++i) {
        if (!consumed[i]) {
            consumed[i] = collision(player, consumable[i]);
        }
    }
}