#pragma once

#include <cstdint>
#include <vector>
#include <algorithm>

#include "../util/gamecontext.hpp"
#include "../cmp/entity.hpp"
#include "componentstorage.hpp"

namespace ECS {

struct EntityManager_t: public GameContext_t {
   static constexpr std::size_t kNUMINITIALENTITIES { 1000 };

   explicit EntityManager_t();
   Entity_t& createEntity(uint32_t x, uint32_t y);
   void addInputComponent(Entity_t&);

   const Vec_t<Entity_t>& getEntities() const override {return m_Entity;}
         Vec_t<Entity_t>& getEntities()       override {return m_Entity;}

   const Entity_t* getEntityById(EntityID_t eid) const override;  
         Entity_t* getEntityById(EntityID_t eid)       override;

   const std::vector<PhysicsComponent_t>& getPhysicsComponent() const override {return m_components.getPhysicsComponent();}
         std::vector<PhysicsComponent_t>& getPhysicsComponent()       override {return m_components.getPhysicsComponent();}

   const std::vector<RenderComponent_t>& getRenderComponent()   const override {return m_components.getRenderComponent();}
         std::vector<RenderComponent_t>& getRenderComponent()         override {return m_components.getRenderComponent();}

   const std::vector<InputComponent_t>& getInputComponent()     const override {return m_components.getInputComponent();}
         std::vector<InputComponent_t>& getInputComponent()           override {return m_components.getInputComponent();}    
private:
   Vec_t<Entity_t> m_Entity {};
   ComponentStorage_t m_components {kNUMINITIALENTITIES};
};

}  // namespace ECS
