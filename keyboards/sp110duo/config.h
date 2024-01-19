// Copyright 2023 Tyler (@Tyler)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Bootloeader defs for RP2040 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* SPI Configuration for display */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP14
#define SPI_MOSI_PIN GP11
#define SPI_MISO_PIN NO_PIN // We don't actually use MISO, so we set it to NO_PIN

/* LCD Configuration */
#ifdef QUANTUM_PAINTER_ENABLE

#define LCD_RST_PIN GP13
#define LCD_CS_PIN GP17
#define LCD_DC_PIN GP18
#define LCD_WIDTH 240
#define LCD_HEIGHT 320
#define LCD_SPI_DIVISOR 16 // tested with 8 as well
#define SPI_MODE 3

#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 30000

#endif // QUANTUM_PAINTER_ENABLE

#ifndef LCD_ACTIVITY_TIMEOUT
#    define LCD_ACTIVITY_TIMEOUT 30000
#endif // LCD_ACTIVITY_TIMEOUTk

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
//#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* RGB configuration */
#ifdef RGB_MATRIX_ENABLE

#define RGB_MATRIX_LED_COUNT    108		// Number of LEDs on board  
#define RGB_ENABLE_PIN GP28
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 70 
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10

#endif // RGB_MATRIX_ENABLE

/* Define lighting layers for using leds to display layers, caps lock, and other useful things */
//#define RGBLIGHT_LAYERS


