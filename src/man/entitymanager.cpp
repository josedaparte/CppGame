#include "entitymanager.hpp"

namespace ECS {

EntityManager_t::EntityManager_t()
{
   m_Entity.reserve(kNUMINITIALENTITIES);  
}

const Entity_t*
EntityManager_t::getEntityById(EntityID_t eid) const
{
   auto it = std::find_if(m_Entity.begin(),
               m_Entity.end(),
               [&](const auto& e){return e.getEntityID() == eid; }
               );

   if(it == m_Entity.end())
        return nullptr;

   return it.base();  
}

Entity_t*
EntityManager_t::getEntityById(EntityID_t eid)
{
   auto eptr = const_cast<const EntityManager_t*>(this)->getEntityById(eid);
   return const_cast<Entity_t*>(eptr);
}

Entity_t&
EntityManager_t::createEntity(uint32_t x, uint32_t y)
{
   auto& e = m_Entity.emplace_back();
   auto& ph = m_components.createPhysicsComponent(e.getEntityID());
   auto& rn = m_components.createRenderComponent(e.getEntityID());
   rn.loadFromFile("/home/josedaparte/Documentos/CppRetroman/src/assets/Mario40px.png");
   e.phy = &ph;
   e.rnd = &rn;
   ph.x = x; ph.y = y;
   return e;
}

void
EntityManager_t::addInputComponent(Entity_t& e)
{
   if( !e.inp )
   {
      auto& in = m_components.createInputComponent(e.getEntityID());
      e.inp = &in;
   }
}

}   // namespace ECS