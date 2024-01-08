
#include "tetromino.h"
#include "constants.h"


Tetromino::Tetromino() {}

Tetromino::~Tetromino() {}

void Tetromino::setShape(sf::RectangleShape new_shape) {
    shape = new_shape;
}

void Tetromino::setPosition(sf::Vector2i new_position) {
    position = new_position;
}

void Tetromino::setMatrix(std::vector<int> new_matrix) {
    matrix = new_matrix;
}

void Tetromino::setSize(int new_size) {
    size = new_size;
}

sf::RectangleShape Tetromino::getShape() const {
    return shape;
}

sf::Vector2i Tetromino::getPosition() const {
    return position;
}

std::vector<int> Tetromino::getMatrix() const {
    return matrix;
}

int Tetromino::getSize() const {
    return size;
}

void Tetromino::move(sf::Vector2i value) {
    position += value;
}

void Tetromino::moveUp() {
    move(sf::Vector2i(0, -1));
}

void Tetromino::moveDown() {
    move(sf::Vector2i(0, 1));
}

void Tetromino::moveLeft() {
    move(sf::Vector2i(-1, 0));
}

void Tetromino::moveRight() {
    move(sf::Vector2i(1, 0));
}

void Tetromino::rotateClockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        aux[(getSize() - i / getSize() - 1) + (i % getSize()) * getSize()] = matrix[i];
    }

    setMatrix(aux);
}

void Tetromino::rotateAnticlockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        aux[(i / getSize()) + (getSize() - i % getSize() - 1) * getSize()] = matrix[i];
    }

    setMatrix(aux);
}

void Tetromino::render(sf::RenderWindow &window) {
    for (long unsigned int i = 0; i < matrix.size(); i++) {
        if (matrix[i]) {
            shape.setPosition(sf::Vector2f(position.x * TETROMINO_SIZE,
             position.y * TETROMINO_SIZE) + sf::Vector2f((i % size) * TETROMINO_SIZE, (i / size) * TETROMINO_SIZE));
            window.draw(shape);
        }
    }
}