
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

void Brick::handle_key_pressed(sf::Keyboard::Key key_pressed) {
    if (key_pressed == sf::Keyboard::Up) {
        rotate_anticlockwise();
    } else if (key_pressed == sf::Keyboard::Right) {
        go_right();
    
        if (wall->crossed_the_line(*this)) {
            go_left();
        }
    } else if (key_pressed == sf::Keyboard::Left) {
        go_left();

        if (wall->crossed_the_line(*this)) {
            go_right();
        }
    } else if (key_pressed == sf::Keyboard::Down) {
        accelerate();
    }
}

void Brick::handle_key_released(sf::Keyboard::Key key_released) {
    if (key_released == sf::Keyboard::Down) {
        decelerate();
    }
}

sf::Vector2f Brick::get_position() const {
    return position;
}

std::vector<int> Brick::get_matrix() const {
    return matrix;
}

int Brick::get_size() const {
    return size;
}

void Brick::set_wall(Wall *_wall) {
    wall = _wall;
}

void Brick::go_right() {
    position.x++;
}

void Brick::go_left() {
    position.x--;
}

void Brick::rotate_clockwise() {
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) { // Se não der a rotação, voltar uma casa para cima ou para lado direito ou para lado esquerdo
        aux[(size - i / size - 1) + (i % size) * size] = matrix[i];
    }

    matrix = aux;
}

void Brick::rotate_anticlockwise() {
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

        if (wall->crossed_the_line(*this)) {
            position.y --;
        }
    }
}

void Brick::draw_at(sf::RenderWindow *window) {
    for (long unsigned int i = 0; i < matrix.size(); i++) {
        
        if (matrix[i]) {
            shape.setPosition(sf::Vector2f(position.x * brick_size, position.y * brick_size) + sf::Vector2f((i % size) * brick_size, (i / size) * brick_size));
            window->draw(shape);
        }
    }
}
