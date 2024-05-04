#include "Sprite.hpp"

namespace graphics {

std::span<const KColor> Sprite::data() const
{
    if (std::holds_alternative<std::vector<KColor>>(rawData))
    {
        return std::span<const KColor>(std::get<std::vector<KColor>>(rawData));
    }
    else
    {
        return std::get<std::span<const KColor>>(rawData);
    }
}

const bool Sprite::isRef()
{
    return std::holds_alternative<std::span<const KColor>>(rawData);
}

void Sprite::drawToBuffer(ScreenBuff &sb, int x, int y) const
{
        KColor *data = sb.data()+(x + y * SCREEN_WIDTH);
        const auto* spritePtr = this->data().data();

        for (int i = 0; i < this->width(); i++)
        {
            for (int j = 0; j < this->height(); j++)
            {
                if (*spritePtr != KColor::Transparent)
                {
                    *data = *spritePtr;
                }
                spritePtr++;
                data++;

            }
            data += SCREEN_WIDTH - this->width();
        }
}

Sprite makeFaceSprite()
{

    // we could use https://www.piskelapp.com/ to create sprites and see how it looks before using it in the code
    KColor spriteData[8 * 8] = {
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
    return Sprite{{8, 8}, std::span{spriteData, 8 * 8}};
}

} // namespace ecs
