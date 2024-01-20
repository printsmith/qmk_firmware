// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"
#ifdef QUANTUM_PAINTER_ENABLE
extern painter_device_t qp_display;
#endif

#include "lv_conf.h"

#pragma pack(push)
#pragma pack(1)

enum sp110duo_keycodes {
    RGB_TOG1,
    LVGL_CLOCKWISE,
    LVGL_COUNTER_CLOCKWISE,
    LVGL_ENCODER_BUTTON
};

void rgb_matrix_increase_flags(void);