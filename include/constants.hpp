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

// Leaderboard constants

const float INPUTBOX_WIDTH = 400.0f;
const float INPUTBOX_HEIGHT = 50.0f;

const unsigned int INPUTNAME_FONT_SIZE = 36;

const float MAX_PLAYER_NAME_LENGTH = 16.0f;

const float MAX_LINES = 10.0f;

const unsigned int HEADER_FONT_SIZE = 40;
const float HEADER_X = 300.0f;
const float HEADER_Y = 40.0f;

const unsigned int LEADERBOARD_FONT_SIZE = 26;
const float POS_HEADER_X = 108.0f;
const float POS_HEADER_Y = HEADER_Y + 61.0f;
const float NAME_HEADER_X = 330.0f;
const float NAME_HEADER_Y = HEADER_Y + 61.0f;
const float SCORE_HEADER_X = 593.0f;
const float SCORE_HEADER_Y = HEADER_Y + 61.0f;

const float PADDING = 8.0f;
const float LEADERBOARD_WIDTH = 600.0f;
const float ROW_HEIGHT = LEADERBOARD_FONT_SIZE + PADDING * 2.0f;
const float LEADERBOARD_X = SCENE_WIDTH / 2.0f - LEADERBOARD_WIDTH / 2.0f;
const float LEADERBOARD_Y = HEADER_Y + 60.0f;

const float ONE_DIGIT_POS_OFFSET = 14.0f;
const float TWO_DIGIT_POS_OFFSET = 19.0f;
const float NAME_X_OFFSET = 60.0f;
const float ONE_DIGIT_SCORE_OFFSET = 520.0f;
const float FOUR_DIGIT_SCORE_OFFSET = 505.0f;
const float FIVE_DIGIT_SCORE_OFFSET = 500.0f;

const float BORDER_OFFSET = 3.0f;

#endif // CPPBASICS_CONSTANTS_HPP
