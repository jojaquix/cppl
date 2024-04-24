#include "lib.h"


Screen screen;

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
    wait(2000);

    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {
            screen[i + j * SCREEN_WIDTH] = KColor::LightMagenta;
        }
    }
    updateScreen(screen);
    
}



