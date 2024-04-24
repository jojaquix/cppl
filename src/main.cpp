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
    enableAntiAliasing();
    drawPixel(80, 60, KColor::Blue);
    drawLine(10, 10, 100, 100, 2, KColor::Green);
    drawRectangle(10, 10, 100, 100, KColor::Blue, KColor::Green);
    drawCircle(200, 100, 50, KColor::LightCyan, KColor::Green);
    //drawArc(60, 80, 50, 10, KColor::Yellow, 0, 3.14);
}



