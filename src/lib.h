#pragma once

#include<cstdint>
#include<array>

constexpr int SCREEN_WIDTH = 640/2;
constexpr int SCREEN_HEIGHT = 360/2;

enum class KColor:uint32_t
{
    Transparent =   0x00000000,
    Black =         0xFF000000,
    Blue =          0xFF0000AA,
    Green =         0xFF00AA00,
    Cyan =          0xFF00AAAA,
    Red =           0xFFAA0000,
    Magenta =       0xFFAA00AA,
    Brown =         0xFFAA5500,
    LightGray =     0xFFAAAAAA,
    DarkGray =      0xFF555555,
    LightBlue =     0xFF5555FF,
    LightGreen =    0xFF55FF55,
    LightCyan =     0xFF55FFFF,
    LightRed =      0xFFFF5555,
    LightMagenta =  0xFFFF55FF,
    Yellow =        0xFFFFFF55,
    White =         0xFFFFFFFF
};


using Screen = std::array<KColor, SCREEN_WIDTH * SCREEN_HEIGHT>;

using ExecFunctionT = void (*)();

/**
 * Define this function pointer to point to the function that will be executed the application
 * todo: this could be better but requieres more work writing gdi window and events management
*/
extern ExecFunctionT executeFunction;

constexpr KColor makeColor(int r, int g, int b);

KColor makeColorHSB(int hue, int sat, int val);

void drawPixel(int x, int y, KColor color);
void drawLine(int startPosX, int startPosY, int endPosX, int endPosY,int thickness, KColor color);
void drawRectangle(int posX, int posY, int width, int height, KColor fill, KColor stroke = KColor::Transparent);
void drawCircle(int centerX, int centerY, int radius, KColor fill, KColor stroke = KColor::Transparent);
void drawArc(int centerX, int centerY, int radius, float thikness, KColor stroke, float startRadians, float endRadians);
void drawString(int x, int y, const char* text, const char* font, int fontSizePt, KColor color, bool centered = false);
void clearScreen(KColor color);

void updateScreen(const Screen& screen);

KColor readPixels(int x, int y);

void enableAntiAliasing();
void disableAntiAliasing();

char lastKey();
char lastBufferedKey();
void clearInputBuffer();

void wait(int milliseconds);
