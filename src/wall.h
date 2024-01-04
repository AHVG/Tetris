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

    int collides_with_other_bricks(Brick &brick) const;
    int crossed_the_line(Brick &brick) const;

    void draw_at(sf::RenderWindow *window);
};


#endif