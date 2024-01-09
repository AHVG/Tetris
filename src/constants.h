#ifndef _H_CONSTANTS
#define _H_CONSTANTS

#include <SFML/Graphics.hpp>


extern const std::vector<std::vector<int>> TETROMINOS_MATRIX;
extern const std::vector<int> TETROMINOS_MATRIX_SIZES;
extern const std::vector<sf::Vector2i> TETROMINOS_INITIAL_POSITION;
extern const std::vector<sf::Color> TETROMINOS_COLOR;

extern const sf::Vector2f NEXT_TETROMINO_POSITION;
extern const sf::Vector2f SAVED_TETROMINO_POSITION;

extern const float TETROMINO_SIZE;
extern const float TETROMINO_GAP;

extern const float WALL_WIDTH;
extern const float WALL_HEIGHT;
extern const float WALL_GAP;

extern const float WINDOW_WIDTH;
extern const float WINDOW_HEIGHT;

extern const float MARGIN_X;
extern const float MARGIN_Y;

extern const char *WALL_AROUND[23];

#endif