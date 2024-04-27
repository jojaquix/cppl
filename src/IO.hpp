#pragma once

#include "Types.hpp"

#include<cstdint>
#include<array>

constexpr int SCREEN_WIDTH = 640/2;
constexpr int SCREEN_HEIGHT = 360/2;

using ScreenBuff = std::array<KColor, SCREEN_WIDTH * SCREEN_HEIGHT>;

using ExecFunctionT = void (*)();

/**
 * Define this function pointer to point to the function that will be executed the application
 * todo: this could be better but requieres more work writing gdi window and events management
*/
//extern ExecFunctionT executeFunction;
extern void execute();

constexpr KColor makeColor(int r, int g, int b);

KColor makeColorHSB(int hue, int sat, int val);

void drawPixel(int x, int y, KColor color);
void drawLine(int startPosX, int startPosY, int endPosX, int endPosY,int thickness, KColor color);
void drawRectangle(int posX, int posY, int width, int height, KColor fill, KColor stroke = KColor::Transparent);
void drawCircle(int centerX, int centerY, int radius, KColor fill, KColor stroke = KColor::Transparent);
void drawArc(int centerX, int centerY, int radius, float thikness, KColor stroke, float startRadians, float endRadians);
void drawString(int x, int y, const char* text, const char* font, int fontSizePt, KColor color, bool centered = false);
void clearScreen(KColor color);

void updateScreen(const ScreenBuff& screen);

KColor readPixels(int x, int y);

void enableAntiAliasing();
void disableAntiAliasing();

char lastKey();
char lastBufferedKey();
void clearInputBuffer();

void wait(int milliseconds);
