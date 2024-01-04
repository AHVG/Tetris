#ifndef _H_APP
#define _H_APP

#include <SFML/Graphics.hpp>

#include "brick.h"


class App {

private:

    void handle_event();
    void handle_update();
    void handle_render();

    sf::RenderWindow *window;
    sf::Clock clock;
    Brick test_brick;

public:

    App();
    ~App();

    void run();

};

#endif