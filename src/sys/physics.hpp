#pragma once

#include "../util/gamecontext.hpp"
#include "../util/typealiases.hpp"

namespace ECS
{   

struct EntityManager_t;

struct PhysicsSystem_t
{
    explicit PhysicsSystem_t() = default;
    bool update(GameContext_t& g) const;

private:

};
   
} // namespace ECS
