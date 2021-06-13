#pragma once

#include "../util/gamecontext.hpp"
#include "../util/typealiases.hpp"

namespace ECS
{   

struct EntityManager_t;

struct CollisionSystem_t
{
    explicit CollisionSystem_t() =default;
    bool update(GameContext_t& g) const;

private:

};
   
} // namespace ECS
