#pragma once

#include "typealiases.hpp"
#include "../cmp/entity.hpp"
 
namespace ECS {

struct GameContext_t
{
    ~GameContext_t() = default;

    virtual const Entity_t* getEntityById(EntityID_t eid) const = 0;  
    virtual       Entity_t* getEntityById(EntityID_t eid)       = 0;

    virtual const Vec_t<Entity_t>& getEntities() const = 0;
    virtual       Vec_t<Entity_t>& getEntities()       = 0 ;

    virtual const std::vector<PhysicsComponent_t>& getPhysicsComponent() const = 0;
    virtual       std::vector<PhysicsComponent_t>& getPhysicsComponent()       = 0;

    virtual const std::vector<RenderComponent_t>&  getRenderComponent()  const = 0;
    virtual       std::vector<RenderComponent_t>&  getRenderComponent()        = 0;

    virtual const std::vector<InputComponent_t>&   getInputComponent()   const = 0;
    virtual       std::vector<InputComponent_t>&   getInputComponent()         = 0;
};

}   // namespace ECS