
#include "game.h"
#include "constants.h"


Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris");
}

Game::~Game() {
    delete window;
}

void Game::handleEvent() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}

void Game::handleUpdate() {
    sf::Time deltaTime = clock.restart();
    float delta = deltaTime.asSeconds();
}

void Game::handleRender() {
    window->clear();

    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        handleEvent();
        handleUpdate();
        handleRender();
    }
}
