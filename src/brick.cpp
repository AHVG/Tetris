
#include <SFML/Graphics.hpp>

#include <stdexcept>
#include <iostream>

#include "brick.h"
#include "constants.h"


Brick::Brick() {

    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(brick_size, brick_size));

    for (int i = 0; i < 16; i++) {
        matrix.push_back(0);
    }

    matrix[4] = 1;
    matrix[5] = 1;
    matrix[6] = 1;
    matrix[7] = 1;

    position = sf::Vector2f(0, 0);

    size = 4;
    
    elapsed_time = 0.0;
    time_when_decelerate = 1.0;
    time_when_accelerate = time_when_decelerate / 6.0;
    current_time = time_when_decelerate;
}

Brick::~Brick() {}

void Brick::handleKeyPressed(sf::Keyboard::Key key_pressed) {
    if (key_pressed == sf::Keyboard::Up) {
        rotateAnticlockwise();
    } else if (key_pressed == sf::Keyboard::Right) {
        goRight();
    
        if (wall->crossedTheLimit(this)) {
            goLeft();
        }
    } else if (key_pressed == sf::Keyboard::Left) {
        goLeft();

        if (wall->crossedTheLimit(this)) {
            goRight();
        }
    } else if (key_pressed == sf::Keyboard::Down) {
        accelerate();
    }
}

void Brick::handleKeyReleased(sf::Keyboard::Key key_released) {
    if (key_released == sf::Keyboard::Down) {
        decelerate();
    }
}

sf::Vector2f Brick::getPosition() {
    return position;
}

std::vector<int> Brick::getMatrix() {
    return matrix;
}

int Brick::getSize() {
    return size;
}

void Brick::setWall(Wall *_wall) {
    wall = _wall;
}

void Brick::goRight() {
    position.x++;
}

void Brick::goLeft() {
    position.x--;
}

void Brick::rotateClockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) { // Se não der a rotação, voltar uma casa para cima ou para lado direito ou para lado esquerdo
        aux[(size - i / size - 1) + (i % size) * size] = matrix[i];
    }

    matrix = aux;
}

void Brick::rotateAnticlockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) { // Se não der a rotação, voltar uma casa para cima ou para lado direito ou para lado esquerdo
        aux[(i / size) + (size - i % size - 1) * size] = matrix[i];
    }

    matrix = aux;
}

void Brick::accelerate() {
    current_time = time_when_accelerate;
}

void Brick::decelerate() {
    current_time = time_when_decelerate;
}

void Brick::update(float delta) {
    elapsed_time += delta;
    
    if (elapsed_time > current_time) {
        elapsed_time = 0;

        position.y++;

        if (wall->crossedTheLimit(this) || wall->collidesWithOtherBricks(this)) {
            position.y--;
            wall->put(this);
            reset();
        }
    }
}

void Brick::reset() {
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(brick_size, brick_size));

    std::vector<int> aux(9, 0);
    matrix = aux;

    matrix[1] = 1;
    matrix[3] = 1;
    matrix[4] = 1;
    matrix[5] = 1;

    position = sf::Vector2f(0, 0);

    size = 3;
    
    elapsed_time = 0.0;
    time_when_decelerate = 1.0;
    time_when_accelerate = time_when_decelerate / 6.0;
    current_time = time_when_decelerate;
}

void Brick::drawAt(sf::RenderWindow *window) {
    for (long unsigned int i = 0; i < matrix.size(); i++) {
        
        if (matrix[i]) {
            shape.setPosition(sf::Vector2f(position.x * brick_size, position.y * brick_size) + sf::Vector2f((i % size) * brick_size, (i / size) * brick_size));
            window->draw(shape);
        }
    }
}
