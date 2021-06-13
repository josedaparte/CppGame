#include "input.hpp"
#include "../util/gamecontext.hpp"

extern "C"{
   #include "tinyPTC/tinyptc.h"
}

namespace ECS {


InputSystem_t::InputSystem_t()
{
ptc_set_on_keypress( onKeyPress );
ptc_set_on_keyrelease( onKeyRelease );
}

void
InputSystem_t::onKeyPress(KeySym k)
{
   theKeyboard.keyPressed(k);
}

void
InputSystem_t::onKeyRelease(KeySym k)
{
   theKeyboard.keyReleased(k);
}

bool InputSystem_t::update(GameContext_t& g) const {
   ptc_process_events();
   for(auto& inp : g.getInputComponent())
   {
      auto* e = g.getEntityById(inp.getEntityId()); 
      if( e && e->phy)
      {
         auto& phy = *(e->phy);
         phy.vx = phy.vy = 0;
         if(theKeyboard.isKeyPressed( inp.Key_DOWN )) phy.vy =  1;
         if(theKeyboard.isKeyPressed( inp.Key_UP   )) phy.vy = -1;
         if(theKeyboard.isKeyPressed( inp.Key_LEFT )) phy.vx = -1;
         if(theKeyboard.isKeyPressed( inp.Key_RIGHT)) phy.vx =  1;
      }
   }
    
   return true;
}

} // namespace ECS