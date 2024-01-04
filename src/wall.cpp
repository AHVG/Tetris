#include <SFML/Graphics.hpp>

#include <stdexcept>
#include <vector>

#include "wall.h"
#include "constants.h"


Wall::Wall() {
    std::vector<int> aux(width * height, 0);
    bricks = aux;
}

Wall::~Wall() {}

int Wall::crossed_the_line(Brick &brick) const {
    sf::Vector2f brick_position = brick.get_position();
    std::vector<int> brick_matrix = brick.get_matrix();

    for (unsigned long int i = 0; i < brick_matrix.size(); i++) {
        sf::Vector2f relative_position(i % brick.get_size(), i / brick.get_size());
        sf::Vector2f real_position = relative_position + brick_position;

        if ((real_position.x < 0 || real_position.x >= width || real_position.y < 0 || real_position.y >= height) &&
            (brick_matrix[i])) {
            return 1;
        }
    }

    return 0;
}

int Wall::collides_with_other_bricks(Brick &brick) const {
    sf::Vector2f brick_position = brick.get_position();
    std::vector<int> brick_matrix = brick.get_matrix();

    for (unsigned long int i = 0; i < brick_matrix.size(); i++) {
        sf::Vector2f relative_position(i % brick.get_size(), i / brick.get_size());
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

void Wall::draw_at(sf::RenderWindow *window) {
    throw std::logic_error("TODO: Wall::draw_at");
}