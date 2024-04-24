#include "lib.h"

#define IMM2D_WIDTH 640/2
#define IMM2D_HEIGHT 480/2
#define IMM2D_SCALE 3
#define IMM2D_IMPLEMENTATION
#include "immediate2d/immediate2d.h"

extern LoopFunctionT loopFunction;

//all api functions in immediate2d.h but lowercase in the first letter
void drawPixel(int x, int y, KColor color)
{
    DrawPixel(x, y, static_cast<Color>(color));
}

void drawLine(int startPosX, int startPosY, int endPosX, int endPosY, int thickness, KColor color)
{
    DrawLine(startPosX, startPosY, endPosX, endPosY, thickness, static_cast<Color>(color));
}

void drawLine(float startPosX, float startPosY, float endPosX, float endPosY, int thickness, KColor color)
{
    DrawLine(startPosX, startPosY, endPosX, endPosY, thickness, static_cast<Color>(color));
}

void drawCircle(int centerX, int centerY, int radius, KColor fill, KColor stroke)
{
    DrawCircle(centerX, centerY, radius, static_cast<Color>(fill), static_cast<Color>(stroke));
}




/**
 * Implemmentation of immediate2d run function
*/
void run()
{
    loopFunction();
}

