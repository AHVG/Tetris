
#include <iostream>

#include "game.h"
#include "constants.h"


Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris") {
    first_exchange = 1;
    exchanged = 0;
    score = 0;

    current_tetromino = tetromino_generator.generate();
    next_tetromino = tetromino_generator.generate();

    if (!font.loadFromFile("./src/fonts/Minecraft.ttf")) {
        return;
    }

    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
}

Game::~Game() {
}

int Game::tryRotateClockwiseTetromino() {
    int done;
    current_tetromino.rotateClockwise();

    if (wall.collide(current_tetromino)) {
        
        for (int i = 1; i < current_tetromino.getSize() / 2 + 1; i++) {
            done = tryMoveRightTetromino(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < current_tetromino.getSize() / 2 + 1; i++) {
            done = tryMoveLeftTetromino(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < current_tetromino.getSize() / 2 + 1; i++) {
            done = tryMoveUpTetromino(i);
            
            if (done) {
                return 1;
            }
        }

        current_tetromino.rotateAnticlockwise();
    }

    return 0;
}

int Game::tryRotateAnticlockwiseTetromino() {
    int done;
    current_tetromino.rotateAnticlockwise();

    if (wall.collide(current_tetromino)) {
        
        for (int i = 1; i < current_tetromino.getSize() / 2 + 1; i++) {
            done = tryMoveRightTetromino(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < current_tetromino.getSize() / 2 + 1; i++) {
            done = tryMoveLeftTetromino(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < current_tetromino.getSize() / 2 + 1; i++) {
            done = tryMoveUpTetromino(i);
            
            if (done) {
                return 1;
            }
        }

        current_tetromino.rotateClockwise();
    }

    return 0;
}

int Game::tryMoveUpTetromino(int steps) {
    for (int i = 0; i < steps; i++) {
        current_tetromino.moveUp();
    }

    if (wall.collide(current_tetromino)) {
        
        for (int i = 0; i < steps; i++) {
            current_tetromino.moveDown();
        }

        return 0;
    }

    return 1;
}

int Game::tryMoveLeftTetromino(int steps) {
    for (int i = 0; i < steps; i++) {
        current_tetromino.moveLeft();
    }

    if (wall.collide(current_tetromino)) {
        
        for (int i = 0; i < steps; i++) {
            current_tetromino.moveRight();
        }

        return 0;
    }

    return 1;
}

int Game::tryMoveRightTetromino(int steps) {
    for (int i = 0; i < steps; i++) {
        current_tetromino.moveRight();
    }

    if (wall.collide(current_tetromino)) {
        
        for (int i = 0; i < steps; i++) {
            current_tetromino.moveLeft();
        }

        return 0;
    }

    return 1;
}

int Game::tryMoveDownTetromino(int steps) {
    for (int i = 0; i < steps; i++) {
        current_tetromino.moveDown();
    }
    
    if (wall.collide(current_tetromino)) {
        
        for (int i = 0; i < steps; i++) {
            current_tetromino.moveUp();
        }

        return 0;
    }

    return 1;
}

void Game::hardDropTetromino() {
    while (tryMoveDownTetromino(1));
    elapsed_time = 10000; // Gambiarra para atualizar na hora
}

void Game::accelerateTetromino() {}

void Game::decelerateTetromino() {}

void Game::changeTetromino() {
    if (exchanged) {
        return;
    }

    if (first_exchange) {
        saved_tetromino = current_tetromino;
        current_tetromino = next_tetromino;
        next_tetromino = tetromino_generator.generate();
        first_exchange = 0;
    } else {
        Tetromino aux;
        aux = current_tetromino;
        current_tetromino = saved_tetromino;
        saved_tetromino = aux;
    }
    
    exchanged = 1;
    current_tetromino.setPosition(sf::Vector2i(4, 0));
}

void Game::generateTetromino() {
    current_tetromino = next_tetromino;
    next_tetromino = tetromino_generator.generate();
    
    if (wall.collide(current_tetromino)) {
        window.close();
    }
}

void Game::toScore() {
    wall.put(current_tetromino);
    score += wall.toScore();
}

void Game::renderNextTetromino() {
    sf::RectangleShape shape = next_tetromino.getShape();
    std::vector<int> matrix = next_tetromino.getMatrix();

    sf::Vector2f pos = NEXT_TETROMINO_POSITION - sf::Vector2f((float(next_tetromino.getSize()) / 2.0 * TETROMINO_SIZE), (float(next_tetromino.getSize()) / 2.0 * TETROMINO_SIZE));
    
    for (unsigned long int i = 0; i < matrix.size(); i++) {
        if (matrix[i]) {
            shape.setPosition(sf::Vector2f((i % next_tetromino.getSize()) * TETROMINO_SIZE, (i / next_tetromino.getSize()) * TETROMINO_SIZE) + 
                              pos);
            window.draw(shape);
        }
    }

    text.setString("Next");

    sf::FloatRect textRect = text.getLocalBounds();
    text.setPosition(NEXT_TETROMINO_POSITION - sf::Vector2f(textRect.width/2.0f, 2.5 * TETROMINO_SIZE));

    window.draw(text);
}

void Game::renderSavedTetromino() {
    if (first_exchange) {
        return;
    }


    sf::RectangleShape shape = saved_tetromino.getShape();
    std::vector<int> matrix = saved_tetromino.getMatrix();

    sf::Vector2f pos = SAVED_TETROMINO_POSITION - sf::Vector2f((float(saved_tetromino.getSize()) / 2.0 * TETROMINO_SIZE), (float(saved_tetromino.getSize()) / 2.0 * TETROMINO_SIZE));
    
    for (unsigned long int i = 0; i < matrix.size(); i++) {
        if (matrix[i]) {
            shape.setPosition(sf::Vector2f((i % saved_tetromino.getSize()) * TETROMINO_SIZE, (i / saved_tetromino.getSize()) * TETROMINO_SIZE) + 
                              pos);
            window.draw(shape);
        }
    }

    text.setString("Hold");

    sf::FloatRect textRect = text.getLocalBounds();
    text.setPosition(SAVED_TETROMINO_POSITION - sf::Vector2f(textRect.width/2.0f, 2.5 * TETROMINO_SIZE));

    window.draw(text);
}

void Game::renderScore() {

    text.setString(std::to_string(score));

    sf::FloatRect textRect = text.getLocalBounds();
    text.setPosition(SCORE_POSITION - sf::Vector2f(textRect.width/2.0f, 0.0));

    window.draw(text);

    text.setString("Score");

    textRect = text.getLocalBounds();
    text.setPosition(SCORE_POSITION - sf::Vector2f(textRect.width/2.0f, 25.0));

    window.draw(text);

}

void Game::handleEvent() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                tryRotateClockwiseTetromino();
            } else if (event.key.code == sf::Keyboard::Right) {
                tryMoveRightTetromino(1);
            } else if (event.key.code == sf::Keyboard::Left) {
                tryMoveLeftTetromino(1);
            } else if (event.key.code == sf::Keyboard::Down) {
                accelerateTetromino();
            } else if (event.key.code == sf::Keyboard::Space) {
                hardDropTetromino();
            } else if (event.key.code == sf::Keyboard::C) {
                changeTetromino();
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Down) {
                decelerateTetromino();
            }
        }
    }
}

void Game::handleUpdate() {
    sf::Time deltaTime = clock.restart();
    float delta = deltaTime.asSeconds();

    elapsed_time += delta;

    if (elapsed_time > 1) {
        elapsed_time = 0;

        if(!tryMoveDownTetromino(1)) {
            toScore();
            generateTetromino();
            exchanged = 0;
        }
    }
}

void Game::handleRender() {
    window.clear();

    wall.render(window);

    renderNextTetromino();
    renderSavedTetromino();
    current_tetromino.render(window);
    
    renderScore();

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        handleEvent();
        handleUpdate();
        handleRender();
    }
}
