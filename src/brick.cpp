
#include <SFML/Graphics.hpp>

#include <stdexcept>
#include <iostream>

#include "brick.h"
#include "constants.h"


Brick::Brick() {

    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(brick_size, brick_size));

    for (int i = 0; i < 9; i++)
        matrix.push_back(0);

    matrix[1] = 1;
    matrix[3] = 1;
    matrix[4] = 1;
    matrix[5] = 1;

    position = sf::Vector2f(262.5, 262.5);

    size = 3;

}

Brick::~Brick() {}

void Brick::go_right() {
    throw std::logic_error("TODO");
}

void Brick::go_left() {
    throw std::logic_error("TODO");
}

void Brick::rotate_clockwise() {
    throw std::logic_error("TODO");
}

void Brick::accelerate() {
    throw std::logic_error("TODO");
}

void Brick::decelerate() {
    throw std::logic_error("TODO");
}

void Brick::update() {
    throw std::logic_error("TODO");
}

void Brick::draw_at(sf::RenderWindow *window) {
    for (long unsigned int i = 0; i < matrix.size(); i++) {
        if (matrix[i]) {
            shape.setPosition(position + sf::Vector2f((i % size) * brick_size, static_cast<int>(i / size) * brick_size));
            window->draw(shape);
        }    
    }
}
