/*  -*-  eval: (turn-on-orgtbl); -*-
 * default FN Layout
 */
#include QMK_KEYBOARD_H

enum layers
{
    BASE = 0,
    GDB,
    FN,
    NORMAL,
    MOUSE
};

enum {
    TD_FF = 0
};

enum custom_keycodes {
  P_PARENT = SAFE_RANGE,
  VIM_Gt,
  VIM_GT,
  VIM_TABE,
  VIM_TE,
  GDB_C,
  GDB_SI,
  GDB_NI,
  GDB_FIN,
  TMUX_RESIZE_PANE_H,
  TMUX_RESIZE_PANE_J,
  TMUX_RESIZE_PANE_K,
  TMUX_RESIZE_PANE_L
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TMUX_RESIZE_PANE_H:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING(SS_LCTRL("a")"H");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case TMUX_RESIZE_PANE_J:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING(SS_LCTRL("a")"J");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case TMUX_RESIZE_PANE_K:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING(SS_LCTRL("a")"K");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case TMUX_RESIZE_PANE_L:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING(SS_LCTRL("a")"L");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case P_PARENT:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("cd .."SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case GDB_C:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("c"SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case GDB_SI:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("si"SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case GDB_NI:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("ni"SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case GDB_FIN:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("fin"SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case VIM_Gt:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("gt"SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case VIM_GT:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING("gT"SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case VIM_TABE:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING(":tabe"SS_TAP(X_ENTER)"");
      } else {
        // when keycode P_PARENT is released
      }
      break;

    case VIM_TE:
      if (record->event.pressed) {
        // when keycode P_PARENT is pressed
        SEND_STRING(":te ");
      } else {
        // when keycode P_PARENT is released
      }
      break;


  }
  return true;
};

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_F);
  } else {
    layer_on(NORMAL);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_F);
  } else {
  }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // complex tap dance function (to specify what happens when key is pressed 3+ times, for example). See https://docs.qmk.fm/tap_dance.html for how to define
    [TD_FF] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE layer: Default Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab(fn)|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift     | fn  |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

     [BASE] = LAYOUT( //  default layer
        LT(GDB, KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        LT(FN, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, TD(TD_FF), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(FN),
        KC_LGUI, KC_LALT, /*        */ (KC_SPC), KC_RGUI, KC_RALT),

    /* FN layer: In progress..
     * ,-----------------------------------------------------------------------------------------.
     * | PWR |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  | PGU |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  | PGD |  F  |  G  | LEF | DOW | UP  | RIG |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | par |  /  | Shift     | RES |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

    [FN] = LAYOUT(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, TG(NORMAL), KC_TRNS, VIM_TABE, KC_TRNS, VIM_TE, KC_TRNS, KC_PGUP, VIM_GT, VIM_Gt, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_PGDN, KC_F, KC_G, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, KC_QUOT, KC_ENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, P_PARENT, KC_DOWN, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, TG(NORMAL), KC_TRNS, KC_TRNS),

    /* Pinky layer: Layer used to replace the most common right hand pinky keys such as enter and backspace
     * ,-----------------------------------------------------------------------------------------.
     * | PWR |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  | PGU |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  | PGD |  F  |  G  | LEF | DOW | UP  | RIG |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | par |  /  | Shift     | RES |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

    [GDB] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, GDB_C, KC_6, KC_7, KC_8, KC_9, GDB_NI, GDB_SI, GDB_FIN, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, TMUX_RESIZE_PANE_H, TMUX_RESIZE_PANE_J, TMUX_RESIZE_PANE_K, TMUX_RESIZE_PANE_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, P_PARENT, KC_SLSH, KC_RSFT, MO(FN),
        KC_LGUI, KC_LALT, /*        */ (KC_SPC), KC_RGUI, KC_RALT),

    /* Normal layer: Layer used to replace the most common right hand pinky keys such as enter and backspace
     * ,-----------------------------------------------------------------------------------------.
     * | PWR |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  | PGU |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  | PGD |  F  |  G  | LEF | DOW | UP  | RIG |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | par |  /  | Shift     | RES |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

    [NORMAL] = LAYOUT(
        TO(BASE), KC_1, KC_2, KC_3, KC_4, GDB_C, KC_6, KC_7, KC_8, KC_9, GDB_NI, GDB_SI, GDB_FIN, KC_BSLS, KC_GRV,
        LT(MOUSE, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_PGUP, TO(BASE), KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, LT(MOUSE, KC_A), KC_S, KC_PGDN, KC_F, KC_G, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, KC_QUOT, KC_BTN1,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, P_PARENT, KC_SLSH, KC_RSFT, MO(FN),
        KC_LGUI, KC_LALT, /*        */ (LT(MOUSE, KC_SPACE)), KC_RGUI, KC_RALT),

    /* Mouse layer: Layer used to replace the most common right hand pinky keys such as enter and backspace
     * ,-----------------------------------------------------------------------------------------.
     * | PWR |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  | PGU |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  | PGD |  F  |  G  | LEF | DOW | UP  | RIG |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | par |  /  | Shift     | RES |
     * +-----------------------------------------------------------------------------------------+
     *         | Alt |  Gui   |               Space               | Gui   | Alt |
     *         `----------------------------------------------------------------´
     */

    [MOUSE] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, GDB_C, KC_6, KC_7, KC_8, KC_9, GDB_NI, GDB_SI, GDB_FIN, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_WH_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_WH_D, KC_F, KC_G, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_SCLN, KC_QUOT, KC_BTN1,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, P_PARENT, KC_SLSH, KC_RSFT, MO(FN),
        KC_LGUI, KC_LALT, /*        */ (KC_BTN1), KC_RGUI, KC_RALT)
};
