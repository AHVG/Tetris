#ifndef _H_BRICK_GENERATOR
#define _H_BRICK_GENERATOR

/*

0000
####
0000
0000

0000
000#
####
0000

0000
#000
####
0000

##
##

0000
0##0
##00

0000
##00
0##0

000
###
0#0

*/

#include "brick.h"

class BrickGenerator {

private:


public:

    Brick *generate(MovementBehavior *movement_behavior);

};

#endif