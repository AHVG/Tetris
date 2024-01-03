
#include "circle.hpp"


void hello_world(sf::RenderWindow &window) {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    window.draw(shape);
}