#include "atte.h"

//
// unicode
//
#ifdef UNICODEMAP_ENABLE

const uint32_t unicode_map[NUM_UNICODES] PROGMEM = {
    [a_UMLAUT] = 0x00E4, [A_UMLAUT] = 0x00C4, [o_UMLAUT] = 0x00F6, [O_UMLAUT] = 0x00D6, [a_RING] = 0x00E5, [A_RING] = 0x00C5, [EURO] = 0x20AC,
};

#    ifdef OS_DETECTION_ENABLE
#        include "os_detection.h"
void housekeeping_task_user(void) {
    switch (detected_host_os()) {
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        case OS_WINDOWS:
        default:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            break;
    }
}
#    endif // OS_DETECTION_ENABLE

#endif // UNICODEMAP_ENABLE

//
// keymap
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#if defined(LEADER_ENABLE) && defined(ESC_LEAD)
        case ESC_LEAD:
            if (record->tap.count) {
                if (record->event.pressed) {
                    dprint("ESC lead tap\n");
                    leader_start();
                }
            } else {
                if (record->event.pressed) {
                    dprint("ESC lead hold\n");
                    register_code(KC_ESC)
                } else {
                    dprint("ESC lead release\n");
                    unregister_code(KC_ESC);
                }
            }
            return false;
#endif
    }
    return true;
}

//
// RGB
//
#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
}
#endif // RGB_MATRIX_ENABLE

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        if (active) {
            rgb_matrix_enable_noeeprom();
        } else {
            rgb_matrix_disable_noeeprom();
        }
        return false;
    }
    return true;
}
#endif // DIP_SWITCH_ENABLE

//
// leader key
//
#ifdef LEADER_ENABLE

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_R, KC_B)) {
        soft_reset_keyboard();
    } else if (leader_sequence_two_keys(KC_F, KC_L)) {
        reset_keyboard();
    }
#    ifdef RGB_MATRIX_ENABLE
    else if (leader_sequence_two_keys(KC_B, KC_L)) {
        rgb_matrix_toggle();
    }
#    endif
    else if (leader_sequence_two_keys(KC_S, KC_R)) {
        tap_code16(LALT(KC_PRINT_SCREEN));
    } else if (leader_sequence_two_keys(KC_P, KC_A)) {
        tap_code(KC_PAUSE);
    } else if (leader_sequence_two_keys(KC_S, KC_L)) {
        tap_code(KC_SCROLL_LOCK);
    } else if (leader_sequence_two_keys(KC_N, KC_L)) {
        tap_code(KC_NUM_LOCK);
    } else if (leader_sequence_two_keys(KC_C, KC_L)) {
        tap_code(KC_CAPS_LOCK);
    } else if (leader_sequence_three_keys(KC_K, KC_P, KC_A)) {
        tap_code(KC_KP_PLUS);
    } else if (leader_sequence_three_keys(KC_K, KC_P, KC_S)) {
        tap_code(KC_KP_MINUS);
    } else if (leader_sequence_three_keys(KC_K, KC_P, KC_M)) {
        tap_code(KC_KP_ASTERISK);
    } else if (leader_sequence_three_keys(KC_K, KC_P, KC_D)) {
        tap_code(KC_KP_SLASH);
    } else if (leader_sequence_three_keys(KC_K, KC_P, KC_E) || leader_sequence_three_keys(KC_K, KC_P, KC_R)) {
        tap_code(KC_KP_ENTER);
    } else if (leader_sequence_two_keys(KC_D, KC_B)) {
        debug_enable = !debug_enable;
    } else if (leader_sequence_three_keys(KC_D, KC_B, KC_M)) {
        debug_matrix = !debug_matrix;
    } else if (leader_sequence_three_keys(KC_D, KC_B, KC_K)) {
        debug_keyboard = !debug_keyboard;
    }
#    ifdef PERSONAL_EMAIL
    else if (leader_sequence_two_keys(KC_P, KC_E)) {
        SEND_STRING(PERSONAL_EMAIL);
    }
#    endif // PERSONAL_EMAIL
#    ifdef WORK_EMAIL
    else if (leader_sequence_two_keys(KC_W, KC_E)) {
        SEND_STRING(WORK_EMAIL);
    }
#    endif // WORK_EMAIL
}

#endif // LEADER_ENABLE
