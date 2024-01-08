
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

const float WINDOW_WIDTH = TETROMINO_SIZE * WALL_WIDTH + 500;
const float WINDOW_HEIGHT = TETROMINO_SIZE * WALL_HEIGHT + 150;

const float MARGIN_X = 250;
const float MARGIN_Y = 50;

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
