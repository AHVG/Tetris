#include "tetromino.h"


void Tetromino::setPosition(sf::Vector2i new_position) {
    position = new_position;
}

void Tetromino::setMatrix(std::vector<int> new_matrix) {
    matrix = new_matrix;
}

void Tetromino::setSize(int new_size) {
    size = new_size;
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

void Tetromino::render(sf::RenderWindow &window) const {
    
}