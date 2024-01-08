#ifndef _H_CONSTANTS
#define _H_CONSTANTS

#include <SFML/Graphics.hpp>

// Arrumar isso aq
const std::vector<std::vector<int>> TETROMINOS_MATRIX{std::vector<int>{0, 1, 0, 1, 1, 1, 0, 0, 0},
                                                std::vector<int>{2, 0, 0, 2, 2, 2, 0, 0, 0},
                                                std::vector<int>{0, 0, 3, 3, 3, 3, 0, 0, 0},
                                                std::vector<int>{4, 4, 4, 4},
                                                std::vector<int>{0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                                                std::vector<int>{6, 6, 0, 0, 6, 6, 0, 0, 0},
                                                std::vector<int>{0, 7, 7, 7, 7, 0, 0, 0, 0}};
const std::vector<int> TETROMINOS_MATRIX_SIZES{3, 3, 3, 2, 4, 3, 3};
const std::vector<sf::Color> TETROMINOS_COLOR{sf::Color(128, 0, 128),
                                              sf::Color(0, 0, 255),
                                              sf::Color(255, 165, 0),
                                              sf::Color(255, 255, 0),
                                              sf::Color(0, 255, 255),
                                              sf::Color(255, 0, 0),
                                              sf::Color(0, 255, 0)};

const float TETROMINO_SIZE = 25.0;
const float TETROMINO_GAP = 3.0;

const float WALL_WIDTH = 10;
const float WALL_HEIGHT = 20;

const float WINDOW_WIDTH = TETROMINO_SIZE * WALL_WIDTH + 400;
const float WINDOW_HEIGHT = TETROMINO_SIZE * WALL_HEIGHT + 400;

const float MARGIN = 200;

#endif