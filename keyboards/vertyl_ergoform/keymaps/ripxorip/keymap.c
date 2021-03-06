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

#include "ripxorip.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [BASE] = LAYOUT(
            BASE_R1,
            BASE_R2,
            BASE_R3,
            _______, _______, _______, _______,
            BASE_M1, BASE_M2, BASE_M3, BASE_M4
    ),

    [LOWER] = LAYOUT(
            LOWER_R1,
            LOWER_R2,
            LOWER_R3,
            _______, _______, _______, _______,
            LOWER_M1, LOWER_M2, LOWER_M3, LOWER_M4
    ),

    [UPPER] = LAYOUT(
            UPPER_R1,
            UPPER_R2,
            UPPER_R3,
            _______, _______, _______, _______,
            UPPER_M1, UPPER_M2, UPPER_M3, UPPER_M4
    ),

    [UTIL_NUM] = LAYOUT(
            UTIL_NUM_R1,
            UTIL_NUM_R2,
            UTIL_NUM_R3,
            _______, _______, _______, _______,
            UTIL_NUM_M1, UTIL_NUM_M2, UTIL_NUM_M3, UTIL_NUM_M4
    ),

    [FN_LAYER] = LAYOUT(
            FN_R1,
            FN_R2,
            FN_R3,
            _______, _______, _______, _______,
            FN_M1, FN_M2, FN_M3, FN_M4
    ),

    [TMUX_NAV] = LAYOUT(
            TMUX_NAV_R1,
            TMUX_NAV_R2,
            TMUX_NAV_R3,
            _______, _______, _______, _______,
            TMUX_NAV_M1, TMUX_NAV_M2, TMUX_NAV_M3, TMUX_NAV_M4
    ),
    [VIM_NAV] = LAYOUT(
            VIM_NAV_R1,
            VIM_NAV_R2,
            VIM_NAV_R3,
            _______, _______, _______, _______,
            VIM_NAV_M1, VIM_NAV_M2, VIM_NAV_M3, VIM_NAV_M4
    ),
    [FUSION_360] = LAYOUT(
            FUSION_360_R1,
            FUSION_360_R2,
            FUSION_360_R3,
            _______, _______, _______, _______,
            FUSION_360_M1, FUSION_360_M2, FUSION_360_M3, FUSION_360_M4
    ),
};
