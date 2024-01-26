// Copyright 2024 TylerK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#include <stdint.h>
#include_next <lv_conf.h>

/*====================
   COLOR SETTINGS
 *====================*/

/*Color depth: 1 (1 byte per pixel), 8 (RGB332), 16 (RGB565), 32 (ARGB8888)*/
#define LV_COLOR_DEPTH 16

/*Swap the 2 bytes of RGB565 color. Useful if the display has an 8-bit interface (e.g. SPI)*/
#define LV_COLOR_16_SWAP 1

/*Enable more complex drawing routines to manage screens transparency.
 *Can be used if the UI is above another layer, e.g. an OSD menu or video player.
 *Requires `LV_COLOR_DEPTH = 32` colors and the screen's `bg_opa` should be set to non LV_OPA_COVER value*/
#define LV_COLOR_SCREEN_TRANSP 0

/* Adjust color mix functions rounding. GPUs might calculate color mix (blending) differently.
 * 0: round down, 64: round up from x.75, 128: round up from half, 192: round up from x.25, 254: round up */
#define LV_COLOR_MIX_ROUND_OFS (LV_COLOR_DEPTH == 32 ? 0: 128)


/*====================
   FONT SETTINGS
 *====================*/

#undef LV_FONT_MONTSERRAT_32
#define LV_FONT_MONTSERRAT_32 1

#undef LV_FONT_MONTSERRAT_48
#define LV_FONT_MONTSERRAT_48 1