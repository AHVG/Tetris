
#include <random>
#include <utility>

#include "tetromino_generator.h"
#include "constants.h"


Tetromino TetrominoGenerator::generate() {
    std::vector<std::vector<int>> tetrominos_matrix{std::vector<int>{0, 1, 0, 1, 1, 1, 0, 0, 0},
                                                    std::vector<int>{1, 0, 0, 1, 1, 1, 0, 0, 0},
                                                    std::vector<int>{0, 0, 1, 1, 1, 1, 0, 0, 0},
                                                    std::vector<int>{1, 1, 1, 1},
                                                    std::vector<int>{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<int> tetrominos_sizes{3, 3, 3, 2, 4};
    std::vector<sf::Color> tetrominos_color{sf::Color::Red, sf::Color::Blue, sf::Color::Cyan, sf::Color::Green, sf::Color::Magenta};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, tetrominos_matrix.size() - 1);
    int chosen_tetromino = distrib(gen);

    Tetromino generated_tetromino;

    sf::RectangleShape tetromino_shape;
    tetromino_shape.setSize(sf::Vector2f(TETROMINO_SIZE - TETROMINO_GAP, TETROMINO_SIZE - TETROMINO_GAP));
    tetromino_shape.setFillColor(tetrominos_color[chosen_tetromino]);

    generated_tetromino.setShape(tetromino_shape);
    generated_tetromino.setMatrix(tetrominos_matrix[chosen_tetromino]);
    generated_tetromino.setSize(tetrominos_sizes[chosen_tetromino]);
    generated_tetromino.setPosition(sf::Vector2i(0, 0));

    return generated_tetromino;
}
