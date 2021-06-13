#pragma once

#include "../sys/render.hpp"
#include "../cmp/physics.hpp"
#include "../cmp/render.hpp"
#include "../cmp/input.hpp"
#include "../util/typealiases.hpp"

#include <vector>
#include <memory>

namespace ECS {

struct ComponentsVectorBase_t
{};

template <typename CMP_t>
struct ComponentVector_t : ComponentsVectorBase_t
{
   std::vector<CMP_t> components {};
};

struct ComponentStorage_t {

   /*
   std::vector<InputComponent_t>& createComponentVector()
   {
      auto tipeId = InputComponent_t::getComponentTypeID();
      auto* v = std::make_unique<InputComponent_t>;

   }
   */
   
   explicit ComponentStorage_t(std::size_t);

   ComponentStorage_t(const ComponentStorage_t& )           = delete;
   ComponentStorage_t(ComponentStorage_t&& )                = delete;
   ComponentStorage_t& operator=(const ComponentStorage_t&) = delete;
   ComponentStorage_t& operator+(ComponentStorage_t&& )     = delete;

   PhysicsComponent_t& createPhysicsComponent(EntityID_t);
   RenderComponent_t&  createRenderComponent(EntityID_t);
   InputComponent_t&   createInputComponent(EntityID_t);

   template <typename CMD_t>
   std::vector<CMD_t>& createVectorComponent()
   {
      auto TypeId = CMD_t::getComponentTypeID();
      auto v = std::make_unique<ComponentVector_t<CMD_t>>();
      v->components.reserve(100);
      auto* vecptr = v.get();
      m_ComponentVectors[TypeId] = std::move(v);
      return vecptr->components;
   }

   template <typename CMD_t>
   std::vector<CMD_t>& getVectorComponent()
   {
      std::vector<CMD_t>* comvec {nullptr};
      auto TypeId = CMD_t::getComponentTypeID();
      auto it = m_ComponentVectors.find(TypeId);
      if( it != m_ComponentVectors.end())
      {
         auto* v = static_cast<ComponentVector_t<CMD_t>*>(it->second.get());
         comvec = &(v->components);
      }
      else
      {
         comvec = &createVectorComponent<CMD_t>();
      }
      return *comvec;
   }

         std::vector<PhysicsComponent_t>&  getPhysicsComponent()       {return m_physicsComponent;}
   const std::vector<PhysicsComponent_t>&  getPhysicsComponent() const {return m_physicsComponent;}

         std::vector<RenderComponent_t>&   getRenderComponent()        {return m_renderComponent;}
   const std::vector<RenderComponent_t>&   getRenderComponent()  const {return m_renderComponent;}

         std::vector<InputComponent_t>&    getInputComponent()         {return m_inputComponent;}
   const std::vector<InputComponent_t>&    getInputComponent()   const {return m_inputComponent;}

private:
   std::unordered_map<std::size_t, std::unique_ptr<ComponentsVectorBase_t> > m_ComponentVectors {};

   std::vector<PhysicsComponent_t> m_physicsComponent {};
   std::vector<RenderComponent_t>  m_renderComponent  {};
   std::vector<InputComponent_t>   m_inputComponent   {};
};

} // namespace ECS