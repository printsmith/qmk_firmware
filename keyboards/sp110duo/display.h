// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "qp_lvgl.h"
<<<<<<< Updated upstream
=======
#include "quantum.h"
#ifdef QUANTUM_PAINTER_ENABLE
    #include <qp.h>
#endif

#pragma pack(push)
#pragma pack(1)

#ifdef QUANTUM_PAINTER_ENABLE
typedef struct kb_runtime_config {
    unsigned          lcd_power : 1;
    unsigned          lcd_timer : 1;
} kb_runtime_config;
#endif
>>>>>>> Stashed changes

#define MODS_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define MODS_CTRL ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define MODS_ALT ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
#define MODS_GUI ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

/* shared styles */
extern lv_style_t style_screen;
extern lv_style_t style_container;
extern lv_style_t style_button;
extern lv_style_t style_button_active;

<<<<<<< Updated upstream
bool display_init_kb(void);
bool display_init_user(void);
void display_housekeeping_task(void);
void display_process_caps(bool active);
=======
#define MODS_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define MODS_CTRL ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define MODS_ALT ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
#define MODS_GUI ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

void display_init_kb(void);
void display_process_layer_state(uint8_t layer);
void display_housekeeping_task(void);
//void display_process_caps(bool active);
//void toggle_state(void *obj, lv_state_t state, bool enabled);
>>>>>>> Stashed changes
