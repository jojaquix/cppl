#include "IO.hpp"


ScreenBuff screen;


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

/**
 * execution function type prototype
*/
void execute();
ExecFunctionT executeFunction = execute;

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


    clearScreen(KColor::White);
  
    //loop to move the sprite
    for (int times = 0; times < 100; ++times)
    {
        for (int i = 0; i < SCREEN_WIDTH; i++)
        {
            for (int j = 0; j < SCREEN_HEIGHT; j++)
            {
                screen[i + j * SCREEN_WIDTH] = KColor::White;
            }
        }

        //copy sprite1 to screen
        static int xi= 10;    
        static int yi= 10;
        
        KColor *data = screen.data()+(xi + yi * SCREEN_WIDTH);
        const auto* spritePtr = sprite1;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                *data++ = *spritePtr++;
            }
            data += SCREEN_WIDTH - 8;
        }

        xi+=2;
        yi++;

        updateScreen(screen);
        wait(100);
    }    
}



