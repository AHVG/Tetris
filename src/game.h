#ifndef _H_APP
#define _H_APP

#include <SFML/Graphics.hpp>


class Game {

private:

    void handleEvent();
    void handleUpdate();
    void handleRender();

    sf::RenderWindow *window;
    sf::Clock clock;

public:

    Game();
    ~Game();

    void run();

};

#endif