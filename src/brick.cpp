
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
    
    time_when_decelerate = 1.0;
    time_when_accelerate = time_when_decelerate / 20.0;
    current_time = time_when_decelerate;
}

Brick::~Brick() {
    delete brick_generator;
}

void Brick::handleKeyPressed(sf::Keyboard::Key key_pressed) {
    if (key_pressed == sf::Keyboard::Up) {
        movement_behavior->tryRotateClockwise();
    } else if (key_pressed == sf::Keyboard::Right) {
        movement_behavior->tryGoRight(1);
    } else if (key_pressed == sf::Keyboard::Left) {
        movement_behavior->tryGoLeft(1);
    } else if (key_pressed == sf::Keyboard::Down) {
        movement_behavior->accelerate();
    }
}

void Brick::handleKeyReleased(sf::Keyboard::Key key_released) {
    if (key_released == sf::Keyboard::Down) {
        movement_behavior->decelerate();
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

float Brick::getTimeWhenAccelerate() {
    return time_when_accelerate;
}

float Brick::getTimeWhenDecelerate() {
    return time_when_decelerate;
}

float Brick::getCurrentTime() {
    return current_time;
}

MovementBehavior *Brick::getMovementbehavior() {
    return movement_behavior;
}

void Brick::setShape(sf::RectangleShape _shape) {
    shape = _shape;
}

void Brick::setPosition(sf::Vector2f _position) {
    position = _position;
}

void Brick::setMatrix(std::vector<int> _matrix) {
    matrix = _matrix;
}

void Brick::setSize(int _size) {
    size = _size;
}

void Brick::setTimeWhenAccelerate(float _time_when_accelerate) {
    time_when_accelerate = _time_when_accelerate;
}

void Brick::setTimeWhenDecelerate(float _time_when_decelerate) {
    time_when_decelerate = _time_when_decelerate;
}

void Brick::setCurrentTime(float _current_time) {
    current_time = _current_time;
}

void Brick::setMovementBehavior(MovementBehavior *_movement_behavior) {
    movement_behavior = _movement_behavior;
}

void Brick::update(float delta) {
    movement_behavior->update(delta);
}

void Brick::reset() {
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(brick_size, brick_size));

    std::pair<std::vector<int>, int> matrix_and_size = brick_generator->generate();

    matrix = matrix_and_size.first;
    size = matrix_and_size.second;

    position = sf::Vector2f(0, 0);

}

void Brick::drawAt(sf::RenderWindow *window) {
    for (long unsigned int i = 0; i < matrix.size(); i++) {
        if (matrix[i]) {
            shape.setPosition(sf::Vector2f(position.x * brick_size, position.y * brick_size) + sf::Vector2f((i % size) * brick_size, (i / size) * brick_size));
            window->draw(shape);
        }
    }
}
