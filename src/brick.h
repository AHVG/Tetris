/*

0000
####
0000
0000

0000
000#
####
0000

0000
#000
####
0000

##
##

0000
0##0
##00

0000
##00
0##0

000
###
0#0

*/

#ifndef _H_BRICK
#define _H_BRICK

#include <SFML/Graphics.hpp>

#include <vector>


class Brick {

private:

    sf::RectangleShape shape;
    sf::Vector2f position;
    std::vector<int> matrix;

    int size;

public:

    Brick();
    ~Brick();

    void go_right();
    void go_left();

    void rotate_clockwise();

    void accelerate();
    void decelerate();

    void update();
    void draw_at(sf::RenderWindow *window);

};

#endif