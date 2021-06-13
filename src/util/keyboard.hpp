#pragma once

#include <X11/X.h>
#include <X11/keysym.h>
#include <unordered_map>

namespace ECS
{

struct Keyboard_t
{
   using OptIter = std::optional<std::unordered_map<KeySym, bool>::iterator>;

   explicit Keyboard_t() = default;

   Keyboard_t(const Keyboard_t&)             = delete;
   Keyboard_t(Keyboard_t&&)                  = delete;
   Keyboard_t& operator=(const Keyboard_t&)  = delete;
   Keyboard_t& operator=(Keyboard_t&&)       = delete;

   bool isKeyPressed (KeySym k) noexcept;
   void keyPressed   (KeySym k) noexcept;
   void keyReleased  (KeySym k) noexcept;
   
private:
   OptIter getIterator(KeySym k) noexcept;

std::unordered_map<KeySym, bool> m_pressedKeys {
   { XK_BackSpace, false},
   { XK_Tab, false},
   { XK_Linefeed, false},
   { XK_Clear, false},
   { XK_Return, false},
   { XK_Pause, false},
   { XK_Scroll_Lock, false},
   { XK_Sys_Req, false},
   { XK_Escape, false},
   { XK_Delete, false},
   { XK_Home, false},
   { XK_Left, false},
   { XK_Up, false},
   { XK_Right, false},
   { XK_Down, false},
   { XK_Prior, false},
   { XK_Page_Down, false},
   { XK_Next, false},
   { XK_Page_Up, false},
   { XK_End, false},
   { XK_Begin, false},
   { XK_Select, false},
   { XK_Print, false},
   { XK_Execute, false},
   { XK_Insert, false},
   { XK_Undo, false},
   { XK_Redo, false},
   { XK_Menu, false},
   { XK_Find, false},
   { XK_Cancel, false},
   { XK_Help, false},
   { XK_Break, false},
   { XK_Mode_switch, false},
   { XK_script_switch, false},
   { XK_Num_Lock, false},
   { XK_space, false},
   { XK_Tab, false},
   { XK_KP_Enter, false},
   { XK_plus, false},
   { XK_comma, false},
   { XK_colon, false},
   { XK_minus, false},
   { XK_period, false},
   { XK_slash, false},
   { XK_0, false},
   { XK_1, false},
   { XK_2, false},
   { XK_3, false},
   { XK_4, false},
   { XK_5, false},
   { XK_6, false},
   { XK_7, false},
   { XK_8, false},
   { XK_9, false},
   { XK_less, false},
   { XK_equal, false},
   { XK_greater, false},
   { XK_question, false},   
   { XK_at, false},
   { XK_q, false},
   { XK_w, false},
   { XK_e, false},
   { XK_r, false},
   { XK_t, false},
   { XK_y, false},
   { XK_u, false},
   { XK_i, false},
   { XK_o, false},
   { XK_p, false},
   { XK_a, false},
   { XK_s, false},
   { XK_d, false},
   { XK_f, false},
   { XK_g, false},
   { XK_h, false},
   { XK_j, false},
   { XK_k, false},
   { XK_l, false},
   { XK_z, false},
   { XK_x, false},
   { XK_c, false},
   { XK_v, false},
   { XK_b, false},
   { XK_n, false},
   { XK_m, false},
   { XK_Q, false},
   { XK_W, false},
   { XK_E, false},
   { XK_R, false},
   { XK_T, false},
   { XK_Y, false},
   { XK_U, false},
   { XK_I, false},
   { XK_O, false},
   { XK_P, false},
   { XK_A, false},
   { XK_S, false},
   { XK_D, false},
   { XK_F, false},
   { XK_G, false},
   { XK_H, false},
   { XK_J, false},
   { XK_K, false},
   { XK_L, false},
   { XK_Z, false},
   { XK_X, false},
   { XK_C, false},
   { XK_V, false},
   { XK_B, false},
   { XK_N, false},
   { XK_M, false}
};

};

   
} // namespace ECS