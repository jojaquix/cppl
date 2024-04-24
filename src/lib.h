#pragma once

#include<cstdint>

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


using LoopFunctionT = void (*)();

constexpr KColor makeColor(int r, int g, int b)
{
    return static_cast<KColor>(0xFF000000 | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | ((b & 0xFF) << 0));
}

void drawPixel(int x, int y, KColor color);
void drawLine(int startPosX, int startPosY, int endPosX, int endPosY,int thickness, KColor color);
void drawLine(float startPosX, float startPosY, float endPosX, float endPosY,int thickness, KColor color);
void drawCircle(int centerX, int centerY, int radius, KColor fill, KColor stroke);
void drawCircle(float centerX, float centerY, float radius, KColor fill, KColor stroke);






