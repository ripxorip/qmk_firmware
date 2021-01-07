/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "ripxorip.h"

/* FIXME add layers for tmux vim movement (see below ctrl arrows)
 * and add Fn layer using the same logic as for the numpad. Use
 * 'home mod' for keys above home row...
 */

enum layers
{
    /* Base layers */
    BASE_QWERTY = 0,
    BASE_CM_DHm,
    BASE_NOOB,

        /* Shift layer */
    UPPER,
    LOWER,
    FN_LAYER,
    TMUX_NAV,

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
    TMUX_0,
    TMUX_1,
    TMUX_2,
    TMUX_3,
    TMUX_4,
    TMUX_5,
    TMUX_6,
    TMUX_7,
    TMUX_8,
    TMUX_9,
    VIM_SPLIT,
    VIM_VSPLIT,
    TMUX_CREATE,
    TMUX_SPLIT,
    TMUX_VSPLIT,
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
         _______, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                        KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN , _______,
         _______, HML(KC_A   , KC_R   , KC_S   , KC_T   , KC_G),                      HMR(KC_M   , KC_N   , KC_E   , KC_I   , KC_O), _______,
         _______, KC_Z, KC_X, LT(FN_LAYER, KC_C), LT(TMUX_NAV, KC_D), KC_V,           KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, _______,
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

    [FN_LAYER] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_F7, KC_F8, KC_F9, KC_F10, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_F4, KC_F5, KC_F6, KC_F11, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),
    [TMUX_NAV] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        TMUX_8, TMUX_0, TMUX_1, TMUX_2, TMUX_3, _______,
         _______, _______, _______, TMUX_CREATE, _______, _______,                    LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), _______, _______,
         _______, _______, _______, _______, _______, _______,                        TMUX_9, TMUX_4, TMUX_5, TMUX_6, TMUX_7, _______,
                           _______, _______,                                                            VIM_SPLIT, VIM_VSPLIT,
                                                _______, _______,                 TMUX_SPLIT, TMUX_VSPLIT,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),

    [UTIL_NUM] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_7,    KC_8,    KC_9,    _______, _______,
         _______, _______, KC_DOWN, KC_UP, KC_UP,     _______,                        _______, KC_4,    KC_5,    KC_6,    KC_0,    _______,
         _______, _______, _______, _______, _______, _______,                        _______, KC_1,    KC_2,    KC_3,    _______, _______,
                           _______, _______,                                                            KC_COMM, KC_DOT,
                                                _______, _______,                 _______, KC_0,
                                                    _______, _______,         _______, _______,
                                                    _______, _______,         _______, _______
    ),

    /* This layer is intended for navigation both keyboard and mouse */
    [LOWER] = RIPXORIP_5x6_WRAPPER(
         _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
         _______, _______, KC_MS_WH_LEFT, KC_MS_U, KC_MS_WH_RIGHT, _______,           LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), _______, _______,
         _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______,                        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
         _______, _______, KC_WH_D, KC_BTN2, KC_WH_U, _______,                        KC_HOME, KC_PGDOWN, KC_ESC, KC_PGUP, KC_END, _______,
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
        rgblight_sethsv_noeeprom(148, 170, 127);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        layer_move(BASE_CM_DHm);
    }
    else if (BASE_QWERTY == current_layer)
    {
        rgblight_sethsv_noeeprom(201, 200, 127);
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

        case TMUX_0:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"0");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_1:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"1");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_2:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"2");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_3:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"3");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_4:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"4");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_5:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"5");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_6:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"6");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_7:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"7");
            } else {
                // when keycode P_PARENT is released
            }
            break;


        case TMUX_8:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"8");
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case TMUX_9:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"9");
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case TMUX_CREATE:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"c");
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case TMUX_SPLIT:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"s");
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case TMUX_VSPLIT:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL("a")"v");
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case VIM_VSPLIT:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(":vspl"SS_TAP(X_ENTER)"");
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case VIM_SPLIT:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(":spl"SS_TAP(X_ENTER)"");
            } else {
                // when keycode P_PARENT is released
            }
            break;


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
