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

#include <qp.h>
#include <qp_lvgl.h>

static bool display_enabled;

/* Public function for use in keymaps */
bool is_display_enabled(void){
    return display_enabled;
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
    if (display_enabled) {
        display_housekeeping_task();
    }

    housekeeping_task_user();
}

void keyboard_post_init_kb(void) {
    display_enabled = false;

    // Enable RGB current limiter and wait for a bit before allowing RGB to continue
    setPinOutput(RGB_ENABLE_PIN);
    //writePinHigh(RGB_ENABLE_PIN);
    writePinLow(RGB_ENABLE_PIN);
    
    // Let the LCD get some power...
    wait_ms(150);

    // Display is enabled, offload to display init func
    display_enabled = display_init_kb();

    // Offload to the user func
    keyboard_post_init_user();
}

