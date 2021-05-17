#include QMK_KEYBOARD_H

enum layers
{
    BASE_WIN = 0,
    BASE_MAC,
    TAB_FN,
    ESC_FN,
    MOUSE
};

enum custom_keycodes {
  P_PARENT = SAFE_RANGE,
  TMUX_RESIZE_PANE_H,
  TMUX_RESIZE_PANE_J,
  TMUX_RESIZE_PANE_K,
  TMUX_RESIZE_PANE_L
};


static bool ascii_code_ctrl = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCTL:
      if (record->event.pressed) {
      }
      else
      {
        ascii_code_ctrl = false;
      }
      break;

    /* Make all applications respect ASCII codes */
    case KC_J:
      if (record->event.pressed) {
        if (keyboard_report->mods & (MOD_BIT(KC_LCTL)))
        {
            ascii_code_ctrl = true;
            unregister_code(KC_LCTL);
            register_code(KC_ENT);
            return false;
        }
        else if (ascii_code_ctrl)
        {
            register_code(KC_ENT);
            return false;
        }

      }
      else {
        unregister_code(KC_ENT);
      }
      break;

    /* Make all applications respect ASCII codes */
    case KC_H:
      if (record->event.pressed) {
        if (keyboard_report->mods & (MOD_BIT(KC_LCTL)))
        {
            ascii_code_ctrl = true;
            unregister_code(KC_LCTL);
            register_code(KC_BSPC);
            return false;
        }
        else if (ascii_code_ctrl)
        {
            register_code(KC_BSPC);
            return false;
        }

      }
      else {
        unregister_code(KC_BSPC);
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


  }
  return true;
};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    /* Shall also set a specific mode */
    case BASE_WIN:
      //rgblight_disable();
      break;
    case MOUSE:
      //rgblight_enable();
      break;
  }
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_WIN] = LAYOUT(
    LT(ESC_FN, KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
    LT(TAB_FN, KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT,
    KC_LSFT, KC_X, KC_C, KC_D, KC_V, KC_Z, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
        KC_LGUI, KC_LALT, /*        */ (KC_SPC), MO(MOUSE), KC_RALT),

  [BASE_MAC] = LAYOUT(
    LT(ESC_FN, KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
    LT(TAB_FN, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
        KC_LALT, KC_LGUI, /*        */ (KC_SPC), MO(MOUSE), KC_RALT),

  [TAB_FN] = LAYOUT(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, RESET,
    KC_TRNS, MO(MOUSE), RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
    MO(MOUSE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, P_PARENT, KC_TRNS, KC_TRNS, KC_TRNS,
        TO(BASE_WIN), TO(BASE_MAC), /*        */ MO(MOUSE), MO(MOUSE), KC_RALT),

  [ESC_FN] = LAYOUT(
    KC_TRNS, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_RESIZE_PANE_H, TMUX_RESIZE_PANE_J, TMUX_RESIZE_PANE_K, TMUX_RESIZE_PANE_L, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LALT, KC_LGUI, /*        */ (KC_SPC), TG(MOUSE), KC_RALT),

  [MOUSE] = LAYOUT(
    TO(BASE_WIN), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
    TG(MOUSE), KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_R, KC_T, KC_Y, KC_WH_U, KC_MS_U, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_BTN1, KC_BTN2, KC_WH_D, KC_F, KC_G, KC_MS_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(BASE_WIN), KC_NO,
        KC_LALT, KC_LGUI, /*        */ TG(MOUSE), TG(MOUSE), KC_RALT),
};
