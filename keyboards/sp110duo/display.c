// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "sp110duo.h"
#include "display.h"
#include "qp.h"
#include "config.h"
#include "ui/ui.h"
#include "raw_hid.h"
#include "qp_comms.h"
#include "print.h"
#include "qp_st77xx_opcodes.h"
#include "qp_st7735_opcodes.h"

painter_device_t lcd;

//----------------------------------------------------------
// Initialize Display 
//----------------------------------------------------------
bool display_init_kb(void){
    dprint("display_init_kb - start\n");
 
    // Initialise the LCD
    lcd = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    qp_init(lcd, QP_ROTATION_180);

    // Invert color on the LCD
    qp_comms_start(lcd);
    qp_comms_command(lcd, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(lcd);

    // Turn on the LCD and clear the display
    qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT, HSV_BLACK, true);
    dprint("display_init_kb - initialised\n");

    // Start LVGL
    qp_lvgl_attach(lcd);
    wait_ms(20);
    
    ui_init();

    return true;
}

//----------------------------------------------------------
// Display Housekeeping
//----------------------------------------------------------
void display_housekeeping_task(void) {
    
    lvgl_event_triggers();

}
    
//----------------------------------------------------------
// LVGL event triggers for UI 
//----------------------------------------------------------
void lvgl_event_triggers(void) {

    if MODS_ALT {
        _ui_state_modify(ui_label_ALT, LV_STATE_PRESSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_label_ALT, LV_STATE_PRESSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_CTRL {
        _ui_state_modify(ui_label_CTRL, LV_STATE_PRESSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_label_CTRL, LV_STATE_PRESSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_GUI {
        _ui_state_modify(ui_label_GUI, LV_STATE_PRESSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_label_GUI, LV_STATE_PRESSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_SHIFT {
        _ui_state_modify(ui_label_SHIFT, LV_STATE_PRESSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_label_SHIFT, LV_STATE_PRESSED, _UI_MODIFY_STATE_REMOVE);
    }

}

