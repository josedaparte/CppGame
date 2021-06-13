#pragma once
#include <cstdint>
#include <memory>
#include "../util/gamecontext.hpp"

namespace ECS
{   
    struct EntityManager_t;

    struct RenderSystem_t
    {
        explicit RenderSystem_t(uint32_t w, uint32_t h);

        ~RenderSystem_t();

        bool update(const GameContext_t& g) const;
        void drawAllEntities(const GameContext_t& g) const;
        void drawEntity(const Entity_t& e) const;

    private:
        const uint32_t m_w { 0 }, m_h { 0 };
        const std::unique_ptr<uint32_t[]> m_framebuffer { nullptr };
};
   
} // namespace ECS
