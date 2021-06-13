#pragma once

#include <cstdint>
#include <unordered_map>

#include "physics.hpp"
#include "render.hpp"
#include "input.hpp"
#include "../util/typealiases.hpp"

namespace ECS {

struct Entity_t
{   
    explicit Entity_t() = default;  

    template <typename CMP_t>
    void addComponent(CMP_t& cmp)
    {
        auto type = cmp.getComponentTypeID();
        m_components[type] = &cmp;
    }

    template <typename CMP_t>
    CMP_t* getComponent()
    {
        auto type = CMP_t::getComponentTypeID();
        auto& it = m_components.find(type);
        if (it != m_components.end())
            return *(it->second);
        return nullptr;
    }

    template <typename CMP_t>
    const CMP_t* getcomponent() const
    {
        auto* cmp = const_cast<Entity_t*>(this)->getComponent<CMP_t>();
        return const_cast<const CMP_t*>(cmp);
    }

    constexpr EntityID_t getEntityID() const noexcept { return entityID; }

    PhysicsComponent_t* phy { nullptr };
    RenderComponent_t*  rnd { nullptr };
    InputComponent_t*   inp { nullptr };


private:
    // unordered Map con los components
    std::unordered_map<std::size_t, Component_t*> m_components {};

    EntityID_t entityID { ++nextID };
    inline static EntityID_t nextID { 0 };
};


}   // namespace ECS 