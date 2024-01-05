
#include <SFML/Graphics.hpp>

#include <vector>

#include "movement_behavior.h"
#include "brick.h"
#include "wall.h"


MovementBehavior::MovementBehavior() {}

MovementBehavior::~MovementBehavior() {}

void MovementBehavior::setWall(Wall *_wall) {
    wall = _wall;
}

void MovementBehavior::setBrick(Brick *_brick) {
    brick = _brick;
}

void MovementBehavior::goRight() {
    brick->setPosition(brick->getPosition() + sf::Vector2f(1, 0));
}

void MovementBehavior::goLeft() {
    brick->setPosition(brick->getPosition() + sf::Vector2f(-1, 0));
}

void MovementBehavior::goUp() {
    brick->setPosition(brick->getPosition() + sf::Vector2f(0, -1));
}

void MovementBehavior::goDown() {
    brick->setPosition(brick->getPosition() + sf::Vector2f(0, 1));
}

void MovementBehavior::rotateClockwise() {
    std::vector<int> matrix = brick->getMatrix();
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        aux[(brick->getSize() - i / brick->getSize() - 1) + (i % brick->getSize()) * brick->getSize()] = matrix[i];
    }

    brick->setMatrix(aux);
}

void MovementBehavior::rotateAnticlockwise() {
    std::vector<int> matrix = brick->getMatrix();
    std::vector<int> aux(matrix.size(), 0);

    for (long unsigned int i = 0; i < matrix.size(); i++) {
        aux[(i / brick->getSize()) + (brick->getSize() - i % brick->getSize() - 1) * brick->getSize()] = matrix[i];
    }

    brick->setMatrix(aux);
}

int MovementBehavior::tryGoRight(int steps) {
    for (int i = 0; i < steps; i++) {
        goRight();
    }

    if (wall->collided(brick)) {
        
        for (int i = 0; i < steps; i++) {
            goLeft();
        }

        return 0;
    }

    return 1;
}

int MovementBehavior::tryGoLeft(int steps) {
    for (int i = 0; i < steps; i++) {
        goLeft();
    }

    if (wall->collided(brick)) {
        
        for (int i = 0; i < steps; i++) {
            goRight();
        }

        return 0;
    }

    return 1;
}

int MovementBehavior::tryGoUp(int steps) {
    for (int i = 0; i < steps; i++) {
        goUp();
    }

    if (wall->collided(brick)) {
        
        for (int i = 0; i < steps; i++) {
            goDown();
        }

        return 0;
    }

    return 1;
}

int MovementBehavior::tryGoDown(int steps) {
    for (int i = 0; i < steps; i++) {
        goDown();
    }

    if (wall->collided(brick)) {
        
        for (int i = 0; i < steps; i++) {
            goUp();
        }

        return 0;
    }

    return 1;
}

int MovementBehavior::tryRotateClockwise() {
    int done;
    rotateClockwise();

    if (wall->collided(brick)) {
        
        for (int i = 1; i < brick->getSize() / 2 + 1; i++) {
            done = tryGoRight(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < brick->getSize() / 2 + 1; i++) {
            done = tryGoLeft(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < brick->getSize() / 2 + 1; i++) {
            done = tryGoUp(i);
            
            if (done) {
                return 1;
            }
        }

        rotateAnticlockwise();
    }

    return 0;
}

int MovementBehavior::tryRotateAnticlockwise() {
    int done;
    rotateAnticlockwise();

    if (wall->collided(brick)) {
        
        for (int i = 1; i < brick->getSize() / 2 + 1; i++) {
            done = tryGoRight(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < brick->getSize() / 2 + 1; i++) {
            done = tryGoLeft(i);
            
            if (done) {
                return 1;
            }
        }

        for (int i = 1; i < brick->getSize() / 2 + 1; i++) {
            done = tryGoUp(i);
            
            if (done) {
                return 1;
            }
        }

        rotateClockwise();
    }

    return 0;
}

void MovementBehavior::accelerate() {
    brick->setCurrentTime(brick->getTimeWhenAccelerate());
}

void MovementBehavior::decelerate() {
    brick->setCurrentTime(brick->getTimeWhenDecelerate());
}

void MovementBehavior::update(float delta) {
    elapsed_time += delta;
    
    if (elapsed_time > brick->getCurrentTime()) {
        elapsed_time = 0;

        if (!tryGoDown(1)) {
            wall->put(brick);
            wall->toScore();
            brick->reset();
        }
    }
}
