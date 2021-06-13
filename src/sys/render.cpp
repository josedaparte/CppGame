#include <algorithm>

extern "C"{
   #include "tinyPTC/tinyptc.h"
}

#include "render.hpp"
#include <iostream>

namespace ECS {

RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h)
: m_w{w}, m_h{h}
, m_framebuffer{ std::make_unique<uint32_t[]> (m_w*m_h) }
{
    ptc_open("Window", m_w, m_h);
}

RenderSystem_t::~RenderSystem_t(){
    ptc_close();
}

void
RenderSystem_t::drawAllEntities(const GameContext_t& g) const
{
    auto screen = m_framebuffer.get();
    auto getScreenXY = [&](uint32_t x, uint32_t y)
    {
        return screen + x + y * m_w; 
    };
    auto drawEntity = [&](const RenderComponent_t& rc){
        auto eptr = g.getEntityById(rc.getEntityId());

        if(eptr && eptr->phy){
            auto& e = *eptr;
            auto screen = getScreenXY(e.phy->x, e.phy->y);
            auto sprite = begin(e.rnd->m_sprite);
            for(uint32_t y = 0; y < e.rnd->h ; y++){
                std::copy(sprite, sprite + e.rnd->w, screen);
                screen += m_w;
                sprite += e.rnd->w;
            }
        }
    };
    std::for_each(begin(g.getRenderComponent()), end(g.getRenderComponent()), drawEntity);
}

bool
RenderSystem_t::update(const GameContext_t& g) const {
    auto screen = m_framebuffer.get();

    std::fill(screen, screen+m_h*m_w, 0x00FF0000);
    drawAllEntities(g);
    ptc_update(screen);
    return !ptc_process_events();
}

} // namespace ECS
