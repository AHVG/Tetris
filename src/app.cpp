#include <SFML/Graphics.hpp>

#include <iostream>

#include "app.h"


App::App() {
    window = new sf::RenderWindow(sf::VideoMode(250, 500), "Tetris");
    
    movement_behavior.setWall(&wall);
    movement_behavior.setBrick(&test_brick);
    test_brick.setMovementBehavior(&movement_behavior);
}

App::~App() {
    delete window;
}

void App::handleEvent() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            test_brick.handleKeyPressed(event.key.code);
        } else if (event.type == sf::Event::KeyReleased) {
            test_brick.handleKeyReleased(event.key.code);
        }
    }
}

void App::handleUpdate() {
    sf::Time deltaTime = clock.restart();
    float delta = deltaTime.asSeconds();

    test_brick.update(delta);
    wall.update(delta);
}

void App::handleRender() {
    window->clear();

    test_brick.drawAt(window);
    wall.drawAt(window);

    window->display();
}

void App::run() {
    while (window->isOpen()) {
        handleEvent();
        handleUpdate();
        handleRender();
    }
}
