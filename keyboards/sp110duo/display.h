// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "qp_lvgl.h"
#include "qp.h"

#define MODS_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define MODS_CTRL ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define MODS_ALT ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
#define MODS_GUI ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

bool display_init_kb(void);
void display_housekeeping_task(void);
void lvgl_event_triggers(void);