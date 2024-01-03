
#include <SFML/Graphics.hpp>

#include <stdexcept>

#include "brick.h"


Brick::Brick() {
    shape = new sf::RectangleShape(sf::Vector2f(10, 10));
    shape->setFillColor(sf::Color::Green);
}

Brick::~Brick() {
    delete shape;
}

void Brick::go_right() {
    throw std::logic_error("TODO");
}

void Brick::go_left() {
    throw std::logic_error("TODO");
}

void Brick::rotate_right() {
    throw std::logic_error("TODO");
}

void Brick::rotate_left() {
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
    window->draw(*shape);
}
