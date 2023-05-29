/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "./private.h"

//
// unicode
//
#ifdef UNICODEMAP_ENABLE

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        dprintf("DIP switch status: %d\n", index);
        set_unicode_input_mode(active ? UNICODE_MODE_WINCOMPOSE : UNICODE_MODE_LINUX);
        return false;
    }
    return true;
}

enum unicode_names {
    a_UMLAUT,
    A_UMLAUT,
    o_UMLAUT,
    O_UMLAUT,
    a_RING,
    A_RING,
    EURO,
    NUM_UNICODES
};

const uint32_t unicode_map[NUM_UNICODES] PROGMEM = {
    [a_UMLAUT] = 0x00E4,
    [A_UMLAUT] = 0x00C4,
    [o_UMLAUT] = 0x00F6,
    [O_UMLAUT] = 0x00D6,
    [a_RING]   = 0x00E5,
    [A_RING]   = 0x00C5,
    [EURO]     = 0x20AC,
};

#define KC_AUML XP(a_UMLAUT, A_UMLAUT)
#define KC_OUML XP(o_UMLAUT, O_UMLAUT)
#define KC_ARNG XP(a_RING,   A_RING)

#endif // UNICODEMAP_ENABLE

//
// keymap
//
#define ESC_FN1  LT(_FN1, KC_ESC)
// #define ESC_LEAD LT(BASE, KC_NO)

enum layer_names {
    BASE,
    _FN1,
    NUM_LAYERS
};

// clang-format off
const uint16_t keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [BASE] = LAYOUT_ansi_61(
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        ESC_FN1,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        SC_LSPO,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,                      SC_RSPC,
        KC_LCTL,  KC_LGUI,  KC_LALT,                   KC_SPC,                                       MO(_FN1), KC_RALT,  KC_APP,   KC_RCTL
    ),

    [_FN1] = LAYOUT_ansi_61(
        QK_LEAD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,
        KC_PSCR,  KC_F13,  KC_UP,   X(EURO), KC_P7,   KC_P8,   KC_P9,   KC_INS,  KC_HOME, KC_PGUP, XXXXXXX, KC_ARNG,  KC_MPRV, KC_MNXT,
        _______,  KC_LEFT, KC_DOWN, KC_RGHT, KC_P4,   KC_P5,   KC_P6,   KC_DEL,  KC_END,  KC_PGDN, KC_OUML, KC_AUML,           _______,
        _______,  XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX, XXXXXXX, XXXXXXX,                    _______,
        _______,  _______, _______,                   KC_P0,                                       _______, _______,  KC_RGUI, _______
    ),
};
// clang-format on

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
// lighting
//
#ifdef RGB_MATRIX_ENABLE

#define KEY_AZURE       0x99F5FF
#define KEY_BLACK       0x000000
#define KEY_BLUE        0x0000FF
#define KEY_CHARTREUSE  0x80FF00
#define KEY_CORAL       0xFF7C4D
#define KEY_CYAN        0x00FFFF
#define KEY_GOLD        0xFFD900
#define KEY_GOLDENROD   0xD9A521
#define KEY_GREEN       0x00FF00
#define KEY_MAGENTA     0xFF00FF
#define KEY_ORANGE      0xFF8000
#define KEY_PINK        0xFF80BF
#define KEY_PURPLE      0x7A00FF
#define KEY_RED         0xFF0000
#define KEY_SPRINGGREEN 0x00FF80
#define KEY_TEAL        0x008080
#define KEY_TURQUOISE   0x476E6A
#define KEY_WHITE       0xFFFFFF
#define KEY_YELLOW      0xFFFF00

enum ledlayer_names {
    LED_CAPS_WORD,
    NUM_LED_LAYERS
};

// clang-format off
static const uint32_t ledmap[NUM_LAYERS + NUM_LED_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [BASE] = LAYOUT_ansi_61(
        KEY_WHITE,   KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,
        KEY_WHITE,   KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,
        KEY_PURPLE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,              KEY_WHITE,
        KEY_WHITE,   KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE,                          KEY_WHITE,
        KEY_WHITE,   KEY_WHITE,  KEY_WHITE,                          KEY_WHITE,                                                 KEY_PURPLE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE
    ),

    [_FN1] = LAYOUT_ansi_61(
        KEY_YELLOW,   KEY_TEAL,    KEY_TEAL,   KEY_TEAL,   KEY_TEAL,    KEY_TEAL,    KEY_TEAL,    KEY_TEAL,   KEY_TEAL,   KEY_TEAL,   KEY_TEAL,   KEY_TEAL,    KEY_TEAL,   KEY_TEAL,
        KEY_CYAN,     KEY_TEAL,    KEY_RED,    KEY_TEAL,   KEY_BLUE,    KEY_BLUE,    KEY_BLUE,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_BLACK,  KEY_TEAL,    KEY_CYAN,   KEY_CYAN,
        KEY_PURPLE,   KEY_RED,     KEY_RED,    KEY_RED,    KEY_BLUE,    KEY_BLUE,    KEY_BLUE,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_TEAL,   KEY_TEAL,                KEY_CYAN,
        KEY_WHITE,    KEY_BLACK,   KEY_BLACK,  KEY_BLACK,  KEY_BLUE,    KEY_BLUE,    KEY_BLUE,    KEY_BLUE,   KEY_BLACK,  KEY_BLACK,  KEY_BLACK,                           KEY_WHITE,
        KEY_WHITE,    KEY_WHITE,   KEY_WHITE,                           KEY_BLUE,                                                    KEY_PURPLE,   KEY_WHITE,  KEY_WHITE,  KEY_WHITE
    ),

    [LED_CAPS_WORD] = LAYOUT_ansi_61(
        KEY_RED,     KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_TEAL,   KEY_RED,    KEY_BLUE,
        KEY_RED,     KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_RED,    KEY_RED,    KEY_RED,
        KEY_PURPLE,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_RED,   KEY_RED,                KEY_RED,
        KEY_WHITE,   KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_RED,   KEY_RED,   KEY_RED,                           KEY_WHITE,
        KEY_WHITE,   KEY_WHITE, KEY_WHITE,                       KEY_WHITE,                                           KEY_PURPLE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE
    ),
};
// clang-format on

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
#ifdef CAPS_WORD_ENABLE
    if (is_caps_word_on()) {
        layer = LED_CAPS_WORD;
    }
#endif

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index >= led_min && led_index < led_max && led_index != NO_LED) {
                uint32_t color = pgm_read_dword(&ledmap[layer][row][col]);
                rgb_matrix_set_color(
                    led_index,
                    (color >> 16) & 0xFF,
                    (color >> 8) & 0xFF,
                    color & 0xFF
                );
            }
        }
    }
    return false;
}

#endif // RGB_MATRIX_ENABLE


//
// leader key
//
#ifdef LEADER_ENABLE

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_P, KC_E)) {
        SEND_STRING(PERSONAL_EMAIL);
    } else if (leader_sequence_two_keys(KC_W, KC_E)) {
        SEND_STRING(WORK_EMAIL);
    } else if (leader_sequence_two_keys(KC_R, KC_B)) {
        soft_reset_keyboard();
    } else if (leader_sequence_two_keys(KC_F, KC_L)) {
        reset_keyboard();
    } else if (leader_sequence_two_keys(KC_B, KC_L)) {
        rgb_matrix_toggle();
    } else if (leader_sequence_two_keys(KC_S, KC_R)) {
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
}

#endif // LEADER_ENABLE
