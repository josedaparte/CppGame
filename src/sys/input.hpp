#pragma once

#include "../util/keyboard.hpp"
#include "../util/typealiases.hpp"

namespace ECS
{   

// Fordward Declaration
struct GameContext_t;

struct InputSystem_t
{
    explicit InputSystem_t();

    static void onKeyPress(KeySym k);
    static void onKeyRelease(KeySym k);
    bool update(GameContext_t& g) const;

private:
    inline static Keyboard_t theKeyboard {};

};
   
} // namespace ECS
