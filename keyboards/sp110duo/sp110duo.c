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

#include <qp.h>
#include <qp_lvgl.h>

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

static int8_t rotations = 0;
bool lvgl_encoder = false;
static lv_group_t *g;

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case RGB_TOG1:
            if (record->event.pressed) {
                rgb_matrix_increase_flags();
            }
            return false;
        case LVGL_CLOCKWISE:
            if (record->event.pressed) {
                rotations++;
                dprintf("Rotations: %d\n", rotations);
            }
            break;
        case LVGL_COUNTER_CLOCKWISE:
            if (record->event.pressed) {
                rotations--;
                dprintf("Rotations: %d\n", rotations);
            }
            break;
        case LVGL_ENCODER_BUTTON: {
            if (record->event.pressed) {
                lvgl_encoder = true;
            } else {
                lvgl_encoder = false;
            }
        }
    }
    return true;
}

void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

// LVGL Encoder Control
lv_indev_t * indev_encoder;

void encoder_read_2(lv_indev_drv_t *drv, lv_indev_data_t *data) {
    data->enc_diff = rotations;
    rotations = 0;
    if (lvgl_encoder) {
        data->state = LV_INDEV_STATE_PRESSED;
        dprintf("pressed");
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}
// LVGL Encoder Control


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

    // Register Encoder and create default group
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = encoder_read_2;
    lv_indev_drv_register(&indev_drv);

    g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_t *cur_drv = NULL;
    for (;;) {
        cur_drv = lv_indev_get_next(cur_drv);
        if (!cur_drv) {
            break;
        }
        if (cur_drv->driver->type == LV_INDEV_TYPE_ENCODER) {
            lv_indev_set_group(cur_drv, g);
        }
    }   

    // Offload to the user func 
    keyboard_post_init_user();

    // Run UI 
    ui_init();
}

void housekeeping_task_kb(void) {

    housekeeping_task_user();
}