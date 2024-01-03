#include <SFML/Graphics.hpp>

#include "app.h"


App::App() {
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "Tetris");
    
    shape = new sf::CircleShape(100.f);
    shape->setFillColor(sf::Color::Green);
}

App::~App() {
    delete window;
    delete shape;
}

void App::handle_event() {
    sf::Event event;

    while (window->pollEvent(event)) {
        
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}

void App::handle_update() {}

void App::handle_render() {
    window->clear();
    window->draw(*shape);
    window->display();
}

void App::run() {

    while (window->isOpen()) {
        handle_event();
        handle_update();
        handle_render();
    }
}
