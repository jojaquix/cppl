#include "lib.h"

/**
 * loop prototype
*/
void loop();

LoopFunctionT loopFunction = loop;

/**
 * loop implementation
*/
void loop()
{
    drawPixel(80, 60, KColor::Red);
}



