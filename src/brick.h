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

    sf::Vector2f getPosition();
    std::vector<int> getMatrix();
    int getSize();

    void setWall(Wall *_wall);

    void goRight();
    void goLeft();

    void rotateClockwise();
    void rotateAnticlockwise();

    void accelerate();
    void decelerate();

    void handleKeyPressed(sf::Keyboard::Key key_pressed);
    void handleKeyReleased(sf::Keyboard::Key key_released);

    void update(float delta);
    void drawAt(sf::RenderWindow *window);

    void reset();

};

#endif