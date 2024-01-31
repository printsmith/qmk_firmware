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
#include "ui/ui.h"
#include "color.h"
#include "print.h"

#include <qp.h>
#include <qp_lvgl.h>

static bool display_enabled;

/* Public function to be used to check if display is active */
bool is_display_enabled(void){
    return display_enabled;
}

//----------------------------------------------------------
// Initialise Keyboard 
//----------------------------------------------------------
void keyboard_post_init_kb(void) {
    // Initialize display as off
    display_enabled = false;

    debug_enable=true;
    
    // Enable RGB current limiter and wait for a bit before allowing RGB to continue.
    // In next board version, this will be an RC timer circuit and not have GPIO control
    setPinOutput(RGB_ENABLE_PIN);
    writePinHigh(RGB_ENABLE_PIN);
    wait_ms(50);

    // LCD PWR piggybacks on RGB_ENABLE_PIN for now, will change in next rev
    // Call display initalization function in display.c
    display_enabled = display_init_kb();

    // Allow for user post-init
    //keyboard_post_init_user();

}

//----------------------------------------------------------
// Housekeeping
//----------------------------------------------------------
void housekeeping_task_kb(void) {

    // Flag for turning on and off peripherals (LCD & RGB)
    bool peripherals_on = last_input_activity_elapsed() < LCD_ACTIVITY_TIMEOUT;   

    // Enable/Diable peripherals
    if (peripherals_on) {
        // RGB pin on
        writePinHigh(RGB_ENABLE_PIN);
        // Since the pin was low, display needs to be initialized, so set flag to false
        //display_enabled= false;
        if (rgb_matrix_is_enabled() != peripherals_on) {
            // Enable RGB
            wait_ms(10);
            rgb_matrix_enable_noeeprom();            
        }
        // Check display sttus
        if (is_display_enabled()) {
            // If display is on, continue with display housekeeping
            display_housekeeping_task();
        } else {
            // If display is off, call display initalization function in display.c
            display_enabled = display_on();
        }
    } else {
        // Turn off RGB pin
        writePinLow(RGB_ENABLE_PIN);
        // Disable PWM output for RGB
        if (rgb_matrix_is_enabled() != peripherals_on) {
            rgb_matrix_disable_noeeprom();
        }
        // Set display enabled flag to false
        display_enabled = false;
    }
    dprintf("Activity: %lu Peripherals On: %u Display Enabled: %u\n",last_input_activity_elapsed(), peripherals_on, display_enabled);
}

