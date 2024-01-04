#include <SFML/Graphics.hpp>

#include <iostream>

#include "app.h"


App::App() {
    window = new sf::RenderWindow(sf::VideoMode(250, 500), "Tetris");
}

App::~App() {
    delete window;
}

void App::handle_event() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            test_brick.handle_key_pressed(event.key.code);
        } else if (event.type == sf::Event::KeyReleased) {
            test_brick.handle_key_released(event.key.code);
        }
    }
}

void App::handle_update() {
    sf::Time deltaTime = clock.restart();
    float delta = deltaTime.asSeconds();
    test_brick.update(delta);
}

void App::handle_render() {
    window->clear();
    test_brick.draw_at(window);
    window->display();
}

void App::run() {
    while (window->isOpen()) {
        handle_event();
        handle_update();
        handle_render();
    }
}
