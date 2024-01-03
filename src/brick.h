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


class Brick {

private:

    sf::RectangleShape *shape;

public:

    Brick();
    ~Brick();

    void go_right();
    void go_left();

    void rotate_right();
    void rotate_left();

    void accelerate();
    void decelerate();

    void update();
    void draw_at(sf::RenderWindow *window);

};

#endif