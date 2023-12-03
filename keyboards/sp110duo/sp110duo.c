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
#include "hal.h"
#include "stdlib.h"
#include "config.h"
#include "qp.h"

void keyboard_post_init_kb(void) {
    // Enable RGB current limiter and wait for a bit before allowing RGB to continue
    setPinOutput(RGB_ENABLE_PIN);
    writePinHigh(RGB_ENABLE_PIN);
    wait_ms(100);

    // Offload to the user func
    keyboard_post_init_user();
}

/*
static painter_device_t lcd;
static painter_image_handle_t image;
// static painter_font_handle_t font;

// Set screen size
const int HEIGHT = 240;
const int WIDTH = 320;
*/
/*
void keyboard_post_init_kb(void) {

    // Let the LCD get some power...
    wait_ms(150);

    // Initialise the LCD
    lcd = qp_st7789_make_spi_device(HEIGHT, WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 1, 3);

    qp_init(lcd, QP_ROTATION_180);

    // Turn on the LCD and clear the display
    qp_power(lcd, true);

    // begin drawing space
    qp_rect(lcd, 0, 0, HEIGHT, WIDTH, 127, 230, 255, true);

    //image = qp_load_image_mem(gfx_kicub);
    
    if (image != NULL) {
        // qp_drawimage(lcd, 0, 0, image);
        qp_drawimage_recolor(lcd, 2, 8, image, 0, 255, 0, 127, 230, 255);
        // qp_drawimage_recolor(lcd, 0, 0, image, 0, 255, 255, 0, 255, 0);

        qp_flush(lcd);
    }

    // font = qp_load_font_mem(font_iosevka11);
    // if (font != NULL) {
    //     qp_drawtext(lcd, 0, 0, font, "QUANTUM PAINTER @ RP2040");
    // }

    // Allow for user post-init
    keyboard_post_init_user();
}
*/
void housekeeping_task_user(void) {

}