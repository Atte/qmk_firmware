#pragma once

#include QMK_KEYBOARD_H
#include "./private.h"

//
// unicode
//
#ifdef UNICODEMAP_ENABLE

enum unicode_names { a_UMLAUT, A_UMLAUT, o_UMLAUT, O_UMLAUT, a_RING, A_RING, EURO, NUM_UNICODES };

#    define KC_AUML XP(a_UMLAUT, A_UMLAUT)
#    define KC_OUML XP(o_UMLAUT, O_UMLAUT)
#    define KC_ARNG XP(a_RING, A_RING)

#endif // UNICODEMAP_ENABLE

//
// keymap
//
enum layer_names { BASE, _FN1, NUM_LAYERS };

#define ESC_FN1 LT(_FN1, KC_ESC)
// #define ESC_LEAD LT(BASE, KC_NO)

//
// lighting
//
#ifdef RGB_MATRIX_CUSTOM_USER

#    define KEY_AZURE 0x99F5FF
#    define KEY_BLACK 0x000000
#    define KEY_BLUE 0x0000FF
#    define KEY_CHARTREUSE 0x80FF00
#    define KEY_CORAL 0xFF7C4D
#    define KEY_CYAN 0x00FFFF
#    define KEY_GOLD 0xFFD900
#    define KEY_GOLDENROD 0xD9A521
#    define KEY_GREEN 0x00FF00
#    define KEY_MAGENTA 0xFF00FF
#    define KEY_ORANGE 0xFF8000
#    define KEY_PINK 0xFF80BF
#    define KEY_PURPLE 0x7A00FF
#    define KEY_RED 0xFF0000
#    define KEY_SPRINGGREEN 0x00FF80
#    define KEY_TEAL 0x008080
#    define KEY_TURQUOISE 0x476E6A
#    define KEY_WHITE 0xFFFFFF
#    define KEY_YELLOW 0xFFFF00

enum rgb_layer_names {
    RGB_LAYERS_OFFSET = NUM_LAYERS - 1,
#    ifdef CAPS_WORD_ENABLE
    CAPS_WORD_LAYER,
#    endif
    NUM_RGB_LAYERS
};

#    ifdef CAPS_WORD_ENABLE
#        define RGB_LAYERS_CAPS_WORD CAPS_WORD_LAYER
#    endif // CAPS_WORD_ENABLE

#endif // RGB_MATRIX_CUSTOM_USER
