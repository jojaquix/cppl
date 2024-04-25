#pragma once

#include "Types.hpp"
#include "Sprite.hpp"
#include <cstdint>
#include <variant>
#include <span>
#include <vector>
#include <unordered_map>
#include <utility>

/**
 * @file EntityManager.hpp
 * @brief Defines the EntityManager class and related data structures for entity-component system.
 */


namespace ecs {

using EntityID = uint32_t; /**< Type alias for entity ID. */


struct BasicEntity {
    EntityID id; /**< The ID of the entity. */
};


struct SpriteEntity: public BasicEntity {    
    Sprite sprite; /**< The sprite of the entity. */
};

/**
 * @class EntityManager
 * @brief Manages entities and their components.
 * @tparam ComponentType The type of the components associated with the entities.
 */
template <typename ComponentType>
class EntityManager {
public:
    /**
     * @brief Constructor for EntityManager.
     */
    explicit EntityManager() : nextEntityID(0) {}

    /**
     * @brief Create a new entity.
     * @return The ID of the newly created entity.
     */
    EntityID createEntity() {
        EntityID entityID = nextEntityID;
        nextEntityID++;
        return entityID;
    }

    /**
     * @brief Destroy an entity.
     * @param entityID The ID of the entity to destroy.
     */
    void destroyEntity(EntityID entityID) {
        // Perform any necessary cleanup for the entity
        // ...

        // Remove the entity from any internal data structures
        // ...
    }

private:
    // Data members and private methods go here

    EntityID nextEntityID; /**< The ID to assign to the next created entity. */

    std::unordered_map<EntityID, ComponentType> components; /**< The map of entity ID to component. */

};

} // namespace ecs