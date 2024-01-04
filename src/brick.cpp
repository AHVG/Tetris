
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

    position = sf::Vector2f(10, 10);

    size = 3;

    rotate_clockwise();

}

Brick::~Brick() {}

void Brick::go_right() {
    throw std::logic_error("TODO");
}

void Brick::go_left() {
    throw std::logic_error("TODO");
}

void Brick::rotate_clockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        aux[(size - i / size - 1) + (i % size) * size] = matrix[i];
    }

    matrix = aux;
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
        shape.setPosition(sf::Vector2f(position.x * brick_size, position.y * brick_size) + sf::Vector2f((i % size) * brick_size, (i / size) * brick_size));
        
        if (matrix[i]) {
            shape.setFillColor(sf::Color::Green);
        } else {
            shape.setFillColor(sf::Color::Blue);
        }

        window->draw(shape);
    }
}
