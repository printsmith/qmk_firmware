// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "sp110duo.h"
#include "display.h"
#include "qp.h"
#include "config.h"
#include "ui/ui.h"
#include "raw_hid.h"

painter_device_t qp_display;

// kb_runtime_config kb_state;
__attribute__((weak)) void draw_ui_user(void) {}

void display_init_kb(void){

    // Initialise the LCD
    qp_display = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    qp_init(qp_display, QP_ROTATION_180);
    //qp_set_viewport_offsets (qp_display, 25, 0);

    // Turn on the LCD and clear the display
    qp_rect(qp_display, 0, 0, LCD_WIDTH, LCD_HEIGHT, 150, 120, 100,true);
    //qp_rect(qp_display, 0, 0, 80, 160, 0, 0, 0, true);

    // Start LVGL
    qp_lvgl_attach(qp_display);
    wait_ms(50);
 
}
/*
void read_string(uint8_t *data, char *string_data) {
    uint8_t data_length = data[1];
    memcpy(string_data, data + 2, data_length);
    string_data[data_length] = '\0';
}
*/
// Process for sending data to display
void display_process_raw_hid_data(uint8_t *data, uint8_t length){
    uint8_t data_type = data[0];
    //char string_data[length - 2];
    switch (data_type) {
       case _TIME:
            dprintf("time %02d:%02d\n", data[1], data[2]);
            lv_label_set_text_fmt(ui_time, "%02d:%02d", data[1], data[2]);
            break;
        case _VOLUME:
            dprintf("volume %d\n", data[1]);
            lv_label_set_text_fmt(ui_volume, "Vol: %02d%%", data[1]);
            //lv_label_set_text_fmt(label_volume_arc, "%02d", data[1]);
            //lv_arc_set_value(arc_volume, data[1]);
            //lv_scr_load(screen_volume);
            //start_home_screen_timer();
            break;
        case _LAYOUT:
            dprintf("layout %d\n", data[1]);
            //set_layout_icon(data[1]);
            break;
    }
}

// Current layer state for display
void display_process_layer_state(uint8_t layer) {
    switch (layer) {
        case _QWERTY:
            //lv_label_set_text(label_layer, "QWERTY");
            break;
            //lv_label_set_text(label_layer, "FUNC");
            break;
    }
}
