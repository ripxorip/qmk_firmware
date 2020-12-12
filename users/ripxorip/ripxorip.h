#pragma once

/* Helpers */
#define ________  KC_TRNS
#define _________ KC_TRNS

#define RIPXORIP_5x6(\
  L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
            L42, L43,                                              R42, R43,           \
                      L44, L45,                          R40, R41,                     \
                                L53, L55,      R50, R52,                               \
                                L52, L54,      R51, R53                                \
  ) \
  { \
    { L00,   L01,   L02, L03, L04, L05 }, \
    { L10,   L11,   L12, L13, L14, L15 }, \
    { L20,   L21,   L22, L23, L24, L25 }, \
    { L30,   L31,   L32, L33, L34, L35 }, \
    { KC_NO, KC_NO, L42, L43, L44, L45 }, \
    { KC_NO, KC_NO, L52, L53, L54, L55 }, \
                                          \
    { R00, R01, R02, R03, R04,   R05   }, \
    { R10, R11, R12, R13, R14,   R15   }, \
    { R20, R21, R22, R23, R24,   R25   }, \
    { R30, R31, R32, R33, R34,   R35   }, \
    { R40, R41, R42, R43, KC_NO, KC_NO }, \
    { R50, R51, R52, R53, KC_NO, KC_NO }  \
}

#define RIPXORIP_5x6_WRAPPER(...) RIPXORIP_5x6(__VA_ARGS__)

/* QWERTY */
#define _____________QWERTY_L1_____________  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _____________QWERTY_L2_____________  KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _____________QWERTY_L3_____________  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _____________QWERTY_R1_____________  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define _____________QWERTY_R2_____________  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define _____________QWERTY_R3_____________  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

/* COLEMAKE-DHm */
#define _____________CM_DHm_L1_____________  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B
#define _____________CM_DHm_L2_____________  KC_A   , KC_R   , KC_S   , KC_T   , KC_G
#define _____________CM_DHm_L3_____________  KC_Z   , KC_X   , KC_C   , KC_D   , KC_V

#define _____________CM_DHm_R1_____________  KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN
#define _____________CM_DHm_R2_____________  KC_M   , KC_N   , KC_E   , KC_I   , KC_O
#define _____________CM_DHm_R3_____________  KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH

/* Numbers and fn for noobs */
#define ____________NUMBERS_L______________  KC_1, KC_2, KC_3, KC_4, KC_5
#define ____________NUMBERS_R______________  KC_6, KC_7, KC_8, KC_9, KC_0

#define __________________F_L______________  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define __________________F_R______________  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#if 0
/* Below is kept for reference */
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#undef MK_MOMENTARY_ACCEL
#define MK_3_SPEED 1

#define LAYOUT_ergodox_pretty_wrapper(...)  LAYOUT_ergodox_pretty(__VA_ARGS__)
#define LAYOUT_wrapper(...)                 LAYOUT(__VA_ARGS__)
#define LAYOUT_5x6_wrapper(...)             LAYOUT_5x6(__VA_ARGS__)
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)
#define MOUSE_L LSFT(KC_WH_D)
#define MOUSE_R LSFT(KC_WH_U)
#define OSX_LOCK LCTL(LGUI(KC_Q))

// layout parts for easy reuse between keyboard keymaps
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  1  |  2  |  3  |  4  |  5  |   |  6  |  7  |  8  |  9  |  0  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________NUMBERS_L__________________  KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_R__________________  KC_6, KC_7, KC_8, KC_9, KC_0

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// | F1  | F2  | F3  | F4  | F5  |   | F6  | F7  | F8  | F9  | F10 |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ______________________F_L__________________  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define ______________________F_R__________________  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U  |  I  |  O  |  P  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  S  |  D  |  F  |  G  |   |  H  |  J  |  K  |  L  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________QWERTY_L1_________________  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _________________QWERTY_L2_________________  KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _________________QWERTY_L3_________________  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _________________QWERTY_R1_________________  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define _________________QWERTY_R2_________________  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define _________________QWERTY_R3_________________  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

#define _____________MOD_QWERTY_L2_________________  CTL_T(KC_A), SFT_T(KC_S), GUI_T(KC_D), ALT_T(KC_F), KC_G
#define _____________MOD_QWERTY_R2_________________  KC_H       , ALT_T(KC_J), GUI_T(KC_K), SFT_T(KC_L), CTL_T(KC_SCLN)

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  !  |  @  |  {  |  }  |  _  |   |  \  |  7  |  8  |  9  |     |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  #  |  $  |  (  |  )  |  -  |   |  =  |  4  |  5  |  6  |  |  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  %  |  ^  |  [  |  ]  |  +  |   |  *  |  1  |  2  |  3  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________SYMBOL_L1_________________  KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_UNDS
#define _________________SYMBOL_L2_________________  KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_MINS
#define _________________SYMBOL_L3_________________  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_PLUS

#define _________________SYMBOL_R1_________________  KC_BSLS, KC_P7, KC_P8 , KC_P9, KC_PAST
#define _________________SYMBOL_R2_________________  KC_EQL , KC_P4, KC_P5, KC_P6, KC_PPLS
#define _________________SYMBOL_R3_________________  KC_ASTR, KC_P1, KC_P2, KC_P3, KC_PMNS
#endif
