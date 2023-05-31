RGB_MATRIX_EFFECT(RGB_LAYERS)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern const uint32_t ledmaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM;

static bool RGB_LAYERS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
#ifdef RGB_LAYERS_CAPS_WORD
    if (is_caps_word_on()) {
        layer = RGB_LAYERS_CAPS_WORD;
    }
#endif

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index >= led_min && led_index < led_max && led_index != NO_LED) {
                uint32_t color = pgm_read_dword(&ledmaps[layer][row][col]);
                rgb_matrix_set_color(
                    led_index,
                    (color >> 16) & 0xFF,
                    (color >> 8) & 0xFF,
                    color & 0xFF
                );
            }
        }
    }

  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
