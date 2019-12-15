#ifndef __CUSTOM_KEYCODES__H__
#define __CUSTOM_KEYCODES__H__

#include "quantum_keycodes.h"
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VIM_A,
  VIM_B,
  VIM_C,
  VIM_CI,
  VIM_D,
  VIM_DI,
  VIM_E,
  VIM_H,
  VIM_I,
  VIM_J,
  VIM_K,
  VIM_L,
  VIM_O,
  VIM_P,
  VIM_S,
  VIM_U,
  VIM_V,
  VIM_VI,
  VIM_W,
  VIM_X,
  VIM_Y,
  EPRM,
  VRSN,
  RGB_SLD,
  /* My old ones */
  P_PARENT,
  TMUX_RESIZE_PANE_H,
  TMUX_RESIZE_PANE_J,
  TMUX_RESIZE_PANE_K,
  TMUX_RESIZE_PANE_L
};

#endif // __CUSTOM_KEYCODES__H__