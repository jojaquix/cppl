#include "IO.hpp"
#include "Sprite.hpp"

#include <iostream>


static ScreenBuff screenBuff;


// we could use https://www.piskelapp.com/ to create sprites and see how it looks before using it in the code

KColor sprite1[8 * 8] = {
    //basic sprite of a smiley face in row major order
    KColor::Transparent, KColor::Transparent, KColor::Blue, KColor::Blue, KColor::Blue, KColor::Blue, KColor::Transparent, KColor::Transparent,
    KColor::Transparent, KColor::Blue, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Blue, KColor::Transparent,
    KColor::Blue, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Blue,
    KColor::Blue, KColor::Yellow, KColor::Black, KColor::Yellow, KColor::Yellow, KColor::Black, KColor::Yellow, KColor::Blue,
    KColor::Blue, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Blue,
    KColor::Blue, KColor::Yellow, KColor::Yellow, KColor::Black, KColor::Black, KColor::Yellow, KColor::Yellow, KColor::Blue,
    KColor::Transparent, KColor::Blue, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Yellow, KColor::Blue, KColor::Transparent,
    KColor::Transparent, KColor::Transparent, KColor::Blue, KColor::Blue, KColor::Blue, KColor::Blue, KColor::Transparent, KColor::Transparent,
};

// simple red cross sprite
KColor sprite2[8 * 8] = 
{
    //basic sprite of a red cross in row major order
    KColor::Transparent, KColor::Transparent, KColor::Transparent, KColor::Red, KColor::Red, KColor::Transparent, KColor::Transparent, KColor::Transparent,
    KColor::Transparent, KColor::Transparent, KColor::Transparent, KColor::Red, KColor::Red, KColor::Transparent, KColor::Transparent, KColor::Transparent,
    KColor::Transparent, KColor::Transparent, KColor::Transparent, KColor::Red, KColor::Red, KColor::Transparent, KColor::Transparent, KColor::Transparent,
    KColor::Red,         KColor::Red,         KColor::Red,         KColor::Red, KColor::Red, KColor::Red, KColor::Red, KColor::Red,
    KColor::Red,         KColor::Red,         KColor::Red,         KColor::Red, KColor::Red, KColor::Red, KColor::Red, KColor::Red,
    KColor::Transparent, KColor::Transparent, KColor::Transparent, KColor::Red, KColor::Red, KColor::Transparent, KColor::Transparent, KColor::Transparent,
    KColor::Transparent, KColor::Transparent, KColor::Transparent, KColor::Red, KColor::Red, KColor::Transparent, KColor::Transparent, KColor::Transparent,
    KColor::Transparent, KColor::Transparent, KColor::Transparent, KColor::Red, KColor::Red, KColor::Transparent, KColor::Transparent, KColor::Transparent,
};

/**
 * execution function type prototype
*/
void execute();


void screenBuffAddSprite(ScreenBuff& screenBuff, const graphics::Sprite& sprite, int x, int y)
{
    const auto* spritePtr = sprite.data().data();
    KColor *data = screenBuff.data()+(x + y * SCREEN_WIDTH);
    for (int i = 0; i < sprite.width(); i++)
    {
        for (int j = 0; j < sprite.height(); j++)
        {
            *data++ = *spritePtr++;
        }
        data += SCREEN_WIDTH - sprite.width();
    }   
}


/**
 * implementation of execute function
 */
void execute()
{    
    enableAntiAliasing();
#if 0    
    drawPixel(80, 60, KColor::Blue);
    drawLine(10, 10, 100, 100, 2, KColor::Green);
    drawRectangle(10, 10, 100, 100, KColor::Blue, KColor::Green);
    drawCircle(200, 100, 50, KColor::LightCyan, KColor::Green);
    //drawArc(60, 80, 50, 10, KColor::Yellow, 0, 3.14);
    wait(500);
#endif
   
    int xi= 10;    
    int yi= 10;

    //loop to move the sprite
    //graphics::Sprite sprite{{8, 8}, std::span{sprite1, 8 * 8}};
    graphics::Sprite sprite{graphics::makeFaceSprite()};
    for (int times = 0; times < 40; ++times)
    {

        std::fill(screenBuff.begin(), screenBuff.end(), KColor::Cyan);        
        //screenBuffAddSprite (screenBuff, sprite, xi, yi);
        sprite.drawToBuffer(screenBuff, xi, yi);     

        xi++;
        yi++;

        updateScreen(screenBuff);
        wait(20);
    }    

    //add a little output message
    drawString(10, 10, "Hello World!", "Consolas", 12, KColor::Black, false);

    std::cout << "Hello 2d using gdi+" << std::endl;

}



