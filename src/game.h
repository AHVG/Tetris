#ifndef _H_APP
#define _H_APP

#include <SFML/Graphics.hpp>

#include "tetromino_generator.h"
#include "tetromino.h"
#include "wall.h"


class Game {

private:

    void handleEvent();
    void handleUpdate();
    void handleRender();

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Font font;
    sf::Text text;

    TetrominoGenerator tetromino_generator;

    Tetromino current_tetromino;
    Tetromino next_tetromino;
    Tetromino saved_tetromino;

    Wall wall;

    int first_exchange;
    int exchanged;

    float elapsed_time_to_accelerate;
    float elapsed_time;
    float time_when_accelerate;
    float time_when_decelerate;
    float current_time;

    int score;

    int tryRotateClockwiseTetromino();
    int tryRotateAnticlockwiseTetromino();
    int tryMoveUpTetromino(int steps);
    int tryMoveLeftTetromino(int steps);
    int tryMoveRightTetromino(int steps);
    int tryMoveDownTetromino(int steps);

    void hardDropTetromino();
    void accelerateTetromino();
    void decelerateTetromino();

    void changeTetromino();
    void generateTetromino();
    void toScore();
    void updateTime(float delta);

    void renderNextTetromino();
    void renderSavedTetromino();

    void renderScore();

public:

    Game();
    ~Game();

    void run();

};

#endif