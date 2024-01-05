#include <SFML/Graphics.hpp>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "wall.h"
#include "constants.h"


Wall::Wall() {
    for (int i = 0; i < width * height; i++) {
        bricks.push_back(0);
    }
}

Wall::~Wall() {}

int Wall::collided(Brick *brick) {
    return crossedTheLimit(brick) || collidesWithOtherBricks(brick);
}

int Wall::crossedTheLimit(Brick *brick) {
    sf::Vector2f brick_position = brick->getPosition();
    std::vector<int> brick_matrix = brick->getMatrix();


    for (unsigned long int i = 0; i < brick_matrix.size(); i++) {
        sf::Vector2f relative_position(i % brick->getSize(), i / brick->getSize());
        sf::Vector2f real_position = relative_position + brick_position;

        if ((real_position.x < 0 || real_position.x >= width || real_position.y < 0 || real_position.y >= height) &&
            (brick_matrix[i])) {
            return 1;
        }
    }

    return 0;
}

int Wall::collidesWithOtherBricks(Brick *brick) {
    sf::Vector2f brick_position = brick->getPosition();
    std::vector<int> brick_matrix = brick->getMatrix();

    for (unsigned long int i = 0; i < brick_matrix.size(); i++) {
        sf::Vector2f relative_position(i % brick->getSize(), i / brick->getSize());
        sf::Vector2f real_position = relative_position + brick_position;

        if (real_position.x < 0 || real_position.x >= width || real_position.y < 0 || real_position.y >= height) {
            continue;
        }

        if (bricks[real_position.x + real_position.y * width] && brick_matrix[i]) {
            return 1;
        }
    }

    return 0;
}

void Wall::put(Brick *brick) {
    sf::Vector2f brick_position = brick->getPosition();
    std::vector<int> brick_matrix = brick->getMatrix();

    for (unsigned long int i = 0; i < brick_matrix.size(); i++) {
        sf::Vector2f relative_position(i % brick->getSize(), i / brick->getSize());
        sf::Vector2f real_position = relative_position + brick_position;
        
        if (real_position.x < 0 || real_position.x >= width || real_position.y < 0 || real_position.y >= height) {
            continue;
        }

        if (brick_matrix[i]) {
            bricks[real_position.x + real_position.y * width] = 1;
        }
    }
}

std::vector<int> Wall::getCompleteLine() {
    std::vector<int> lines;

    for (int i = 0; i < height; i++) {
        int number_of_elements_with_one = 0;

        for (int j = 0; j < width; j++) {
            if (bricks[i * width + j]) {
                number_of_elements_with_one++;
            } else {
                break;
            }
        }

        if (number_of_elements_with_one == width) {
            lines.push_back(i);
        }
    }

    return lines;
}

int Wall::toScore() {
    std::vector<int> lines;
    lines = getCompleteLine();

    for (unsigned long int i = 0; i < lines.size(); i++) {
        int line = lines[i];
    
        for (int k = line; k > 0; k--) {

            for (int j = 0; j < width; j++) {
                bricks[k * width + j] = bricks[(k - 1) * width + j];
            }
        }
    }

    return lines.size();
}

void Wall::update(float delta) {
    toScore();
}

void Wall::drawAt(sf::RenderWindow *window) {
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(brick_size, brick_size));

    for (long unsigned int i = 0; i < bricks.size(); i++) {
        if (bricks[i]) {
            shape.setPosition(sf::Vector2f((float(i % int(width))) * brick_size, (int(i / int(width))) * brick_size));
            window->draw(shape);
        }
    }
}