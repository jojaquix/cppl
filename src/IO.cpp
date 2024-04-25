#include "IO.hpp"

#define IMM2D_WIDTH SCREEN_WIDTH
#define IMM2D_HEIGHT SCREEN_HEIGHT
#define IMM2D_SCALE 3
#define IMM2D_IMPLEMENTATION
#include "immediate2d/immediate2d.h"

#include <span>

static void updateScreenImpl(std::span<const KColor> screen);

//all api functions in immediate2d.h but lowercase in the first letter

constexpr KColor makeColor(int r, int g, int b)
{
    return static_cast<KColor>(0xFF000000 | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | ((b & 0xFF) << 0));
}

KColor makeColorHSB(int hue, int sat, int val)
{
    float h = std::min(1.0f, std::max(0.0f, (hue % 360) / 360.0f));
    float s = std::min(1.0f, std::max(0.0f, sat / 255.0f));
    float v = std::min(1.0f, std::max(0.0f, val / 255.0f));

    if (s == 0)
    {
        int gray = int(v * 255);
        return makeColor(gray, gray, gray);
    }

    float var_h = h * 6;
    int var_i = int(var_h);
    float var_1 = v * (1 - s);
    float var_2 = v * (1 - s * (var_h - var_i));
    float var_3 = v * (1 - s * (1 - (var_h - var_i)));

    float var_r;
    float var_g;
    float var_b;

    switch (var_i)
    {
        case 0:  var_r = v;     var_g = var_3; var_b = var_1; break;
        case 1:  var_r = var_2; var_g = v;     var_b = var_1; break;
        case 2:  var_r = var_1; var_g = v;     var_b = var_3; break;
        case 3:  var_r = var_1; var_g = var_2; var_b = v;     break;
        case 4:  var_r = var_3; var_g = var_1; var_b = v;     break;
        default: var_r = v;     var_g = var_1; var_b = var_2; break;
    }

    return makeColor(int(var_r * 255), int(var_g * 255), int(var_b * 255));
}

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

void clearScreen(KColor color)
{
    Clear(static_cast<Color>(color));
}

void updateScreen(const ScreenBuff &screen)
{
    updateScreenImpl(screen);
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

void wait(int milliseconds)
{
    Wait(milliseconds);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Internal implementations
///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Just to allow us work with vector or array as screen buffer 
*/

static void updateScreenImpl(std::span<const KColor> screen)
{
    if (screen.size() != Width * Height) return;

    std::lock_guard<std::mutex> lock(imm2d_bitmapLock);
    if (!imm2d_graphics) return;

    Gdiplus::BitmapData d;
    Gdiplus::Rect r(0, 0, Width, Height);

    auto &b = imm2d_doubleBuffered ? imm2d_bitmapOther : imm2d_bitmap;
    b->LockBits(&r, Gdiplus::ImageLockModeWrite, b->GetPixelFormat(), &d);

    auto dstLine = reinterpret_cast<uint32_t *>(d.Scan0);
    for (int y = 0; y < Height; ++y)
    {
        auto srcLine = &screen[Width * y];
        memcpy(dstLine, srcLine, Width * sizeof(uint32_t));
        dstLine += d.Stride / 4;
    }

    b->UnlockBits(&d);
    imm2d_dirty = true;
}    

/**
 * Implemmentation of immediate2d run function
*/
void run()
{
    executeFunction();
}




