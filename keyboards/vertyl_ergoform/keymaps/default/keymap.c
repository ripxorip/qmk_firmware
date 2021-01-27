/* Copyright 2021 ripxorip
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _______ KC_TRNS

enum ripxorip_keycodes
{
    TMUX_0 = SAFE_RANGE,
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
    KVM_SET_WIN_MAIN,
    KVM_SET_WORK,
    KVM_SET_LINUX,
    KVM_SET_MAC,
    STRUCT_REF
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE,
    UPPER,
    LOWER,
    FN_LAYER,
    TMUX_NAV,
    UTIL_NUM
};

/* Empty layer for reference
  _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______,
                        _______, _______,                                                                _______, _______,
                                              _______, _______,         _______, _______
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [BASE] = LAYOUT(
        KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN ,
        CTL_T(KC_A)   , SFT_T(KC_R)   , GUI_T(KC_S)   , LT(UTIL_NUM, KC_T)   , KC_G,                      ALT_T(KC_M)   , ALT_T(KC_N)   , GUI_T(KC_E)   , SFT_T(KC_I)   , CTL_T(KC_O),
        KC_Z, KC_X, LT(FN_LAYER, KC_C), LT(TMUX_NAV, KC_D), KC_V,                                         KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,
                        _______, _______,                                                                                        _______, _______,
                                                LT(UPPER, KC_ESC), LT(LOWER, KC_SPC),                  LT(LOWER, KC_BSPC), LT(UPPER, KC_ENT)
    ),

    [LOWER] = LAYOUT(
         _______, KC_MS_WH_LEFT, KC_MS_U, KC_MS_WH_RIGHT, _______,           LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), _______,
         KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______,                        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_LSFT,
         _______, KC_WH_D, KC_BTN2, KC_WH_U, _______,                        KC_HOME, KC_PGDOWN, KC_ESC, KC_PGUP, KC_END,
                           _______, _______,                                          _______, _______,
                                                _______, _______,                 _______, KC_TAB
    ),

    [UPPER] = LAYOUT(
         LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),       KC_GRV, LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_8), UC(L'å'),
         KC_EQL, KC_MINS, LSFT(KC_EQL), LSFT(KC_MINS), LSFT(KC_GRV),       KC_QUOT, LSFT(KC_9), LSFT(KC_0), LSFT(KC_QUOT), KC_SCLN,
         KC_TAB, UC(L'ö'), KC_LBRC, KC_RBRC, LSFT(KC_BSLASH),              LSFT(KC_6), LSFT(KC_7), UC(L'ä'), STRUCT_REF, KC_BSLASH,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, UC_MOD
    ),

    [UTIL_NUM] = LAYOUT(
         _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______,
         _______, KC_DOWN, KC_UP, KC_UP,     _______,                        _______, KC_4,    KC_5,    KC_6,    KC_0,
         _______, _______, _______, _______, _______,                        _______, KC_1,    KC_2,    KC_3,    _______,
                           _______, _______,                                          KC_COMM, KC_DOT,
                                                _______, _______,                 _______, KC_0
    ),

    [FN_LAYER] = LAYOUT(
         RESET, _______, _______, _______, _______,                          _______, KC_F7, KC_F8, KC_F9, KC_F10,
         _______, _______, _______, _______, _______,                        _______, KC_F4, KC_F5, KC_F6, KC_F11,
         _______, _______, _______, _______, _______,                        _______, KC_F1, KC_F2, KC_F3, KC_F12,
                           _______, _______,                                                            _______, _______,
                                                _______, _______,                 _______, _______
    ),
    [TMUX_NAV] = LAYOUT(
         _______, _______, _______, _______, _______,                        TMUX_8, TMUX_0, TMUX_1, TMUX_2, TMUX_3,
         _______, _______, TMUX_CREATE, _______, _______,                    LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), _______,
         _______, _______, _______, _______, _______,                        TMUX_9, TMUX_4, TMUX_5, TMUX_6, TMUX_7,
                           _______, _______,                                         _______, _______,
                                                VIM_VSPLIT, VIM_SPLIT,                 TMUX_SPLIT, TMUX_VSPLIT
    ),
};

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


        case KVM_SET_WIN_MAIN:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL(SS_LALT("1")));
                SEND_STRING(SS_LCTRL(SS_LALT("u")));
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case KVM_SET_WORK:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL(SS_LALT("1")));
                SEND_STRING(SS_LCTRL(SS_LALT("l")));
                SEND_STRING(SS_LCTRL(SS_LALT("2")));
            } else {
                // when keycode P_PARENT is released
            }
            break;

        case KVM_SET_MAC:
            if (record->event.pressed) {
                // when keycode P_PARENT is pressed
                SEND_STRING(SS_LCTRL(SS_LALT("1")));
                SEND_STRING(SS_LCTRL(SS_LALT("y")));
                SEND_STRING(SS_LCTRL(SS_LALT("3")));
            } else {
                // when keycode P_PARENT is released
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
    return true;
}
