#pragma once

#include <vector>
#include <cstdint>
#include <string_view>
#include "../picoPNG/picopng.hpp"
#include "../util/typealiases.hpp"
#include "component.hpp"

namespace ECS {

struct RenderComponent_t : Component_t
{   
    explicit RenderComponent_t(EntityID_t eid)
    : Component_t(eid)
    {};

    static std::size_t getComponentTypeID()
{
   static std::size_t typeId { 3 };
   return typeId;
}

    void loadFromFile(const std::string_view filename);

    uint32_t w{0}, h{0};
    std::vector<uint32_t> m_sprite {};
};


}   // namespace ECS 