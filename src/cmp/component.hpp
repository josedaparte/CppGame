#pragma once

#include <cstdint>

#include "../util/typealiases.hpp"

namespace ECS
{

struct Component_t
{
   explicit Component_t(EntityID_t eid):
      EntityID {eid}
   {}
/*
   template <typename TIPO>
   std::size_t getComponentTypeID() 
   {
      static std::size_t type { ++nextComponentTypeID }; 
      return type;
   }*/

   constexpr EntityID_t getEntityId() const noexcept {return EntityID; }

private:
   EntityID_t EntityID { 0 };
   EntityID_t ComponentID { ++nextID };
   inline static EntityID_t nextID { 0 };
   inline static std::size_t nextComponentTypeID { 0 };
};

} // namespace ECS