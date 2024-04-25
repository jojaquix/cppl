#include "Sprite.hpp"

namespace ecs {

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


} // namespace ecs
