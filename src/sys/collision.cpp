#include "collision.hpp"
#include "../util/gamecontext.hpp"

namespace ECS {

bool CollisionSystem_t::update(GameContext_t& g) const {
    for(auto& e : g.getEntities()){
        if(e.phy && e.rnd){
            if(e.phy->x > 640 || e.phy->x + e.rnd->w > 640) { e.phy->x -= e.phy->vx; e.phy->vx = -e.phy->vx; }
            if(e.phy->y > 360 || e.phy->y + e.rnd->h > 360) { e.phy->y -= e.phy->vy; e.phy->vy = -e.phy->vy; }
        }
    }
    return true;
}

} // namespace ECS