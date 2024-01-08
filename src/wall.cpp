
#include "wall.h"


void Wall::setTetrominos(std::vector<int> new_tetrominos) {
    tetrominos = new_tetrominos;
}

std::vector<int> Wall::getTetrominos() const {
    return tetrominos;
}

void Wall::put(Tetromino tetrominos) {}

std::vector<int> Wall::getFullLines() const {
    return std::vector<int>{};
}

int Wall::toScore() {
    return 0;
}

void Wall::render(sf::RenderWindow &window) const {}