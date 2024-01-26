// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "sp110duo.h"
#include "display.h"
#include "qp.h"
#include "config.h"
#include "ui/ui.h"
#include "raw_hid.h"
#include "qp_comms.h"
#include "qp_st77xx_opcodes.h"
#include "qp_st7735_opcodes.h"

uint16_t home_screen_timer = 0;

void start_home_screen_timer(void) {
    dprint("start_home_screen_timer\n");
    home_screen_timer = timer_read();
}

//----------------------------------------------------------
// Initialize Display 
bool display_init_kb(void){
    dprint("display_init_kb - start\n");
 
    // Initialise the LCD
    painter_device_t qp_display;
    qp_display = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    qp_init(qp_display, QP_ROTATION_180);

    // Invert color on the LCD
    qp_comms_start(qp_display);
    qp_comms_command(qp_display, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(qp_display);

    // Turn on the LCD and clear the display
    qp_rect(qp_display, 0, 0, LCD_WIDTH, LCD_HEIGHT, HSV_BLACK, true);
    
    dprint("display_init_kb - initialised\n");

    // Start LVGL
    qp_lvgl_attach(qp_display);

    return true;
}

//----------------------------------------------------------
// Display Raw HID data 
void display_process_raw_hid_data(uint8_t *data, uint8_t length){
    uint8_t data_type = data[0];
    //char string_data[length - 2];
    switch (data_type) {
       case _TIME:
            dprintf("time %02d:%02d\n", data[1], data[2]);
            lv_label_set_text_fmt(ui_label_time, "%02d:%02d", data[1], data[2]);
            break;
        case _VOLUME:
            dprintf("volume %d\n", data[1]);
            lv_label_set_text_fmt(ui_label_vol_home, "Vol: %02d%%", data[1]);
            //lv_label_set_text_fmt(label_volume_arc, "%02d", data[1]);
            //lv_arc_set_value(arc_volume, data[1]);
            //lv_scr_load(screen_volume);
            start_home_screen_timer();
            break;
        case _LAYOUT:
            dprintf("layout %d\n", data[1]);
            //set_layout_icon(data[1]);
            break;
    }
}


void display_housekeeping_task(void) {
    if (home_screen_timer && timer_elapsed(home_screen_timer) > 5000) {
        home_screen_timer = 0;
    }
}