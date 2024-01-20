// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp_lvgl.h"
#include "quantum.h"

typedef enum {
    _QWERTY = 0,
    _FUNC,
} layer_number;

typedef enum {
    _TIME = 0xAA, // random value that does not conflict with VIA, must match companion app
    _VOLUME,
    _LAYOUT
} hid_data_type;

void display_init_kb(void);
void display_process_raw_hid_data(uint8_t *data, uint8_t length);
void display_process_layer_state(uint8_t layer);