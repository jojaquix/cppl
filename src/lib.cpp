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

void drawRectangle(int posX, int posY, int width, int height, KColor fill, KColor stroke)
{
    DrawRectangle(posX, posY, width, height, static_cast<Color>(fill), static_cast<Color>(stroke));
}

void drawCircle(int centerX, int centerY, int radius, KColor fill, KColor stroke)
{
    DrawCircle(centerX, centerY, radius, static_cast<Color>(fill), static_cast<Color>(stroke));
}

void drawArc(int centerX, int centerY, int radius, float thikness, KColor stroke, float startRadians, float endRadians)
{
    DrawArc(centerX, centerY, radius, thikness, static_cast<Color>(stroke), startRadians, endRadians);
}

void drawString(int x, int y, const char *text, const char *font, int fontSizePt, KColor color, bool centered)
{
    DrawString(x, y, text, font, fontSizePt, static_cast<Color>(color), centered);
}

void clear(KColor color)
{
    Clear(static_cast<Color>(color));
}

void enableAntiAliasing()
{
    UseAntiAliasing();
}

void disableAntiAliasing()
{
    StopAntiAliasing();
}

char lastKey()
{
    return LastKey();
}

char lastBufferedKey()
{
    return LastBufferedKey();
}

void clearInputBuffer()
{
    ClearInputBuffer();
}

/**
 * Implemmentation of immediate2d run function
*/
void run()
{
    loopFunction();
}

