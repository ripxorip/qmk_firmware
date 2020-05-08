/* Copyright 2020 Philip Karlsson Gisslow
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE,
    FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    CUSTOM_RUN_PAUSE = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [BASE] = LAYOUT(LCTL(KC_F5), KC_F5, KC_F4, KC_F10, KC_F11, LSFT(KC_F11), MO(FN)),
    [FN] = LAYOUT(RESET, RESET, KC_C, KC_D, KC_E, KC_F, KC_G)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTOM_RUN_PAUSE:
            if (record->event.pressed) {
                static bool run = false;
                if (run)
                    SEND_STRING(SS_TAP(X_F5));
                else
                    SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_F5)SS_UP(X_LCTL));
                run = !run;
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_R);
        } else {
            tap_code(KC_WH_L);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_KP_PLUS)SS_UP(X_LCMD));
        } else {
            SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_KP_MINUS)SS_UP(X_LCMD));
        }
    }
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
