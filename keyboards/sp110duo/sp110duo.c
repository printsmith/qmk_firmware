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

//#include "sp110duo.h"

#include <string.h>
#include <math.h>
#include "quantum.h"
#include <hal_pal.h>
#include "hal.h"
#include "stdlib.h"
#include "config.h"
#include "qp.h"
#include "graphics/qmk_logo.qgf.h"

painter_device_t lcd;
painter_image_handle_t splash;
//static painter_font_handle_t font;

void keyboard_post_init_kb(void) {
    splash = qp_load_image_mem(gfx_qmk_logo);
    // Enable RGB current limiter and wait for a bit before allowing RGB to continue
    setPinOutput(RGB_ENABLE_PIN);
    //writePinHigh(RGB_ENABLE_PIN);
    writePinLow(RGB_ENABLE_PIN);
    wait_ms(100);
    
    // Debug enables
    debug_enable=true;
    //debug_matrix=true;

    // LCD tasks
    // Let the LCD get some power...
    wait_ms(150);

    // Initialise the LCD
    lcd = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    qp_init(lcd, QP_ROTATION_180);

    // Turn on the LCD and clear the display
    qp_power(lcd, true);
    //qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT, 0, 0, 255, true);
    qp_drawimage(lcd, 0, 0, splash);
    


    // Offload to the user func
    keyboard_post_init_user();
}


//----------------------------------------------------------
// Housekeeping
/*
void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();
        // Draw 8px-wide rainbow filled rectangles down the left side of the display
        for (int i = 0; i < 239; i+=8) {
            qp_rect(lcd, 0, i, 7, i+7, i, 255, 255, true);
        }
        qp_flush(lcd);
    }
}
*/
