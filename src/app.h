#ifndef _H_APP
#define _H_APP

#include <SFML/Graphics.hpp>

#include "brick.h"
#include "wall.h"


class App {

private:

    void handleEvent();
    void handleUpdate();
    void handleRender();

    sf::RenderWindow *window;
    sf::Clock clock;
    Brick test_brick;
    Wall wall;

public:

    App();
    ~App();

    void run();

};

#endif