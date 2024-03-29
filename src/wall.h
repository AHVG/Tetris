#ifndef _H_WALL
#define _H_WALL

#include <SFML/Graphics.hpp>

#include <vector>

#include "tetromino.h"


class Wall {

private:

    std::vector<int> tetrominos;

public:

    Wall();
    ~Wall();

    void setTetrominos(std::vector<int> new_bricks);

    std::vector<int> getTetrominos() const;

    void put(Tetromino tetromino);

    std::vector<int> getFullLines() const;
    int toScore();

    int collide(Tetromino tetromino);
    int collidesWithOtherTetrominos(Tetromino tetromino);
    int crossedTheLimit(Tetromino tetromino);
    
    void reset();

    void render(sf::RenderWindow &window);

};

#endif