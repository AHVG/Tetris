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

    sf::RenderWindow *window;
    sf::Clock clock;

    TetrominoGenerator tetromino_generator;

    Tetromino current_tetromino;
    Tetromino next_tetromino;
    Tetromino saved_tetromino;

    Wall wall;

    // Encapsular numa classe? Pode ser, mas fica tão simples aqui
    int tryRotateClockwiseTetromino();
    int tryRotateAnticlockwiseTetromino();
    int tryMoveUpTetromino(int steps);
    int tryMoveLeftTetromino(int steps);
    int tryMoveRightTetromino(int steps);
    int tryMoveDownTetromino(int steps);

    void hardDrop();
    void accelerateTetromino();
    void decelerateTetromino();

    void changeTetromino();

public:

    Game();
    ~Game();

    void run();

};

#endif