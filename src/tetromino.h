#ifndef _H_TETROMINO
#define _H_TETROMINO

#include <SFML/Graphics.hpp>


class Tetromino {

private:

    sf::Vector2i position;
    std::vector<int> matrix;
    int size;

public:

    void setPosition(sf::Vector2i new_position);
    void setMatrix(std::vector<int> new_matrix);
    void setSize(int new_size);

    sf::Vector2i getPosition() const;
    std::vector<int> getMatrix() const;
    int getSize() const;

    void move(sf::Vector2i value);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void rotateClockwise();
    void rotateAnticlockwise();

    void render(sf::RenderWindow &window) const;

};


#endif