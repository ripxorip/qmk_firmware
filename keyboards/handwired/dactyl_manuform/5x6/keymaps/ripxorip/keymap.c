/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "ripxorip.h"

enum layers
{
    BASE = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = RIPXORIP_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                                      KC_SPC ,KC_SPC,                         KC_SPC, KC_SPC,
                                      KC_C,KC_D,                              KC_C,  KC_D,
                                      KC_E, RESET,                            KC_E, KC_F
  )
};

void keyboard_post_init_user(void)
{
    /* Set static blue LEDs */
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(170, 170, 100);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

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
  }

  return true;
};


