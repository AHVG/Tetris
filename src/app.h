#ifndef _H_APP
#define _H_APP

#include <SFML/Graphics.hpp>


class App {

private:

    void handle_event();
    void handle_update();
    void handle_render();

    sf::CircleShape *shape;
    sf::RenderWindow *window;

public:

    App();
    ~App();

    void run();

};

#endif