RGB_MATRIX_EFFECT(pink_gradient)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool pink_gradient(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
	for (uint8_t i = 0; i < 72; i++) {
		rgb_matrix_set_color(i, 0x00, 3*i, 0x00);
	}
  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
