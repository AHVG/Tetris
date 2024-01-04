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

#include "wall.h"

class Wall;

class Brick {

private:

    sf::RectangleShape shape;
    sf::Vector2f position;
    std::vector<int> matrix;
    Wall *wall;

    int size;
    float elapsed_time;
    float time_when_accelerate;
    float time_when_decelerate;
    float current_time;

public:

    Brick();
    ~Brick();

    sf::Vector2f get_position() const;
    std::vector<int> get_matrix() const;
    int get_size() const;

    void set_wall(Wall *_wall);

    void go_right();
    void go_left();

    void rotate_clockwise();
    void rotate_anticlockwise();

    void accelerate();
    void decelerate();

    void handle_key_pressed(sf::Keyboard::Key key_pressed);
    void handle_key_released(sf::Keyboard::Key key_released);

    void update(float delta);
    void draw_at(sf::RenderWindow *window);

};

#endif