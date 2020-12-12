/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "ripxorip.h"

enum layers
{
    /* Base layers */
    BASE_QWERTY = 0,
    BASE_CM_DHm,

    /* Util layers */
    UTIL_SYM,
    UTIL_NUM,
    /* Layer shifting, flashing, LEDS, etc.. */
    UTIL_MISC
};

const uint8_t HIGHEST_BASE = BASE_CM_DHm+1;

enum ripxorip_keycodes
{
    NEXT_BASE = SAFE_RANGE
};

static uint8_t current_layer = 0;

/* EMPTY BASE:
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
*/

/* Home row modifiers */

#define HOME_MOD_LEFT(K1, K2, K3, K4, K5)       CTL_T(K1), SFT_T(K2), GUI_T(K3), ALT_T(K4), K5
#define HOME_MOD_RIGHT(K1, K2, K3, K4, K5)      K1 , ALT_T(K2), GUI_T(K3), SFT_T(K4), CTL_T(K5)

#define HML(...) HOME_MOD_LEFT(__VA_ARGS__)
#define HMR(...) HOME_MOD_RIGHT(__VA_ARGS__)


/* Common thumb cluster for the base layouts */
#define __BASE_THUMBS__                         LT(UTIL_NUM, KC_BSPC), LT(UTIL_SYM, KC_SPC),      KC_ENT, _______, \
                                                            _______,       _______,                  _______, _______, \
                                                            MO(UTIL_MISC), _______,                  _______, _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_CM_DHm] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _____________CM_DHm_L1_____________        ,                        _____________CM_DHm_R1_____________        , _______,
         _______, HML(_____________CM_DHm_L2_____________   ),                        HMR(_____________CM_DHm_R2_____________   ), _______,
         _______, _____________CM_DHm_L3_____________        ,                        _____________CM_DHm_R3_____________        , _______,
                           _______, _______,                                                            _______, _______,
                                                                  __BASE_THUMBS__
    ),
    [BASE_QWERTY] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _____________QWERTY_L1_____________        ,                        _____________QWERTY_R1_____________        , _______,
         _______, HML(_____________QWERTY_L2_____________)   ,                        HMR(_____________QWERTY_R2_____________   ), _______,
         _______, _____________QWERTY_L3_____________        ,                        _____________QWERTY_R3_____________        , _______,
                           _______, _______,                                                            _______, _______,
                                                                  __BASE_THUMBS__
    ),

    [UTIL_NUM] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_7,    KC_8,    KC_9,    _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_4,    KC_5,    KC_6,    _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_1,    KC_2,    KC_3,    _______, _______,
                           _______, _______,                                                            KC_0,    _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [UTIL_SYM] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),        LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,
         _______, KC_TAB, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, KC_ESC, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______

    ),
    [UTIL_MISC] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, RESET,           NEXT_BASE, _______
    )
};

/* Set layer according to index */
static void set_layer(void)
{
    if (BASE_CM_DHm == current_layer)
    {
        rgblight_sethsv_noeeprom(201, 200, 100);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        layer_move(BASE_CM_DHm);
    }
    else if (BASE_QWERTY == current_layer)
    {
        rgblight_sethsv_noeeprom(148, 170, 170);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        layer_move(BASE_QWERTY);
    }
    else
    {
        /* DO NOTHING */
    }
}

void keyboard_post_init_user(void)
{
    /* Set static blue LEDs */
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    set_layer();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NEXT_BASE:
      if (record->event.pressed) {
          current_layer = (current_layer + 1) % HIGHEST_BASE;
          set_layer();
      }
      else
      {
          /* DO NOTHING */
      }
      break;
  }
  return true;
};

#if 0
/* Below is kept for reference only */
enum layers
{
    BASE = 0,
    MOTION,
    SPEC_CHAR,
    GUI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = RIPXORIP_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_EQL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LSFT ,KC_RBRC,                                                       KC_LBRC, KC_RBRC,
                                      KC_BSPC ,KC_SPC,                         KC_LCTL, MO(MOTION),
                                      LCTL(KC_A),KC_LALT,                            KC_LALT,  KC_LGUI,
                                      KC_E, MO(GUI),                              KC_E, KC_F
   ),

  /* This mode shall have support for removing words quickly using old fashion editing commands e.g. ctrl backspace in a VIM agnostic style */
  [MOTION] = RIPXORIP_5x6(
     KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                    KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  ,KC_F11,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         LCTL(KC_BSPC)  , KC_U  , KC_I  , KC_O  , KC_P  ,UC(L'å'),
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_LEFT  , KC_DOWN  , KC_UP  , KC_RIGHT  ,UC(L'ö'),UC(L'ä'),
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_LBRC, KC_RBRC,
                                      KC_LALT ,KC_SPC,                         KC_SPC, KC_SPC,
                                      KC_C,KC_D,                              KC_C,  KC_D,
                                      KC_E, RESET,                            KC_E, KC_F
   ),

  [SPEC_CHAR] = RIPXORIP_5x6(
     KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_GRV  ,LSFT(KC_GRV),
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , UC(L'å'),
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_LEFT  , KC_DOWN  , KC_UP  , KC_RIGHT  ,UC(L'ö'),UC(L'ä'),
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH, KC_NO,
                      KC_LBRC,KC_RBRC,                                                       KC_LBRC, KC_RBRC,
                                      KC_LALT ,KC_SPC,                         KC_SPC, KC_SPC,
                                      KC_C,KC_D,                              KC_C,  KC_D,
                                      KC_E, RESET,                            KC_E, KC_F
   ),

  [GUI] = RIPXORIP_5x6(
     KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_GRV  ,LSFT(KC_GRV),
     KC_TAB , KC_Q  , LALT(KC_F4)  , KC_E  , KC_R  , KC_T  ,                         LCTL(KC_BSPC)  , KC_U  , KC_I  , KC_O  , KC_P  , KC_LBRC,
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         LGUI(KC_LEFT)  , LGUI(KC_DOWN)  , LGUI(KC_UP)  , LGUI(KC_RIGHT)  ,KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH, KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_LBRC, KC_RBRC,
                                      KC_LALT ,KC_SPC,                         KC_SPC, KC_SPC,
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
#endif
