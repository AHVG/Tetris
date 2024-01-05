#ifndef _H_WALL
#define _H_WALL

#include <SFML/Graphics.hpp>

#include <vector>

#include "brick.h"

class Brick;


class Wall {

private:

    std::vector<int> bricks;

public:

    Wall();
    ~Wall();

    int collided(Brick *brick);
    int collidesWithOtherBricks(Brick *brick);
    int crossedTheLimit(Brick *brick);

    void put(Brick *brick);
    int isThereCompleteLine();
    int toScore();

    void drawAt(sf::RenderWindow *window);
};


#endif