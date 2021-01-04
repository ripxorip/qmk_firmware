/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "ripxorip.h"

enum layers
{
    /* Base layers */
    BASE_QWERTY = 0,
    BASE_CM_DHm,
    BASE_NOOB,

    /* Shift layers */
    SHIFT_LEFT_RAISE,
    SHIFT_RIGHT_RAISE,
    SHIFT_LEFT_SINK,
    SHIFT_RIGHT_SINK,

    /* Util layers (legacy) */
    UPPER,
    LOWER,
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
    NEXT_BASE = SAFE_RANGE,
    STRUCT_REF
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

#define HOME_MOD_LEFT(K1, K2, K3, K4, K5)       CTL_T(K1), SFT_T(K2), GUI_T(K3), LT(UTIL_NUM, K4), K5
#define HOME_MOD_RIGHT(K1, K2, K3, K4, K5)      K1 , ALT_T(K2), GUI_T(K3), SFT_T(K4), CTL_T(K5)

#define HML(...) HOME_MOD_LEFT(__VA_ARGS__)
#define HMR(...) HOME_MOD_RIGHT(__VA_ARGS__)


/* Common thumb cluster for the base layouts */
#define __BASE_THUMBS__                        KC_LALT, KC_TAB,                                 KC_A, KC_LCTL, \
                        LT(UPPER, KC_ESC), LT(LOWER, KC_SPC),      LT(LOWER, KC_BSPC), LT(UPPER, KC_ENT), \
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
         KC_ESC, ____________NUMBERS_L______________         ,                        ____________NUMBERS_R______________       ,  KC_MINS,
         KC_TAB, _____________QWERTY_L1_____________         ,                        _____________QWERTY_R1_____________        , KC_EQL,
         KC_LCTL, HML(_____________QWERTY_L2_____________)   ,                        HMR(_____________QWERTY_R2_____________   ), KC_QUOT,
         KC_LSFT, _____________QWERTY_L3_____________        ,                        _____________QWERTY_R3_____________        , KC_BSLASH,
                                                                  __BASE_THUMBS__
    ),

    [BASE_NOOB] = RIPXORIP_5x6_WRAPPER(
         KC_ESC, ____________NUMBERS_L______________        ,                        ____________NUMBERS_R______________        , KC_MINS,
         LT(UTIL_NOOB, KC_TAB), _____________QWERTY_L1_____________,                 _____________QWERTY_R1_____________        , KC_EQL,
         KC_LCTL, HML(_____________QWERTY_L2_____________)       ,                   HMR(_____________QWERTY_R2_____________)        , KC_QUOT,
         KC_LSFT, _____________QWERTY_L3_____________       ,                        _____________QWERTY_R3_____________        , KC_BSLASH,
                           UC(L'å'), UC(L'ä'),                                                            UC(L'ö'), KC_RBRC,
                                                LT(UTIL_NOOB, KC_SPC), LT(UTIL_NOOB, KC_SPC),        KC_BSPC, LT(UPPER, KC_ENT),
                                                    MO(UTIL_MISC), KC_LALT,                             KC_LALT, KC_LGUI,
                                                    MO(UTIL_MISC), _______,                             KC_E, KC_F
    ),

    /* ----END BASE---- */

    /* Are these really needed? */

    [SHIFT_LEFT_RAISE] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [SHIFT_LEFT_SINK] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [SHIFT_RIGHT_RAISE] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, NEXT_BASE,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [SHIFT_RIGHT_SINK] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    /* ---- END SHIFT ---- */

    [UTIL_NUM] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_7,    KC_8,    KC_9,    _______, _______,
         _______, _______, KC_DOWN, KC_UP, KC_UP, _______,                        _______, KC_4,    KC_5,    KC_6,    KC_0,    _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_1,    KC_2,    KC_3,    _______, _______,
                           _______, _______,                                                            KC_COMM, KC_DOT,
                                                _______, _______,                 _______, KC_0,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),

    /* This layer is intended for navigation both keyboard and mouse */
    [LOWER] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, KC_MS_WH_LEFT, KC_MS_U, KC_MS_WH_RIGHT, _______,           _______, KC_HOME, KC_UP, KC_END, _______, _______,
         _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______,                        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
         _______, _______, KC_WH_D, KC_BTN2, KC_WH_U, _______,                        _______, KC_PGDOWN, KC_ESC, KC_PGUP, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    /* This layer is almost final take a look at the cheat notes */
    [UPPER] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
         _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),       KC_GRV, LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_8), UC(L'å'), _______,
         _______, KC_EQL, KC_MINS, LSFT(KC_EQL), LSFT(KC_MINS), LSFT(KC_GRV),       KC_QUOT, LSFT(KC_9), LSFT(KC_0), LSFT(KC_QUOT), KC_SCLN, _______,
         _______, KC_TAB, UC(L'ö'), KC_LBRC, KC_RBRC, LSFT(KC_BSLASH),              LSFT(KC_6), LSFT(KC_7), UC(L'ä'), STRUCT_REF, KC_BSLASH, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, NEXT_BASE,
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
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, UC(L'å'),
         _______, _______, _______, _______, _______, _______,                        _______, LCTL(KC_A), _______, _______, UC(L'ö'), UC(L'ä'),
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, MO(UTIL_FN),                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [UTIL_NAV] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, KC_MS_U, KC_WH_U, _______,                        LCTL(KC_BSPC), KC_PGUP, KC_UP, _______, _______, _______,
         _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END, _______,
         _______, _______, _______, _______, KC_WH_D, _______,                        KC_HOME, KC_PGDOWN, KC_END, _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                KC_BTN1, KC_BTN2,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [UTIL_NOOB] = RIPXORIP_5x6_WRAPPER(
         _______, __________________F_L______________        ,                        __________________F_R______________,               KC_GRV,
         _______, _______, _______, _______, _______, _______,                        LCTL(KC_BSPC), _______, _______, _______, _______, UC(L'å'),
         _______, _______, _______, LCTL(KC_A), _______, _______,                        KC_LEFT  , KC_DOWN  , KC_UP  , KC_RIGHT  ,UC(L'ö'),UC(L'ä'),
         _______, _______, _______, _______, _______, _______,                        _______, LCTL(KC_A), LCTL(KC_A), _______, _______, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, NEXT_BASE,
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
        rgblight_sethsv_noeeprom(106, 200, 170);
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
    current_layer = BASE_CM_DHm;
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
        case STRUCT_REF:
            if (record->event.pressed) {
                SEND_STRING("->");
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
    return true;
}
