/* Copyright 2020 Atte Virtanen
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

#include "atte.h"

// clang-format off
const uint16_t keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [BASE] = LAYOUT_ansi_61(
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        ESC_FN1,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,                      KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                   KC_SPC,                                       MO(_FN1), KC_RALT,  KC_APP,   KC_RCTL
    ),

    [_FN1] = LAYOUT_ansi_61(
        QK_LEAD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,
        KC_PSCR,  KC_F13,  KC_UP,   X(EURO), KC_P7,   KC_P8,   KC_P9,   KC_INS,  KC_HOME, KC_PGUP, XXXXXXX, KC_ARNG,  KC_MPRV, KC_MNXT,
        _______,  KC_LEFT, KC_DOWN, KC_RGHT, KC_P4,   KC_P5,   KC_P6,   KC_DEL,  KC_END,  KC_PGDN, KC_OUML, KC_AUML,           KC_MPLY,
        _______,  XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX, XXXXXXX, XXXXXXX,                    _______,
        _______,  _______, _______,                   KC_P0,                                       _______, _______,  KC_RGUI, _______
    ),
};
// clang-format on

#ifdef RGB_MATRIX_CUSTOM_USER
// clang-format off
const uint32_t rgbmaps[NUM_RGB_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
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

    [CAPS_WORD_LAYER] = LAYOUT_ansi_61(
        KEY_RED,     KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_BLUE,  KEY_TEAL,   KEY_RED,    KEY_BLUE,
        KEY_RED,     KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_RED,    KEY_RED,    KEY_RED,
        KEY_PURPLE,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_RED,   KEY_RED,                KEY_RED,
        KEY_WHITE,   KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_TEAL,  KEY_RED,   KEY_RED,   KEY_RED,                           KEY_WHITE,
        KEY_WHITE,   KEY_WHITE, KEY_WHITE,                       KEY_WHITE,                                           KEY_PURPLE,  KEY_WHITE,  KEY_WHITE,  KEY_WHITE
    ),

    [LEADER_LAYER] = LAYOUT_ansi_61(
        KEY_RED,     KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,
        KEY_RED,     KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,
        KEY_PURPLE,  KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,                KEY_RED,
        KEY_RED,     KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,    KEY_RED,                            KEY_RED,
        KEY_RED,     KEY_RED,    KEY_RED,                            KEY_RED,                                                   KEY_PURPLE,  KEY_RED,    KEY_RED,    KEY_RED
      ),
};
// clang-format on
#endif // RGB_MATRIX_CUSTOM_USER
