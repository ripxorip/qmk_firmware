#pragma once

#include QMK_KEYBOARD_H

#define _______ KC_TRNS

bool process_record_user(uint16_t keycode, keyrecord_t *record);

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
    FUSION_360_ORBIT,
    FUSION_360_PAN,
    VIM_NUM_NAV_UP,
    VIM_NUM_NAV_DOWN,
    VIM_NUM_NAV_ESC,

    VIM_WIN_NAV_LEFT,
    VIM_WIN_NAV_DOWN,
    VIM_WIN_NAV_UP,
    VIM_WIN_NAV_RIGHT,

    Q_LEADER,
    ALT_TAB_START,
    ALT_TAB_NEXT,
    ALT_TAB_PREVIOUS,
    ALT_TAB_END,
    TAB_SHIFT_START,
    VIM_EXIT,
    STRUCT_REF
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE,
    UPPER,
    LOWER,
    FN_LAYER,
    TMUX_NAV,
    VIM_NUM_NAV,
    VIM_WIN_NAV,
    FUSION_360,
    LEADER,
    APP_SHIFT,
    TAB_SHIFT,
    UTIL_NUM
};

/*************************************************************
 *
 * THE LAYERS
 *
 *************************************************************/

#define BASE_R1   LT(UTIL_NUM, KC_Q)   , KC_W   , KC_F   , KC_P   , KC_B , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN
#define BASE_R2   CTL_T(KC_A) , SFT_T(KC_R) , LT(TMUX_NAV, KC_S), LT(UTIL_NUM, KC_T) , GUI_T(KC_G), ALT_T(KC_M)   , ALT_T(KC_N)   , GUI_T(KC_E)   , SFT_T(KC_I)   , CTL_T(KC_O)
#define BASE_R3   LT(VIM_WIN_NAV, KC_Z), KC_X, LT(FN_LAYER, KC_C), KC_D, KC_V,            KC_K, KC_H   , KC_COMM, KC_DOT , KC_SLSH
#define BASE_M1   LT(UPPER, KC_ESC)
#define BASE_M2   LT(LOWER, KC_SPC)
#define BASE_M3   LT(LOWER, KC_BSPC)
#define BASE_M4   LT(UPPER, KC_ENT)

#define LOWER_R1   LCTL(KC_Q), KC_MS_WH_LEFT, KC_MS_U, KC_MS_WH_RIGHT, _______,  LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), _______
#define LOWER_R2   KC_TAB, KC_LSFT, KC_LALT, TO(VIM_NUM_NAV), _______,                        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_LSFT
#define LOWER_R3   KC_TAB, KC_WH_D, KC_BTN2, KC_WH_U, _______,                        KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, KC_END
#define LOWER_M1   _______
#define LOWER_M2   _______
#define LOWER_M3   _______
#define LOWER_M4   KC_TAB

#define UPPER_R1   LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),       KC_GRV, LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_8), UC(L'å')
#define UPPER_R2   KC_EQL, KC_MINS, LSFT(KC_EQL), LSFT(KC_MINS), LSFT(KC_GRV),       KC_QUOT, LSFT(KC_9), LSFT(KC_0), LSFT(KC_QUOT), KC_DEL
#define UPPER_R3   KC_TAB, UC(L'ö'), KC_LBRC, KC_RBRC, LSFT(KC_BSLASH),              LSFT(KC_6), LSFT(KC_7), UC(L'ä'), STRUCT_REF, KC_BSLASH
#define UPPER_M1   _______
#define UPPER_M2   _______
#define UPPER_M3   _______
#define UPPER_M4   UC_MOD

#define FN_R1   RESET, _______, _______, _______, _______,                          _______, KC_F7, KC_F8, KC_F9, KC_F10
#define FN_R2   _______, _______, _______, _______, _______,                        _______, KC_F4, KC_F5, KC_F6, KC_F11
#define FN_R3     TO(FUSION_360), _______, _______, _______, _______,                        _______, KC_F1, KC_F2, KC_F3, KC_F12
#define FN_M1   TO(BASE)
#define FN_M2   _______
#define FN_M3   _______
#define FN_M4   _______

#define UTIL_NUM_R1   _______, _______, _______, _______, _______,                        _______, KC_7,    KC_8,    KC_9,    _______
#define UTIL_NUM_R2   _______, KC_DOWN, KC_UP, KC_UP,     _______,                        _______, KC_4,    KC_5,    KC_6,    KC_0
#define UTIL_NUM_R3     KC_DOWN, _______, _______, _______, _______,                        _______, KC_1,    KC_2,    KC_3,    _______
#define UTIL_NUM_M1   KC_COMM
#define UTIL_NUM_M2   KC_DOT
#define UTIL_NUM_M3   _______
#define UTIL_NUM_M4   KC_0

#define VIM_NUM_NAV_R1   _______, _______, _______, _______, _______,                        _______, KC_7,    KC_8,    KC_9,    _______
#define VIM_NUM_NAV_R2   _______, VIM_NUM_NAV_DOWN, VIM_NUM_NAV_UP, KC_DOT, _______,             _______, KC_4,    KC_5,    KC_6,    KC_0
#define VIM_NUM_NAV_R3   VIM_NUM_NAV_DOWN, KC_MINS, LSFT(KC_EQL), LSFT(KC_8), KC_SLSH,                 _______, KC_1,    KC_2,    KC_3,    _______
#define VIM_NUM_NAV_M1   VIM_NUM_NAV_ESC
#define VIM_NUM_NAV_M2   TO(BASE)
#define VIM_NUM_NAV_M3   _______
#define VIM_NUM_NAV_M4   KC_0

#define VIM_WIN_NAV_R1   _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______
#define VIM_WIN_NAV_R2   _______, _______, _______, _______, _______,                        VIM_WIN_NAV_LEFT, VIM_WIN_NAV_DOWN, VIM_WIN_NAV_UP, VIM_WIN_NAV_RIGHT, _______
#define VIM_WIN_NAV_R3   _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______
#define VIM_WIN_NAV_M1   VIM_VSPLIT
#define VIM_WIN_NAV_M2   VIM_SPLIT
#define VIM_WIN_NAV_M3   _______
#define VIM_WIN_NAV_M4   _______

#define TMUX_NAV_R1   _______, _______, _______, _______, _______,                        TMUX_8, TMUX_0, TMUX_1, TMUX_2, TMUX_3
#define TMUX_NAV_R2   _______, _______, _______, TMUX_CREATE, _______,                    LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), _______
#define TMUX_NAV_R3   _______, _______, _______, _______, _______,                        TMUX_9, TMUX_4, TMUX_5, TMUX_6, TMUX_7
#define TMUX_NAV_M1   VIM_VSPLIT
#define TMUX_NAV_M2   VIM_SPLIT
#define TMUX_NAV_M3   TMUX_SPLIT
#define TMUX_NAV_M4   TMUX_VSPLIT

#define FUSION_360_R1   KC_Q, _______, _______, KC_P, _______,                               _______, _______, _______, _______, _______
#define FUSION_360_R2   KC_BSPC, _______, FUSION_360_PAN, FUSION_360_ORBIT, KC_L,                               _______, _______, _______, _______, _______
#define FUSION_360_R3   _______, _______, KC_C, KC_D, KC_I,                               _______, _______, _______, _______, _______
#define FUSION_360_M1   KC_ESC
#define FUSION_360_M2   KC_ENT
#define FUSION_360_M3   _______
#define FUSION_360_M4   TO(BASE)

#define LEADER_R1   Q_LEADER, _______, _______, TO(VIM_NUM_NAV), _______,                          _______, _______, _______, _______, VIM_EXIT
#define LEADER_R2   _______, _______, _______, _______, _______,                        _______, ALT_TAB_START, _______, _______, _______
#define LEADER_R3   _______, _______, TO(FN_LAYER), _______, _______,                        _______, _______, TAB_SHIFT_START, _______, _______
#define LEADER_M1   TO(BASE)
#define LEADER_M2   ALT_TAB_START
#define LEADER_M3   _______
#define LEADER_M4   _______

#define APP_SHIFT_R1   _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______
#define APP_SHIFT_R2   _______, _______, ALT_TAB_PREVIOUS, ALT_TAB_NEXT, _______,                        _______, ALT_TAB_NEXT, ALT_TAB_PREVIOUS, _______, _______
#define APP_SHIFT_R3   _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______
#define APP_SHIFT_M1   ALT_TAB_END
#define APP_SHIFT_M2   ALT_TAB_END
#define APP_SHIFT_M3   ALT_TAB_END
#define APP_SHIFT_M4   ALT_TAB_END

#define TAB_SHIFT_R1   _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______
#define TAB_SHIFT_R2   _______, _______, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), _______,                        _______, LCTL(KC_TAB), LCTL(LSFT(KC_TAB)), _______, _______
#define TAB_SHIFT_R3   _______, _______, _______, _______, _______,                        _______, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), _______, _______
#define TAB_SHIFT_M1   TO(BASE)
#define TAB_SHIFT_M2   TO(BASE)
#define TAB_SHIFT_M3   TO(BASE)
#define TAB_SHIFT_M4   TO(BASE)

