#ifndef _H_ENTITY
#define _H_ENTITY

#include <SFML/Graphics.hpp>


class Entity {

private:

public:

    virtual void update(float delta) = 0;
    virtual void drawAt(sf::RenderWindow *window) = 0;

};

#endif