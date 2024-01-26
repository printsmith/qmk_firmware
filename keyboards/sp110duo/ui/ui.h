// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_screen_home
void ui_screen_home_screen_init(void);
extern lv_obj_t * ui_screen_home;
extern lv_obj_t * ui_label_time;
extern lv_obj_t * ui_label_vol_home;
extern lv_obj_t * ui____initial_actions0;




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
