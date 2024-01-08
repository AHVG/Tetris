
#include <iostream>

#include "wall.h"
#include "constants.h"


Wall::Wall() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        tetrominos.push_back(0);
    }
}

Wall::~Wall() {}

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

int Wall::crossedTheLimit(Tetromino tetromino) {
    sf::Vector2i tetromino_position = tetromino.getPosition();
    std::vector<int> tetromino_matrix = tetromino.getMatrix();


    for (unsigned long int i = 0; i < tetromino_matrix.size(); i++) {
        sf::Vector2i relative_position(i % tetromino.getSize(), i / tetromino.getSize());
        sf::Vector2i real_position = relative_position + tetromino_position;

        if ((real_position.x < 0 || real_position.x >= WIDTH || real_position.y < 0 || real_position.y >= HEIGHT) &&
            (tetromino_matrix[i])) {
            return 1;
        }
    }

    return 0;
}

int Wall::collidesWithOtherTetrominos(Tetromino tetromino) {
    sf::Vector2i tetromino_position = tetromino.getPosition();
    std::vector<int> tetromino_matrix = tetromino.getMatrix();

    
    for (unsigned long int i = 0; i < tetromino_matrix.size(); i++) {
        sf::Vector2i relative_position(i % tetromino.getSize(), i / tetromino.getSize());
        sf::Vector2i real_position = relative_position + tetromino_position;

        if (real_position.x < 0 || real_position.x >= WIDTH || real_position.y < 0 || real_position.y >= HEIGHT) {
            continue;
        }


        if (tetrominos[real_position.x + real_position.y * WIDTH] && tetromino_matrix[i]) { 
            return 1;
        }
    }


    return 0;
}

int Wall::collide(Tetromino tetromino) {
    return crossedTheLimit(tetromino) || collidesWithOtherTetrominos(tetromino);
}

void Wall::render(sf::RenderWindow &window) {
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(TETROMINO_SIZE, TETROMINO_SIZE));

    for (long unsigned int i = 0; i < tetrominos.size(); i++) {
        if (tetrominos[i]) {
            shape.setPosition(sf::Vector2f((float(i % int(WIDTH))) * TETROMINO_SIZE, (int(i / int(WIDTH))) * TETROMINO_SIZE));
            window.draw(shape);
        }
    }
}