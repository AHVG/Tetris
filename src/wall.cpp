
#include <iostream>

#include "wall.h"
#include "constants.h"


Wall::Wall() {
    for (int i = 0; i < WALL_WIDTH * WALL_HEIGHT; i++) {
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

void Wall::put(Tetromino tetromino) {
    sf::Vector2i tetromino_position = tetromino.getPosition();
    std::vector<int> tetromino_matrix = tetromino.getMatrix();

    for (unsigned long int i = 0; i < tetromino_matrix.size(); i++) {
        sf::Vector2i relative_position(i % tetromino.getSize(), i / tetromino.getSize());
        sf::Vector2i real_position = relative_position + tetromino_position;
        
        if (real_position.x < 0 || real_position.x >= WALL_WIDTH || real_position.y < 0 || real_position.y >= WALL_HEIGHT) {
            continue;
        }

        if (tetromino_matrix[i]) {
            tetrominos[real_position.x + real_position.y * WALL_WIDTH] = tetromino_matrix[i];
        }
    }
}

std::vector<int> Wall::getFullLines() const {
    std::vector<int> lines;

    for (int i = 0; i < WALL_HEIGHT; i++) {
        int number_of_elements_with_one = 0;

        for (int j = 0; j < WALL_WIDTH; j++) {
            if (tetrominos[i * WALL_WIDTH + j]) {
                number_of_elements_with_one++;
            } else {
                break;
            }
        }

        if (number_of_elements_with_one == WALL_WIDTH) {
            lines.push_back(i);
        }
    }

    return lines;
}

int Wall::toScore() {
    std::vector<int> lines;
    lines = getFullLines();

    for (unsigned long int i = 0; i < lines.size(); i++) {
        int line = lines[i];
    
        for (int k = line; k > 0; k--) {

            for (int j = 0; j < WALL_WIDTH; j++) {
                tetrominos[k * WALL_WIDTH + j] = tetrominos[(k - 1) * WALL_WIDTH + j];
            }
        }
    }

    return lines.size();
}

int Wall::crossedTheLimit(Tetromino tetromino) {
    sf::Vector2i tetromino_position = tetromino.getPosition();
    std::vector<int> tetromino_matrix = tetromino.getMatrix();


    for (unsigned long int i = 0; i < tetromino_matrix.size(); i++) {
        sf::Vector2i relative_position(i % tetromino.getSize(), i / tetromino.getSize());
        sf::Vector2i real_position = relative_position + tetromino_position;

        if ((real_position.x < 0 || real_position.x >= WALL_WIDTH || real_position.y < 0 || real_position.y >= WALL_HEIGHT) &&
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

        if (real_position.x < 0 || real_position.x >= WALL_WIDTH || real_position.y < 0 || real_position.y >= WALL_HEIGHT) {
            continue;
        }

        if (tetrominos[real_position.x + real_position.y * WALL_WIDTH] && tetromino_matrix[i]) { 
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
    shape.setSize(sf::Vector2f(TETROMINO_SIZE - TETROMINO_GAP, TETROMINO_SIZE - TETROMINO_GAP));

    shape.setFillColor(sf::Color(156, 31, 46));
    
    for (int line = 0; line < 23; line++) {
        for (int column = 0; column < 24; column++) {
            if(WALL_AROUND[line][column] == '#') {
                shape.setPosition(sf::Vector2f(column * TETROMINO_SIZE, line * TETROMINO_SIZE) + 
                                sf::Vector2f(MARGIN_X - 7 * TETROMINO_SIZE, MARGIN_Y) + sf::Vector2f(TETROMINO_GAP, TETROMINO_GAP));
                window.draw(shape);
            }
        }
    }

    for (long unsigned int i = 0; i < tetrominos.size(); i++) {
        if (tetrominos[i]) {
            shape.setFillColor(TETROMINOS_COLOR[tetrominos[i] - 1]);
            shape.setPosition(sf::Vector2f((float(i % int(WALL_WIDTH))) * TETROMINO_SIZE, (int(i / int(WALL_WIDTH))) * TETROMINO_SIZE) + 
                              sf::Vector2f(MARGIN_X, MARGIN_Y) + sf::Vector2f(TETROMINO_GAP, TETROMINO_GAP));
            window.draw(shape);
        }
    }
}