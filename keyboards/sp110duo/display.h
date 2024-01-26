// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp_lvgl.h"
#include "quantum.h"

typedef enum {
    _QWERTY = 0,
    _FUNC,
} layer_number;

typedef enum {
    _TIME = 0, 
    _VOLUME,
    _LAYOUT
} hid_data_type;

bool display_init_kb(void);
void display_process_raw_hid_data(uint8_t *data, uint8_t length);
void display_process_layer_state(uint8_t layer);
void display_housekeeping_task(void);
