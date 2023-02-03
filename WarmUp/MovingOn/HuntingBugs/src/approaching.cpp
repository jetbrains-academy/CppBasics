#include "scene.hpp"

void approachingLoop(Circle player, Circle consumable[], bool concerned[], int size) {
    for (int i = 0; i <= size; ++i) {
        float dist = distance(player.center, consumable[i].center);
        float warnDist = 3 * player.radius + consumable[i].radius;
        if (concerned[i] = false) {
            concerned[i] = dist < warnDist;
        }
    }
}
