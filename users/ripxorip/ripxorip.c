#include "ripxorip.h"

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
        case FUSION_360_ORBIT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                SEND_STRING(SS_DELAY(200));
                register_code(KC_BTN3);
            }
            else
            {
                unregister_code(KC_LSFT);
                unregister_code(KC_BTN3);
            }
            break;
        case VIM_NUM_NAV_UP:
            if (record->event.pressed) {
                SEND_STRING(""SS_TAP(X_UP)"");
            }
            else
            {
                layer_clear();
                layer_move(BASE);
            }
            break;
        case VIM_WIN_NAV_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_W);
                unregister_code(KC_LCTL);
                unregister_code(KC_W);
                register_code(KC_H);
            }
            else
            {
                unregister_code(KC_H);
            }
            break;
        case VIM_WIN_NAV_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_W);
                unregister_code(KC_LCTL);
                unregister_code(KC_W);
                register_code(KC_L);
            }
            else
            {
                unregister_code(KC_L);
            }
            break;
        case VIM_WIN_NAV_UP:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_W);
                unregister_code(KC_LCTL);
                unregister_code(KC_W);
                register_code(KC_K);
            }
            else
            {
                unregister_code(KC_K);
            }
            break;
        case VIM_WIN_NAV_DOWN:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_W);
                unregister_code(KC_LCTL);
                unregister_code(KC_W);
                register_code(KC_J);
            }
            else
            {
                unregister_code(KC_J);
            }
            break;
        case VIM_NUM_NAV_ESC:
            if (record->event.pressed) {
                SEND_STRING(""SS_TAP(X_ESC)"");
            }
            else
            {
                layer_clear();
                layer_move(BASE);
            }
            break;
        case VIM_NUM_NAV_DOWN:
            if (record->event.pressed) {
                SEND_STRING(""SS_TAP(X_DOWN)"");
            }
            else
            {
                layer_clear();
                layer_move(BASE);
            }
            break;
        case Q_LEADER:
            if (record->event.pressed) {
                register_code(KC_Q);
            }
            else
            {
                unregister_code(KC_Q);
                layer_clear();
                layer_move(BASE);
            }
            break;
        case FUSION_360_PAN:
            if (record->event.pressed) {
                register_code(KC_BTN3);
            }
            else
            {
                unregister_code(KC_BTN3);
            }
        case ALT_TAB_START:
            if (record->event.pressed) {
                register_code(KC_LALT);
                layer_clear();
                layer_move(APP_SHIFT);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            else
            {
            }
            break;
        case ALT_TAB_END:
            if (record->event.pressed) {
                unregister_code(KC_LALT);
                layer_clear();
                layer_move(BASE);
            }
            else
            {
            }
            break;
        case ALT_TAB_NEXT:
            if (record->event.pressed) {
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            else
            {
            }
            break;
        case ALT_TAB_PREVIOUS:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            else
            {
            }
            break;
        case TAB_SHIFT_START:
            if (record->event.pressed) {
            }
            else
            {
                layer_clear();
                layer_move(TAB_SHIFT);
                register_code(KC_LCTL);
                register_code(KC_TAB);
                unregister_code(KC_LCTL);
                unregister_code(KC_TAB);
            }
            break;
        case VIM_EXIT:
            if (record->event.pressed) {
            }
            else
            {
                SEND_STRING(":qa"SS_TAP(X_ENTER)"");
                layer_clear();
                layer_move(BASE);
            }
            break;
    }
    return true;
}
