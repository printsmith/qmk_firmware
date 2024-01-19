// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "display.h"
#include "qp.h"
#include "config.h"
#include "sp110duo.h"
#include "ui/ui.h"

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
 
};