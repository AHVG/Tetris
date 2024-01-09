
#include "constants.h"


const std::vector<std::vector<int>> TETROMINOS_MATRIX{std::vector<int>{1, 0, 0, 1, 1, 0, 1, 0, 0},
                                                      std::vector<int>{0, 2, 2, 0, 2, 0, 0, 2, 0},
                                                      std::vector<int>{0, 3, 0, 0, 3, 0, 0, 3, 3},
                                                      std::vector<int>{4, 4, 4, 4},
                                                      std::vector<int>{0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                                                      std::vector<int>{0, 0, 6, 0, 6, 6, 0, 6, 0},
                                                      std::vector<int>{7, 0, 0, 7, 7, 0, 0, 7, 0}};
const std::vector<int> TETROMINOS_MATRIX_SIZES{3, 3, 3, 2, 4, 3, 3};
const std::vector<sf::Color> TETROMINOS_COLOR{sf::Color(128, 0, 128),
                                              sf::Color(0, 0, 255),
                                              sf::Color(255, 165, 0),
                                              sf::Color(255, 255, 0),
                                              sf::Color(0, 255, 255),
                                              sf::Color(255, 0, 0),
                                              sf::Color(0, 255, 0)};


const float TETROMINO_SIZE = 25.0;
const float TETROMINO_GAP = 0.0;

const float WALL_WIDTH = 10;
const float WALL_HEIGHT = 20;
const float WALL_GAP = 0.0;

const float WINDOW_WIDTH = TETROMINO_SIZE * WALL_WIDTH + 450;
const float WINDOW_HEIGHT = TETROMINO_SIZE * WALL_HEIGHT + 75;

const float MARGIN_X = 225;
const float MARGIN_Y = 0.0;

const sf::Vector2f NEXT_TETROMINO_POSITION{WINDOW_WIDTH - 4.5 * TETROMINO_SIZE, MARGIN_Y + 4.5 * TETROMINO_SIZE};
const sf::Vector2f SAVED_TETROMINO_POSITION{4.5 * TETROMINO_SIZE, MARGIN_Y + 4.5 * TETROMINO_SIZE};

const char *WALL_AROUND[23] = {
    "#########          #########",
    "#########          #########",
    "##     ##          ##     ##",
    "##     ##          ##     ##",
    "##     ##          ##     ##",
    "##     ##          ##     ##",
    "##     ##          ##     ##",
    "#########          #########",
    "#########          #########",
    "##     ##          #########",
    "##     ##          #########",
    "#########          #########",
    "#########          #########",
    "#########          #########",
    "#########          #########",
    "#########          #########",
    "#########          #########",
    "#########          #########",
    "#########          #########",
    "#########          #########",
    "############################",
    "############################",
    "############################"
};
