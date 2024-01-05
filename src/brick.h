#ifndef _H_BRICK
#define _H_BRICK

#include <SFML/Graphics.hpp>

#include <vector>

#include "movement_behavior.h"
#include "entity.h"

class Wall;
class MovementBehavior;


class Brick : public Entity {

private:

    sf::RectangleShape shape;
    sf::Vector2f position;
    std::vector<int> matrix;

    int size;
    float time_when_accelerate;
    float time_when_decelerate;
    float current_time;

    MovementBehavior *movement_behavior;

    int fixed;

public:

    Brick();
    ~Brick();

    // Getters
    sf::RectangleShape getShape();
    sf::Vector2f getPosition();
    std::vector<int> getMatrix();
    int getSize();
    float getTimeWhenAccelerate();
    float getTimeWhenDecelerate();
    float getCurrentTime();
    MovementBehavior *getMovementbehavior();
    int getFixed();

    // Setters
    void setShape(sf::RectangleShape _shape);
    void setPosition(sf::Vector2f _position);
    void setMatrix(std::vector<int> _matrix);
    void setSize(int _size);
    void setTimeWhenAccelerate(float _time_when_accelerate);
    void setTimeWhenDecelerate(float _time_when_decelerate);
    void setCurrentTime(float _current_time);
    void setMovementBehavior(MovementBehavior *_movement_behavior);
    void setFixed(int _fixed);

    void handleKeyPressed(sf::Keyboard::Key key_pressed);
    void handleKeyReleased(sf::Keyboard::Key key_released);

    void update(float delta);
    void drawAt(sf::RenderWindow *window);

    void reset();

};

#endif