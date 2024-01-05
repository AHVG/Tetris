
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
    time_when_accelerate = time_when_decelerate / 20.0;
    current_time = time_when_decelerate;
}

Brick::~Brick() {}

void Brick::handleKeyPressed(sf::Keyboard::Key key_pressed) {
    if (key_pressed == sf::Keyboard::Up) {
        tryRotateClockwise();
    } else if (key_pressed == sf::Keyboard::Right) {
        tryGoRight(1);
    } else if (key_pressed == sf::Keyboard::Left) {
        tryGoLeft(1);
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

int Brick::tryGoRight(int steps) {
    for (int i = 0; i < steps; i++) {
        goRight();
    }

    if (wall->collided(this)) {
        
        for (int i = 0; i < steps; i++) {
            goLeft();
        }

        return 0;
    }

    return 1;
}

int Brick::tryGoLeft(int steps) {
    for (int i = 0; i < steps; i++) {
        goLeft();
    }

    if (wall->collided(this)) {
        
        for (int i = 0; i < steps; i++) {
            goRight();
        }

        return 0;
    }

    return 1;
}

void Brick::goUp() {
    position.y--;
}

void Brick::goDown() {
    position.y++;
}

int Brick::tryGoUp(int steps) {
    for (int i = 0; i < steps; i++) {
        goUp();
    }

    if (wall->collided(this)) {
        
        for (int i = 0; i < steps; i++) {
            goDown();
        }

        return 0;
    }

    return 1;
}

int Brick::tryGoDown(int steps) {
    for (int i = 0; i < steps; i++) {
        goDown();
    }

    if (wall->collided(this)) {
        
        for (int i = 0; i < steps; i++) {
            goUp();
        }

        return 0;
    }

    return 1;
}

void Brick::rotateClockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        aux[(size - i / size - 1) + (i % size) * size] = matrix[i];
    }

    matrix = aux;
}

void Brick::rotateAnticlockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        aux[(i / size) + (size - i % size - 1) * size] = matrix[i];
    }

    matrix = aux;
}

int Brick::tryRotateClockwise() {
    int done;
    rotateClockwise();

    if (wall->collided(this)) {
        
        for (int i = 1; i < size / 2 + 1; i++) {
            done = tryGoRight(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < size / 2 + 1; i++) {
            done = tryGoLeft(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < size / 2 + 1; i++) {
            done = tryGoUp(i);
            
            if (done) {
                return 1;
            }
        }

        rotateAnticlockwise();
    }

    return 0;
}

int Brick::tryRotateAnticlockwise() {
    int done;
    rotateAnticlockwise();

    if (wall->collided(this)) {
        
        for (int i = 1; i < size / 2 + 1; i++) {
            done = tryGoRight(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < size / 2 + 1; i++) {
            done = tryGoLeft(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < size / 2 + 1; i++) {
            done = tryGoUp(i);
            
            if (done) {
                return 1;
            }
        }

        rotateClockwise();
    }

    return 0;
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

        goDown();

        if (wall->collided(this)) {
            goUp();
            wall->put(this);
            wall->toScore();
            reset();
        }
    }
}

void Brick::reset() {
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(brick_size, brick_size));

    std::vector<int> aux(9, 0);
    matrix = aux;

    matrix[3] = 1;
    matrix[4] = 1;
    matrix[5] = 1;
    matrix[6] = 1;

    position = sf::Vector2f(0, 0);

    size = 3;
    
    elapsed_time = 0.0;
}

void Brick::drawAt(sf::RenderWindow *window) {
    for (long unsigned int i = 0; i < matrix.size(); i++) {
        if (matrix[i]) {
            shape.setPosition(sf::Vector2f(position.x * brick_size, position.y * brick_size) + sf::Vector2f((i % size) * brick_size, (i / size) * brick_size));
            window->draw(shape);
        }
    }
}
