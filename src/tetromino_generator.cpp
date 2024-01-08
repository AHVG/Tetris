
#include <random>
#include <utility>

#include "tetromino_generator.h"
#include "constants.h"


Tetromino TetrominoGenerator::generate() {
    std::vector<std::pair<std::vector<int>, int>> tetrominos;

    tetrominos.push_back(std::make_pair(std::vector<int>{0, 1, 0, 1, 1, 1, 0, 0, 0}, 3));
    tetrominos.push_back(std::make_pair(std::vector<int>{1, 0, 0, 1, 1, 1, 0, 0, 0}, 3));
    tetrominos.push_back(std::make_pair(std::vector<int>{0, 0, 1, 1, 1, 1, 0, 0, 0}, 3));
    tetrominos.push_back(std::make_pair(std::vector<int>{1, 1, 1, 1}, 2));
    tetrominos.push_back(std::make_pair(std::vector<int>{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 4));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, tetrominos.size() - 1);
    int chosen_brick = distrib(gen);

    Tetromino generated_tetromino;

    sf::RectangleShape tetromino_shape;
    tetromino_shape.setSize(sf::Vector2f(TETROMINO_SIZE, TETROMINO_SIZE));
    tetromino_shape.setFillColor(sf::Color::Green);

    generated_tetromino.setShape(tetromino_shape);
    generated_tetromino.setMatrix(tetrominos[chosen_brick].first);
    generated_tetromino.setSize(tetrominos[chosen_brick].second);
    generated_tetromino.setPosition(sf::Vector2i(0, 0));

    return generated_tetromino;
}
