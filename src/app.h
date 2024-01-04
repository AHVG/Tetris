#ifndef _H_APP
#define _H_APP

#include <SFML/Graphics.hpp>

#include "brick.h"
#include "wall.h"


class App {

private:

    void handle_event();
    void handle_update();
    void handle_render();

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