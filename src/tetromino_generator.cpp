
#include <random>
#include <utility>

#include "tetromino_generator.h"
#include "constants.h"


Tetromino TetrominoGenerator::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, TETROMINOS_MATRIX.size() - 1);
    int chosen_tetromino = distrib(gen);

    Tetromino generated_tetromino;

    sf::RectangleShape tetromino_shape;
    tetromino_shape.setSize(sf::Vector2f(TETROMINO_SIZE - TETROMINO_GAP, TETROMINO_SIZE - TETROMINO_GAP));
    tetromino_shape.setFillColor(TETROMINOS_COLOR[chosen_tetromino]);

    generated_tetromino.setShape(tetromino_shape);
    generated_tetromino.setMatrix(TETROMINOS_MATRIX[chosen_tetromino]);
    generated_tetromino.setSize(TETROMINOS_MATRIX_SIZES[chosen_tetromino]);
    generated_tetromino.setPosition(sf::Vector2i(0, 0));

    return generated_tetromino;
}
