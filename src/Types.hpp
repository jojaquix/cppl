#pragma once

#include<cstdint>
#include<array>

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


constexpr int SCREEN_DIV = 4;
constexpr int SCREEN_SCALE = 6;
constexpr int SCREEN_WIDTH = 640/SCREEN_DIV;
constexpr int SCREEN_HEIGHT = 360/SCREEN_DIV;

using ScreenBuff = std::array<KColor, SCREEN_WIDTH * SCREEN_HEIGHT>;

/** forward declaration of Srite type*/
namespace graphics {
    struct Sprite;
}


