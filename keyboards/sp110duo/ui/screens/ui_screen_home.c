// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_screen_home_screen_init(void)
{
    ui_screen_home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_screen_home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_screen_home, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_screen_home, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_screen_home, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_screen_home, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_panel_mods = lv_obj_create(ui_screen_home);
    lv_obj_set_width(ui_panel_mods, lv_pct(90));
    lv_obj_set_height(ui_panel_mods, lv_pct(25));
    lv_obj_set_x(ui_panel_mods, -46);
    lv_obj_set_y(ui_panel_mods, 21);
    lv_obj_set_align(ui_panel_mods, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_panel_mods, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_panel_mods, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_panel_mods, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_panel_mods, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panel_mods, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_panel_mods, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_panel_mods, 125, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_panel_mods, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_panel_mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_panel_mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_panel_mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_panel_mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_panel_mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_panel_mods, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_panel_mods, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_panel_mods, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_label_GUI = lv_label_create(ui_panel_mods);
    lv_obj_set_width(ui_label_GUI, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label_GUI, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_label_GUI, -81);
    lv_obj_set_y(ui_label_GUI, 13);
    lv_obj_set_align(ui_label_GUI, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label_GUI, "GUI");
    lv_obj_set_style_text_color(ui_label_GUI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_GUI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_label_GUI, lv_color_hex(0x00A5FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_label_GUI, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_label_GUI, lv_color_hex(0xFD2A2A), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_label_GUI, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_label_ALT = lv_label_create(ui_panel_mods);
    lv_obj_set_width(ui_label_ALT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label_ALT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_label_ALT, -37);
    lv_obj_set_y(ui_label_ALT, 93);
    lv_obj_set_align(ui_label_ALT, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_label_ALT, "ALT");

    ui_label_CTRL = lv_label_create(ui_panel_mods);
    lv_obj_set_width(ui_label_CTRL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label_CTRL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_label_CTRL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label_CTRL, "CTRL");

    ui_label_SHIFT = lv_label_create(ui_panel_mods);
    lv_obj_set_width(ui_label_SHIFT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label_SHIFT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_label_SHIFT, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label_SHIFT, "SHIFT");

    lv_obj_add_event_cb(ui_label_GUI, ui_event_label_GUI, LV_EVENT_ALL, NULL);

}
