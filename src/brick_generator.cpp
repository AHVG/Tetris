
#include "brick_generator.h"

Brick *BrickGenerator::generate(MovementBehavior *movement_behavior) {
    Brick *new_brick = new Brick();

    movement_behavior->setBrick(new_brick);

    return new_brick;
}
