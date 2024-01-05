#ifndef _H_WALL
#define _H_WALL

#include <SFML/Graphics.hpp>

#include <vector>

#include "brick.h"
#include "entity.h"

class Brick;


class Wall : public Entity{

private:

    std::vector<int> bricks;

public:

    Wall();
    ~Wall();

    int collided(Brick *brick);
    int collidesWithOtherBricks(Brick *brick);
    int crossedTheLimit(Brick *brick);

    void put(Brick *brick);
    std::vector<int> getCompleteLine();
    int toScore();

    void update(float delta);
    void drawAt(sf::RenderWindow *window);
};


#endif