/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "ripxorip.h"

enum layers
{
    /* Base layers */
    BASE_QWERTY = 0,
    BASE_CM_DHm,
    BASE_NOOB,

    /* Util layers */
    UTIL_SYM,
    UTIL_NUM,
    /* Layer shifting, flashing, LEDS, etc.. */
    UTIL_MISC,
    UTIL_MACRO,
    UTIL_NAV,
    UTIL_FN,
    UTIL_NOOB
};

const uint8_t HIGHEST_BASE = BASE_NOOB+1;

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
#define __BASE_THUMBS__                         _______, LCTL(KC_A),                                 KC_LBRC, KC_RBRC, \
                                            LT(UTIL_SYM, KC_BSPC), LT(UTIL_NUM, KC_SPC),      LT(UTIL_NAV, KC_BSPC), LT(UTIL_MACRO, KC_ENT), \
                                                         MO(UTIL_MISC), _______,             _______, _______, \
                                                            _______, _______,                  _______, _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_CM_DHm] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _____________CM_DHm_L1_____________        ,                        _____________CM_DHm_R1_____________        , _______,
         _______, HML(_____________CM_DHm_L2_____________   ),                        HMR(_____________CM_DHm_R2_____________   ), _______,
         _______, _____________CM_DHm_L3_____________        ,                        _____________CM_DHm_R3_____________        , _______,
                                                                  __BASE_THUMBS__
    ),
    [BASE_QWERTY] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _____________QWERTY_L1_____________        ,                        _____________QWERTY_R1_____________        , _______,
         _______, HML(_____________QWERTY_L2_____________)   ,                        HMR(_____________QWERTY_R2_____________   ), _______,
         _______, _____________QWERTY_L3_____________        ,                        _____________QWERTY_R3_____________        , _______,
                                                                  __BASE_THUMBS__
    ),

    [BASE_NOOB] = RIPXORIP_5x6_WRAPPER(
         KC_ESC, ____________NUMBERS_L______________        ,                        ____________NUMBERS_R______________        , KC_EQL,
         LT(UTIL_NOOB, KC_TAB), _____________QWERTY_L1_____________,                 _____________QWERTY_R1_____________        , KC_MINS,
         KC_LCTL, _____________QWERTY_L2_____________       ,                        _____________QWERTY_R2_____________        , KC_QUOT,
         KC_LSFT, _____________QWERTY_L3_____________       ,                        _____________QWERTY_R3_____________        , KC_BSLASH,
                           KC_LSFT, KC_RBRC,                                                            KC_LBRC, KC_RBRC,
                                                KC_LALT, KC_SPC,                     KC_LCTL, MO(UTIL_NOOB),
                                                    MO(UTIL_MISC), KC_LALT,         KC_LALT, KC_LGUI,
                                                    MO(UTIL_MISC), _______,      KC_E, KC_F
    ),

    /* ----END BASE---- */

    [UTIL_NUM] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_7,    KC_8,    KC_9,    _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_4,    KC_5,    KC_6,    KC_0,    _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_1,    KC_2,    KC_3,    _______, _______,
                           _______, _______,                                                            KC_0,    _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),

    [UTIL_SYM] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
         _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),        LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,
         _______, KC_TAB, KC_LSFT, LSFT(KC_LBRC), LSFT(KC_RBRC), _______,            _______, KC_LBRC, KC_RBRC, LSFT(KC_MINS), KC_QUOT, _______,
         _______, KC_ESC, KC_ESC, _______, _______, _______,                        _______, KC_MINS, KC_EQL, KC_GRV, KC_BSLASH, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______

    ),
    [UTIL_FN] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, __________________F_L______________        ,                        __________________F_R______________        , _______,
         _______, KC_F11, KC_F12, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [UTIL_MACRO] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, UC(L'å'), _______,
         _______, _______, _______, _______, _______, _______,                        _______, LCTL(KC_A), _______, UC(L'ö'), UC(L'ä'), _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, MO(UTIL_FN),                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [UTIL_NAV] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, KC_MS_U, KC_WH_U, _______,                        _______, KC_PGUP, KC_UP, _______, _______, _______,
         _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
         _______, _______, _______, _______, KC_WH_D, _______,                        _______, KC_PGDOWN, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                KC_BTN1, KC_BTN2,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [UTIL_NOOB] = RIPXORIP_5x6_WRAPPER(
         _______, __________________F_L______________        ,                        __________________F_R______________,               KC_GRV,
         _______, _______, _______, _______, _______, _______,                        LCTL(KC_BSPC), _______, _______, _______, _______, UC(L'å'),
         _______, _______, _______, _______, _______, _______,                        KC_LEFT  , KC_DOWN  , KC_UP  , KC_RIGHT  ,UC(L'ö'),UC(L'ä'),
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,           _______, _______,
                                                    _______, _______,           _______, _______
    ),
    [UTIL_MISC] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, RESET,            NEXT_BASE, _______,
                                                    _______, _______,           _______, _______
    )
};

/* Set layer according to index */
static void set_layer(void)
{
    if (BASE_CM_DHm == current_layer)
    {
        rgblight_sethsv_noeeprom(201, 200, 127);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        layer_move(BASE_CM_DHm);
    }
    else if (BASE_QWERTY == current_layer)
    {
        rgblight_sethsv_noeeprom(148, 170, 127);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        layer_move(BASE_QWERTY);
    }
    else if (BASE_NOOB == current_layer)
    {
        rgblight_sethsv_noeeprom(85, 200, 170);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        layer_move(BASE_NOOB);
    }
    else
    {
        /* DO NOTHING */
    }
}

void keyboard_post_init_user(void)
{
    /* Set static blue LEDs */
    current_layer = BASE_QWERTY;
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
    /* Noob layers stuff... */
    if (current_layer == BASE_NOOB)
    {
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
        }
    }
    return true;
};
