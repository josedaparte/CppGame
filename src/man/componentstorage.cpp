#include "componentstorage.hpp"

namespace ECS {

ComponentStorage_t::ComponentStorage_t(std::size_t initialsize)
{
   m_physicsComponent.reserve(initialsize);
   m_renderComponent.reserve(initialsize);
   m_inputComponent.reserve(initialsize);
}

PhysicsComponent_t&
ComponentStorage_t::createPhysicsComponent(EntityID_t eid)
{
   auto& cmp = m_physicsComponent.emplace_back(eid);
   return cmp;
}

RenderComponent_t&
ComponentStorage_t::createRenderComponent(EntityID_t eid)
{
   auto& cmp = m_renderComponent.emplace_back(eid);
   return cmp;
}

InputComponent_t&
ComponentStorage_t::createInputComponent(EntityID_t eid)
{
   auto& cmp = m_inputComponent.emplace_back(eid);
   return cmp;
}

} // namespace ECS 