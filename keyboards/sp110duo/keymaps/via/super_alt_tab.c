/*
 * Function for Super Alt/Tab, makes a single key does ALT+TAB
 * From: https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
 */
 
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;		

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

// This will do most of the grunt work with the keycodes.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { 
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

// The very important timer.
void matrix_scan_user(void) { 
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}