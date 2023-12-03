#ifndef CPPBASICS_CONSTANTS_HPP
#define CPPBASICS_CONSTANTS_HPP

const float RADIUS = 40.0f;
const float CONSUMABLE_RADIUS = 20.0f;
const float ENEMY_RADIUS = 60.0f;

const float SPEED = 150.0f;

const float WINDOW_WIDTH  = 800.0f;
const float WINDOW_HEIGHT = 600.0f;

const float SCENE_WIDTH  = 800.0f;
const float SCENE_HEIGHT = 600.0f;

const float NORTH_BORDER = 0.0f;
const float WEST_BORDER  = 0.0f;
const float EAST_BORDER  = WEST_BORDER + SCENE_WIDTH;
const float SOUTH_BORDER = NORTH_BORDER + SCENE_HEIGHT;

const float PLAYER_START_X = 400.0f;
const float PLAYER_START_Y = 300.0f;

const float CONSUMABLE_START_X = 600.0f;
const float CONSUMABLE_START_Y = 150.0f;

const float ENEMY_START_X = 100.0f;
const float ENEMY_START_Y = 450.0f;

const float CONSUMABLE_WARNED_MULTIPLIER = 6.0f;

#endif // CPPBASICS_CONSTANTS_HPP
