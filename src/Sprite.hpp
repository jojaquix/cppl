#pragma once

#include "Types.hpp"
#include <cstdint>
#include <variant>
#include <span>
#include <vector>

namespace ecs {

using Dimension = std::pair<int, int>; /**< Type alias for dimension of a sprite. */
using SpriteData = std::variant<std::vector<KColor>, std::span<const KColor>>; /**< Type alias for sprite data. */

/**
 * @struct Sprite
 * @brief Represents a sprite with its size and data.
 */
struct Sprite
{    
    Dimension size; /**< The size of the sprite. */
    SpriteData rawData; /**< The data of the sprite. */

    /**
     * @brief Get the sprite data as a span of const KColor.
     * @return The sprite data as a span of const KColor.
     */
    std::span<const KColor> data() const;
};

} // namespace ecs