#pragma once

#include "./clear_effects.h"

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT

#define TAP_CODE_DELAY 10

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define UNICODE_KEY_WINC KC_RGUI

#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_RGB_LAYERS
