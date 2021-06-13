#pragma once

#include <cstdint>

#include "component.hpp"

namespace ECS {

struct PhysicsComponent_t: Component_t {

PhysicsComponent_t(EntityID_t eid)
   : Component_t(eid)
{ };

static std::size_t getComponentTypeID()
{
   static std::size_t typeId { 2 };
   return typeId;
}

uint32_t x{0}, y{0};    
int32_t vx{1}, vy{1};
};

} // namespace ECS 