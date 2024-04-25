#pragma once

#include "lib.h"
#include <cstdint>
#include <variant>
#include <span>
#include <vector>
#include <unordered_map>
#include <utility>

namespace ecs {

using EntityID = uint32_t;

using Dimension = std::pair<int, int>;

using SpriteData = std::variant<std::vector<KColor>, std::span<const KColor>>;

struct Sprite
{    
    std::span<const KColor> data() const
    {
        if (std::holds_alternative<std::vector<KColor>>(data))
        {
            return std::span<const KColor>(std::get<std::vector<KColor>>(data));
        }
        else
        {
            return std::get<std::span<const KColor>>(data);
        }
    }        
    Dimension size;
    SpriteData data;
};

struct Entity {
    EntityID id;
    Sprite sprite;
};

template <typename ComponentType>
class EntityManager {
public:
    // Constructor
    explicit EntityManager() : nextEntityID(0) {}

    // Create a new entity
    EntityID createEntity() {
        EntityID entityID = nextEntityID;
        nextEntityID++;
        return entityID;
    }

    // Destroy an entity
    void destroyEntity(EntityID entityID) {
        // Perform any necessary cleanup for the entity
        // ...

        // Remove the entity from any internal data structures
        // ...
    }

private:
    // Data members and private methods go here

    EntityID nextEntityID; // The ID to assign to the next created entity

    std::unorderer_map<EntityID, ComponentType> components;

};

} // namespace ecs