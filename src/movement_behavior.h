#ifndef _H_MOVEMENT_BEHAVIOR
#define _H_MOVEMENT_BEHAVIOR

#include "wall.h"
#include "brick.h"

class Brick;
class Wall;


class MovementBehavior {

private:

    Wall *wall;
    Brick *brick;
    float elapsed_time;

public:

    MovementBehavior();
    ~MovementBehavior();

    void setWall(Wall *_wall);
    void setBrick(Brick *brick);

    void goRight();
    void goLeft();
    void goUp();
    void goDown();
    void rotateClockwise();
    void rotateAnticlockwise();

    int tryGoRight(int steps);
    int tryGoLeft(int steps);
    int tryGoUp(int steps);
    int tryGoDown(int steps);
    int tryRotateClockwise();
    int tryRotateAnticlockwise();

    void accelerate();
    void decelerate();

    void update(float delta);

};

#endif