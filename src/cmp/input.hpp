#pragma once

#include <cstdint>
#include <X11/X.h>
#include <X11/keysym.h>

#include "component.hpp"

namespace ECS {

struct InputComponent_t: Component_t {

InputComponent_t(EntityID_t eid)
   : Component_t(eid)
   { };

static std::size_t getComponentTypeID()
{
   static std::size_t typeId { 1 };
   return typeId;
}

KeySym Key_UP     { XK_w };
KeySym Key_DOWN   { XK_s };
KeySym Key_LEFT   { XK_a };
KeySym Key_RIGHT  { XK_d };

};

} // namespace ECS 