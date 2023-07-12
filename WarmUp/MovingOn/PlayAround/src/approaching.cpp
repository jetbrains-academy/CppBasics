#include "game.hpp"

void approachingLoop(Circle player, Circle consumable[], bool concerned[], int size) {
    for (int i = 0; i < size; ++i) {
        float dist = distance(player.center, consumable[i].center);
        float warnDist = 3 * player.radius + consumable[i].radius;
        concerned[i] = dist < warnDist;
    }
}
