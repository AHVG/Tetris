#include <SFML/Graphics.hpp>
#include <iostream>

#include "circle.hpp"


int main() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        hello_world(window);
        window.display();
    }


    return 0;
}