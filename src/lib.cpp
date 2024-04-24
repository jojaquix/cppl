#include "lib.h"

#define IMM2D_WIDTH SCREEN_WIDTH
#define IMM2D_HEIGHT SCREEN_HEIGHT
#define IMM2D_SCALE 2
#define IMM2D_IMPLEMENTATION
#include "immediate2d/immediate2d.h"

#include <span>

extern LoopFunctionT loopFunction;

static void updateScreenImpl(std::span<const KColor> screen);

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

void updateScreen(const Screen &screen)
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
    loopFunction();
}




