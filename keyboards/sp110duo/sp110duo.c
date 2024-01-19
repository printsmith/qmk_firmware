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
#include "ui/ui.h"
#include "color.h"

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

void keyboard_post_init_kb(void) {

    #if CONSOLE_ENABLE
        debug_enable = true;
    #endif // CONSOLE_ENABLE

    // Enable RGB current limiter and wait for a bit before allowing RGB to continue
    setPinOutput(RGB_ENABLE_PIN);
    //writePinHigh(RGB_ENABLE_PIN);
    writePinLow(RGB_ENABLE_PIN);
    
    // Let the LCD get some power...
    wait_ms(150);

    // Display is enabled, offload to display init func
    display_init_kb();

    // Offload to the user func 
    keyboard_post_init_user();

    // Run UI 
    ui_init();
}

void housekeeping_task_kb(void) {

    housekeeping_task_user();
}