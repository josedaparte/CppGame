#include "keyboard.hpp"

namespace ECS
{

bool
Keyboard_t::isKeyPressed(KeySym k) noexcept
{
   auto it = getIterator(k);
   if( it )
      return (*it)->second;
   return false;
}

void 
Keyboard_t::keyPressed(KeySym k) noexcept
{
   auto it = getIterator(k);
      (*it)->second = true;
}
void 
Keyboard_t::keyReleased(KeySym k) noexcept
{
   auto it = getIterator(k);
      (*it)->second = false;
}

Keyboard_t::OptIter
Keyboard_t::getIterator(KeySym k) noexcept
{
   auto it = m_pressedKeys.find(k);
   if(it != m_pressedKeys.end())
      return it;
   return {};
}

} // namespace ECS