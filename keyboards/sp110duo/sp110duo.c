/*
Copyright 2023 TylerK

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "sp110duo.h"
#include <string.h>
#include <math.h>
#include "quantum.h"
#include <hal_pal.h>
#include <hal.h>
#include "stdlib.h"
#include "config.h"
#include "display.h"
//#include "ui/ui.h"
#include "color.h"
#include "print.h"

#include <qp.h>
#include <qp_lvgl.h>

<<<<<<< Updated upstream
static bool display_enabled;

/* Public function to be used to check if display is active */
bool is_display_enabled(void){
    return display_enabled;
}

/* default encoder keys */
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code_delay(KC_RIGHT, 10);
        } else {
            tap_code_delay(KC_LEFT, 10);
        }
    }
    return true;
}

/* Caps Lock processing */
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res && display_enabled) {
        display_process_caps(led_state.caps_lock);
    }

    return res;
}

void housekeeping_task_kb(void) {
    if (display_enabled){
        display_housekeeping_task();
    }

    housekeeping_task_user();
}

=======
>>>>>>> Stashed changes
void keyboard_post_init_kb(void) {
    // Enable RGB current limiter and wait for a bit before allowing RGB to continue.
    setPinOutput(RGB_ENABLE_PIN);
    writePinHigh(RGB_ENABLE_PIN);
    wait_ms(20);

    // RGB_EN also controls LCD power, so check if RGB is enabled and then turn on the LCD and offload to display init
    //if (readPin(RGB_ENABLE_PIN)) {
        display_init_kb();
        wait_ms(30);
    //}

    // Offload to the user func 
    keyboard_post_init_user();
}

<<<<<<< Updated upstream
=======
void housekeeping_task_kb(void) {

    #ifdef QUANTUM_PAINTER_ENABLE
        display_housekeeping_task();
    #endif //QUANTUM_PAINTER_ENABLE
}
>>>>>>> Stashed changes
