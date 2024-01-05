#ifndef _H_APP
#define _H_APP

#include <SFML/Graphics.hpp>

#include "brick.h"
#include "wall.h"
#include "movement_behavior.h"


class App {

private:

    void handleEvent();
    void handleUpdate();
    void handleRender();

    sf::RenderWindow *window;
    sf::Clock clock;
    Brick test_brick;
    Wall wall;
    MovementBehavior movement_behavior;

public:

    App();
    ~App();

    void run();

};

#endif